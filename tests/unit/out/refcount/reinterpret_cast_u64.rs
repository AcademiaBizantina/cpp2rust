extern crate libcc2rs;
use libcc2rs::*;
use std::cell::RefCell;
use std::io::Seek;
use std::io::{Read, Write};
use std::os::fd::AsFd;
use std::os::fd::AsRawFd;
use std::os::fd::FromRawFd;
use std::rc::{Rc, Weak};
pub fn main() {
    std::process::exit(main_0());
}
fn main_0() -> i32 {
    let val: Value<u64> = Rc::new(RefCell::new(578437695752307201_u64));
    let bytes: Value<Ptr<u8>> = Rc::new(RefCell::new((val.as_pointer()).reinterpret_cast::<u8>()));
    (if ((((*bytes.borrow()).offset((0) as isize).deref()) as i32) == 1) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[0] == 0x01").to_rust_string())
    });
    (if ((((*bytes.borrow()).offset((1) as isize).deref()) as i32) == 2) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[1] == 0x02").to_rust_string())
    });
    (if ((((*bytes.borrow()).offset((2) as isize).deref()) as i32) == 3) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[2] == 0x03").to_rust_string())
    });
    (if ((((*bytes.borrow()).offset((3) as isize).deref()) as i32) == 4) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[3] == 0x04").to_rust_string())
    });
    (if ((((*bytes.borrow()).offset((4) as isize).deref()) as i32) == 5) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[4] == 0x05").to_rust_string())
    });
    (if ((((*bytes.borrow()).offset((5) as isize).deref()) as i32) == 6) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[5] == 0x06").to_rust_string())
    });
    (if ((((*bytes.borrow()).offset((6) as isize).deref()) as i32) == 7) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[6] == 0x07").to_rust_string())
    });
    (if ((((*bytes.borrow()).offset((7) as isize).deref()) as i32) == 8) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[7] == 0x08").to_rust_string())
    });
    return 0;
}
