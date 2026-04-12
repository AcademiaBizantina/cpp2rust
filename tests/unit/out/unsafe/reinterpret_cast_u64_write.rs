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
    let mut val: u64 = 0_u64;
    let mut bytes: *mut u8 = ((&mut val as *mut u64) as *mut u8);
    (*bytes.offset((0) as isize)) = 1_u8;
    (*bytes.offset((1) as isize)) = 2_u8;
    (*bytes.offset((2) as isize)) = 3_u8;
    (*bytes.offset((3) as isize)) = 4_u8;
    (*bytes.offset((4) as isize)) = 5_u8;
    (*bytes.offset((5) as isize)) = 6_u8;
    (*bytes.offset((6) as isize)) = 7_u8;
    (*bytes.offset((7) as isize)) = 8_u8;
    (if ((val as u64) == (578437695752307201_u64)) {
    } else {
        std::panic::panic_any(
            ::std::ffi::CStr::from_ptr(b"val == 0x0807060504030201ULL\0".as_ptr() as *const i8)
                .to_str()
                .unwrap(),
        )
    });
    return 0;
}
