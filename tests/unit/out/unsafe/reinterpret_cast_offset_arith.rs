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
    let mut arr: [u32; 2] = [67305985_u32, 134678021_u32];
    let mut base: *mut u8 = (arr.as_mut_ptr() as *mut u8);
    let mut p: *mut u8 = base.offset((3) as isize);
    (if (((*p) as i32) == (4)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"*p == 0x04\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    p = p.offset((2) as isize);
    (if (((*p) as i32) == (6)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"*p == 0x06\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    p = p.offset(-((1) as isize));
    (if (((*p) as i32) == (5)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"*p == 0x05\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    p = p.offset(-((4) as isize));
    (if (((*p) as i32) == (1)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"*p == 0x01\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    return 0;
}
