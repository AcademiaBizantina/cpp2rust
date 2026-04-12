extern crate libcc2rs;
use libcc2rs::{prepostfix::*, rc::*};
use std::rc::{Rc, Weak};
use std::cell::RefCell;
pub fn main() {
    std::process::exit(*main_0().borrow() as i32);
}
pub fn main_0() -> Value<i32> {
    let x: Value<i32> = Rc::new(RefCell::new(5_i32));
    let p: Value<Pointer<i32>> = Rc::new(RefCell::new(x.as_pointer()));
    return Rc::new(RefCell::new(
        (*(*p.borrow_mut())
            .prefix_inc()
            .as_reference()
            .upgrade()
            .expect("ub: dangling pointer")
            .borrow()),
    ));
}
