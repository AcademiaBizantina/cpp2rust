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
    let val: Value<u64> = Rc::new(RefCell::new(0_u64));
    let bytes: Value<Ptr<u8>> = Rc::new(RefCell::new((val.as_pointer()).reinterpret_cast::<u8>()));
    (*(*bytes.borrow()).offset((0) as isize).upgrade().deref_mut()) = 1_u8;
    (*(*bytes.borrow()).offset((1) as isize).upgrade().deref_mut()) = 2_u8;
    (*(*bytes.borrow()).offset((2) as isize).upgrade().deref_mut()) = 3_u8;
    (*(*bytes.borrow()).offset((3) as isize).upgrade().deref_mut()) = 4_u8;
    (*(*bytes.borrow()).offset((4) as isize).upgrade().deref_mut()) = 5_u8;
    (*(*bytes.borrow()).offset((5) as isize).upgrade().deref_mut()) = 6_u8;
    (*(*bytes.borrow()).offset((6) as isize).upgrade().deref_mut()) = 7_u8;
    (*(*bytes.borrow()).offset((7) as isize).upgrade().deref_mut()) = 8_u8;
    (if (((*val.borrow()) as u64) == 578437695752307201_u64) {
    } else {
        std::panic::panic_any(
            Ptr::from_string_literal("val == 0x0807060504030201ULL").to_rust_string(),
        )
    });
    return 0;
}
