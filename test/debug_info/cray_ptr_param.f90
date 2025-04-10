! Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
! See https://llvm.org/LICENSE.txt for license information.
! SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

! REQUIRES: llvm-19
! RUN: %flang -gdwarf-4 -S -emit-llvm %s -o - | FileCheck %s

! CHECK-LABEL: define internal void @main_callee
! CHECK: #dbg_declare(ptr %callee_ptr, [[CALLEE_PTR:![0-9]+]]
! CHECK: [[CALLEE_PTR]] = !DILocalVariable(name: "callee_ptr"
! CHECK-SAME: arg: 1,

program main
  pointer (ptr, b)
  integer :: a(10), b(10)
  a = (/1,2,3,4,5,6,7,8,9,10/)
  call callee(ptr)
  print *, b 
  print *, a
  print *, ptr
contains
  subroutine callee(callee_ptr)
    pointer(callee_ptr, callee_pte)
    integer, allocatable :: callee_pte(:)
    allocate (callee_pte(10))
    callee_pte = (/5,4,5,4,5,4,5,4,5,4/)
    print *,callee_ptr
    print *,callee_pte
  end subroutine
end
