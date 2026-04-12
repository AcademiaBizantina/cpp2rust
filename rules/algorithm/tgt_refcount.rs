// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

use libcc2rs::*;
use std::cell::RefCell;
use std::io::Write;
use std::rc::Rc;

fn f1<T1: Ord>(a0: Ptr<T1>, a1: Ptr<T1>) {
    a0.sort(a1.get_offset())
}

fn f2<T1: Clone + PartialOrd + ByteRepr, T2: Clone + From<T1> + ByteRepr>(
    a0: Ptr<T1>,
    a1: Ptr<T1>,
    a2: Ptr<T2>,
) -> Ptr<T2> {
    let mut outptr = a2.clone();
    let mut curr = a0.clone();
    while curr < a1 {
        outptr.write((curr.read()).clone().into());
        curr += 1;
        outptr += 1;
    }
    outptr
}

fn f3<T1: PartialEq + Clone + ByteRepr>(a0: Ptr<T1>, a1: Ptr<T1>, a2: T1) -> Ptr<T1> {
    a0.offset(
        a0.clone()
            .into_iter()
            .enumerate()
            .position(|(index_0, value_0)| {
                index_0 < a1.get_offset() as usize && value_0.read() == a2
            })
            .unwrap_or(a1.get_offset() as usize) as isize,
    )
}

fn f6<T1: Ord + Clone, T2>(a0: Ptr<T1>, a1: Ptr<T1>, a2: T2)
where
    T2: FnMut(Ptr<T1>, Ptr<T1>) -> bool,
{
    a0.sort_with_cmp(a1.get_offset(), a2)
}

fn f7<T1: Ord + Clone, T2>(a0: Ptr<T1>, a1: Ptr<T1>, a2: T2)
where
    T2: FnMut(Ptr<T1>, Ptr<T1>) -> bool,
{
    a0.sort_with_cmp(a1.get_offset(), a2)
}

fn f8<T1: PartialOrd + Clone + ByteRepr>(a0: Ptr<T1>, a1: Ptr<T1>) -> Ptr<T1> {
    if a0 == a1 {
        a0.clone()
    } else {
        let mut __a0 = a0.clone();
        let mut max_it = a0.clone();
        __a0.postfix_inc();

        while __a0 != a1 {
            if max_it.read() < __a0.read() {
                max_it = __a0.clone();
            }
            __a0.postfix_inc();
        }
        max_it
    }
}

fn f9<T1: Clone + ByteRepr>(a0: Ptr<T1>, a1: Ptr<T1>) {
    let tmp = a0.read();
    a0.write(a1.read());
    a1.write(tmp);
}

fn f10<T1: PartialEq + Clone + ByteRepr>(a0: Ptr<T1>, a1: Ptr<T1>) -> Ptr<T1> {
    if a0 == a1 {
        a0.clone()
    } else {
        let mut write = a0.clone();
        let mut prev = a0.clone();
        let mut it = a0.clone();
        it.postfix_inc();

        while it != a1 {
            if prev.read() != it.read() {
                write.postfix_inc();
                let v = it.read().clone();
                write.write(v);
                prev = write.clone();
            }
            it.postfix_inc();
        }

        write.postfix_inc();
        write
    }
}

fn f12<T1: Clone + ByteRepr>(a0: Ptr<T1>, a1: Ptr<T1>, a2: T1) {
    let mut __a0 = a0.clone();
    while __a0 != a1 {
        let v = a2.clone();
        __a0.write(v);
        __a0.postfix_inc();
    }
}

// TODO: a2 should be passed as &mut
fn f13(a0: Ptr<u8>, a1: Ptr<u8>, a2: &mut ::std::fs::File) -> ::std::fs::File {
    a2.write_all(a0.slice_until(&a1).as_slice());
    a2.try_clone().unwrap()
}

fn f14<T1: Ord + Clone + ByteRepr, T2>(a0: Ptr<T1>, a1: Ptr<T1>, a2: T2)
where
    T2: Fn(T1, T1) -> bool,
{
    let fun = |x: Ptr<T1>, y: Ptr<T1>| a2((x.read()).clone(), (y.read()).clone());
    a0.sort_with_cmp(a1.get_offset(), fun)
}

fn f15<T1: Ord + Clone + ByteRepr, T2>(a0: Ptr<T1>, a1: Ptr<T1>, a2: T2)
where
    T2: Fn(T1, T1) -> bool,
{
    let fun = |x: Ptr<T1>, y: Ptr<T1>| a2((x.read()).clone(), (y.read()).clone());
    a0.sort_with_cmp(a1.get_offset(), fun)
}

fn f16<T1: PartialOrd + Clone + ByteRepr>(a0: Ptr<T1>, a1: Ptr<T1>) -> Ptr<T1> {
    if a0.read() <= a1.read() { a0 } else { a1 }
}

fn f17<T1: PartialOrd + Clone + ByteRepr>(a0: Ptr<T1>, a1: Ptr<T1>) -> Ptr<T1> {
    if a0.read() >= a1.read() { a0 } else { a1 }
}
