extern crate libc;
use libc::*;
extern crate libcc2rs;
use libcc2rs::*;
use std::io::Seek;
use std::io::{Read, Write};
use std::os::fd::AsFd;
use std::os::fd::AsRawFd;
use std::os::fd::FromRawFd;
use std::rc::Rc;
pub fn main() {
    unsafe {
        std::process::exit(main_0() as i32);
    }
}
unsafe fn main_0() -> i32 {
    let mut val: u64 = 578437695752307201_u64;
    let mut bytes: *mut u8 = ((&mut val as *mut u64) as *mut u8);
    (if (((*bytes.offset((0) as isize)) as i32) == (1)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"bytes[0] == 0x01\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    (if (((*bytes.offset((1) as isize)) as i32) == (2)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"bytes[1] == 0x02\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    (if (((*bytes.offset((2) as isize)) as i32) == (3)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"bytes[2] == 0x03\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    (if (((*bytes.offset((3) as isize)) as i32) == (4)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"bytes[3] == 0x04\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    (if (((*bytes.offset((4) as isize)) as i32) == (5)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"bytes[4] == 0x05\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    (if (((*bytes.offset((5) as isize)) as i32) == (6)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"bytes[5] == 0x06\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    (if (((*bytes.offset((6) as isize)) as i32) == (7)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"bytes[6] == 0x07\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    (if (((*bytes.offset((7) as isize)) as i32) == (8)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"bytes[7] == 0x08\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    return 0;
}
