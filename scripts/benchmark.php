<?php

define('ONLY_COMPILE', @$argv[1] == '--only-compile');
define('ONLY_RUN', @$argv[1] == '--only-run');

@mkdir('tmp');

foreach (glob('../tests/benchmarks/*.cc') as $file) {
  echo "Running $file\n";
  $name = basename($file, '.cc');
  compile_cpp($file, "tmp/$name.cc");
  $stats[$name]['cpp'] = benchmark("tmp/$name.cc");
  foreach (['unsafe', 'refcount'] as $type) {
    $bin = "tmp/$name.rs.$type";
    compile_rust("../tests/benchmarks/out/$type/$name.rs", $bin);
    $stats[$name][$type] = benchmark($bin);
  }
}

echo "Benchmark";
$cols = array_keys(reset($stats));
foreach ($cols as $type) {
  echo "\t$type";
}
echo "\n";

foreach ($stats as $bench => $data) {
  echo $bench;
  foreach ($cols as $type) {
    echo "\t", $data[$type];
  }
  echo "\n";
}


function compile_cpp($file, $output) {
  if (ONLY_RUN)
    return;
  `clang++ -O3 $file -o $output`;
}

function compile_rust($file, $output) {
  if (ONLY_RUN)
    return;

  @mkdir('tmp/rust/src', 0777, true);
  file_put_contents('tmp/rust/Cargo.toml', <<<EOF
[package]
name = "test"
version = "0.1.0"
edition = "2021"

[dependencies]
libc = "0.2.169"
libcc2rs = { path = "../../../libcc2rs" }
EOF);
  copy($file, 'tmp/rust/src/main.rs');

  chdir('tmp/rust');
  putenv('RUSTFLAGS=-Awarnings');
  `cargo build --release --quiet`;
  chdir('../..');

  `mv tmp/rust/target/release/test $output`;
  `rm -fr tmp/rust`;
}

function benchmark($bin) {
  if (ONLY_COMPILE)
    return [];

  $times = [];
  for ($i = 0; $i < 15; ++$i) {
    $out = `/usr/bin/time ./$bin 2>&1`;
    preg_match('/(\d+):([0-9.]+)elapsed/', $out, $m);
    $times[] = (float)$m[1] * 60 + (float)$m[2];
  }
  sort($times);
  array_shift($times);
  array_pop($times);
  return number_format(array_sum($times) / count($times), 3);
}
