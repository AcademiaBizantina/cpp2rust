// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

unsafe fn f1(a0: u32) -> u32 {
    u32::from_be(a0)
}
unsafe fn f2(a0: u16) -> u16 {
    u16::from_be(a0)
}
