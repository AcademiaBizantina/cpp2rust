extern crate libcc2rs;
use libcc2rs::{prepostfix::*, rc::*};
use std::rc::{Rc, Weak};
use std::cell::RefCell;
pub fn main() {
    std::process::exit(*main_0().borrow() as i32);
}
pub fn main_0() -> Value<i32> {
    let x: Value<i32> = Rc::new(RefCell::new(1_i32));
    let p: Value<Pointer<i32>> = Rc::new(RefCell::new(x.as_pointer()));
    (*p.borrow()).delete();
    return Rc::new(RefCell::new(0_i32));
}
