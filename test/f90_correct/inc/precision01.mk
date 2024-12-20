#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#

########## Make rule for test precision01  ########


precision01: run
	

build:  $(SRC)/precision01.f08
	-$(RM) precision01.$(EXESUFFIX) core *.d *.mod FOR*.DAT FTN* ftn* fort.*
	@echo ------------------------------------ building test $@
	-$(CC) -c $(CFLAGS) $(SRC)/check.c -o check.$(OBJX)
	-$(FC) -c $(FFLAGS) $(LDFLAGS) $(SRC)/precision01.f08  -o precision01.$(OBJX)
	-$(FC) $(FFLAGS) $(LDFLAGS) precision01.$(OBJX) check.$(OBJX) $(LIBS) -o precision01.$(EXESUFFIX)


run:
	@echo ------------------------------------ executing test precision01
	precision01.$(EXESUFFIX)

verify: ;

precision01.run: run

