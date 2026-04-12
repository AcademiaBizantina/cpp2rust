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
    let arr: Value<Box<[u32]>> = Rc::new(RefCell::new(Box::new([67305985_u32, 134678021_u32])));
    let base: Value<Ptr<u8>> = Rc::new(RefCell::new(
        (arr.as_pointer() as Ptr<u32>).reinterpret_cast::<u8>(),
    ));
    let p: Value<Ptr<u8>> = Rc::new(RefCell::new((*base.borrow()).offset((3) as isize)));
    (if ((((*p.borrow()).deref()) as i32) == 4) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("*p == 0x04").to_rust_string())
    });
    let __rhs = (*p.borrow()).offset((2) as isize);
    (*p.borrow_mut()) = __rhs;
    (if ((((*p.borrow()).deref()) as i32) == 6) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("*p == 0x06").to_rust_string())
    });
    let __rhs = (*p.borrow()).offset(-((1) as isize));
    (*p.borrow_mut()) = __rhs;
    (if ((((*p.borrow()).deref()) as i32) == 5) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("*p == 0x05").to_rust_string())
    });
    let __rhs = (*p.borrow()).offset(-((4) as isize));
    (*p.borrow_mut()) = __rhs;
    (if ((((*p.borrow()).deref()) as i32) == 1) {
    } else {
        std::panic::panic_any(Ptr::from_string_literal("*p == 0x01").to_rust_string())
    });
    return 0;
}
