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
    let val: Value<u32> = Rc::new(RefCell::new(67305985_u32));
    let bytes: Value<Ptr<u8>> = Rc::new(RefCell::new((val.as_pointer()).reinterpret_cast::<u8>()));
    (if ((((*bytes.borrow()).offset((0) as isize).deref()) as i32) == 1) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[0] == 0x01").to_rust_string())
    });
    (if ((((*bytes.borrow()).offset((1) as isize).deref()) as i32) == 2) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("bytes[1] == 0x02").to_rust_string())
    });
    (*(*bytes.borrow()).offset((1) as isize).upgrade().deref_mut()) = 255_u8;
    (if ((*val.borrow()) == 67370753_u32) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("val == 0x0403FF01").to_rust_string())
    });
    (*(*bytes.borrow()).offset((3) as isize).upgrade().deref_mut()) = 170_u8;
    (if ((*val.borrow()) == 2852388609_u32) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("val == 0xAA03FF01").to_rust_string())
    });
    return 0;
}
