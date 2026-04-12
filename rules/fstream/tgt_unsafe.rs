// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

fn types() -> Result<(), Box<dyn std::error::Error>> {
    let t1: ::std::fs::File = ::std::fs::File::open("")?;
    let t2: ::std::fs::File = ::std::fs::File::open("")?;
    let t3: ::std::fs::File = ::std::fs::File::open("")?;
    Ok(())
}

unsafe fn f1(a0: *const u8) -> ::std::fs::File {
    ::std::fs::File::create(
        ::std::ffi::CStr::from_ptr(a0 as *const i8)
            .to_str()
            .unwrap(),
    )
    .unwrap()
}

unsafe fn f2(a0: ::std::fs::File) -> ::std::fs::File {
    a0.try_clone().unwrap()
}
unsafe fn f3(a0: &mut ::std::fs::File) -> &mut ::std::fs::File {
    a0
}
unsafe fn f4(a0: ::std::fs::File) -> ::std::fs::File {
    a0
}
unsafe fn f5(a0: *const u8) -> ::std::fs::File {
    ::std::fs::File::open(
        ::std::ffi::CStr::from_ptr(a0 as *const i8)
            .to_str()
            .unwrap(),
    )
    .unwrap()
}

unsafe fn f6(a0: ::std::fs::File) -> ::std::fs::File {
    a0.try_clone().unwrap()
}

unsafe fn f7(a0: ::std::fs::File) -> ::std::fs::File {
    a0.try_clone().unwrap()
}

unsafe fn f8(a0: ::std::fs::File) -> ::std::fs::File {
    a0
}
