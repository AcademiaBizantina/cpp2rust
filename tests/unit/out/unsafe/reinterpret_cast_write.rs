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
    let mut val: u32 = 67305985_u32;
    let mut bytes: *mut u8 = ((&mut val as *mut u32) as *mut u8);
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
    (*bytes.offset((1) as isize)) = 255_u8;
    (if ((val) == (67370753_u32)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"val == 0x0403FF01\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    (*bytes.offset((3) as isize)) = 170_u8;
    (if ((val) == (2852388609_u32)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"val == 0xAA03FF01\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    return 0;
}
