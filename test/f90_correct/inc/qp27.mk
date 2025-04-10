#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#

########## Make rule for test qp27  ########


qp27: run


build:  $(SRC)/qp27.f08
	-$(RM) qp27.$(EXESUFFIX) core *.d *.mod FOR*.DAT FTN* ftn* fort.*
	@echo ------------------------------------ building test $@
	-$(CC) -c $(CFLAGS) $(SRC)/check.c -o check.$(OBJX)
	-$(FC) -c $(FFLAGS) $(LDFLAGS) $(SRC)/qp27.f08 -o qp27.$(OBJX)
	-$(FC) $(FFLAGS) $(LDFLAGS) qp27.$(OBJX) check.$(OBJX) $(LIBS) -o qp27.$(EXESUFFIX)


run:
	@echo ------------------------------------ executing test qp27
	qp27.$(EXESUFFIX)

verify: ;
