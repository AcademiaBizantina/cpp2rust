// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

use libcc2rs::*;

struct T1;

fn types() {
    let t1: Box<[Value<Box<[T1]>>]> = Box::new([Default::default()]);
    let t2: Box<[Value<Box<[Value<Box<[T1]>>]>>]> = Box::new([Default::default()]);
}
