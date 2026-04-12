// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

use libcc2rs::*;
use std::cell::RefCell;
use std::rc::Rc;

fn f1<T1>(a0: Ptr<T1>) -> Ptr<T1> {
    a0.to_last()
}

fn f2<T1>(a0: Ptr<T1>) -> Ptr<T1> {
    a0
}

fn f7<T1: ByteRepr>(a0: Ptr<Vec<Value<Vec<T1>>>>, a1: Value<Vec<T1>>) {
    a0.with_mut(|__v: &mut Vec<Value<Vec<T1>>>| __v.push(a1))
}
