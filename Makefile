# 
#  Copyright (c) 2016 Lénárd Szolnoki
# 
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, see <http://www.gnu.org/licenses/>.
# 

# CONFIG

CC := gcc

SRCDIR ?= src
BUILDDIR ?= build
DEPDIR ?= dep
BINDIR ?= bin
TESTSDIR ?= tests
SRCEXT ?= c
CFLAGS += -g -O2 -march=haswell
INCLUDE += -I include

# /CONFIG

TARGET_SOURCES := ${wildcard ${SRCDIR}/target/*.${SRCEXT}}
TARGET_ELFS := ${patsubst ${SRCDIR}/target/%.${SRCEXT},bin/%.elf,${TARGET_SOURCES}}

TEST_SOURCES := ${wildcard ${SRCDIR}/tests/*.${SRCEXT}}
TEST_ELFS := ${patsubst ${SRCDIR}/tests/%.${SRCEXT},tests/%.elf,${TEST_SOURCES}}

LIB_SOURCES := ${wildcard ${SRCDIR}/*.${SRCEXT}}
SOURCES := ${TARGET_SOURCES} ${TEST_SOURCES} ${LIB_SOURCES}
OBJECTS := ${patsubst ${SRCDIR}/%.${SRCEXT},${BUILDDIR}/%.o,${SOURCES}}
LIB_OBJECTS := ${patsubst ${SRCDIR}/%.${SRCEXT},${BUILDDIR}/%.o,${LIB_SOURCES}}
DEPENDS := ${patsubst ${SRCDIR}/%.${SRCEXT},${DEPDIR}/%.d,${SOURCES}}

target: ${TARGET_ELFS}
	
tests: ${TEST_ELFS}
	
all: target tests
	
include ${DEPENDS}

${DEPDIR}/%.d: ${SRCDIR}/%.${SRCEXT}
	@mkdir -p ${shell dirname $@} ; \
	echo -n "`dirname '${patsubst ${SRCDIR}/%.${SRCEXT},${BUILDDIR}/%.o,$<}'`/" > $@; \
	$(CC) -MM ${INCLUDE} $< >> $@
${BINDIR}/%.elf : ${BUILDDIR}/target/%.o ${LIB_OBJECTS}
	$(CC) $^ -o $@ ${CFLAGS} ${LDFLAGS}
${TESTSDIR}/%.elf : ${BUILDDIR}/tests/%.o ${LIB_OBJECTS}
	$(CC) $^ -o $@ ${CFLAGS} ${LDFLAGS}
${BUILDDIR}/%.o: ${SRCDIR}/%.${SRCEXT}
	@mkdir -p `dirname $@` ;\
	echo '$(CC) -c ${INCLUDE} ${CFLAGS} $< -o $@' ;\
	      $(CC) -c ${INCLUDE} ${CFLAGS} $< -o $@
dirs:
	mkdir -p ${SRCDIR} ${BUILDDIR} ${DEPDIR} ${BINDIR} ${TESTSDIR} ${SRCDIR}/target ${SRCDIR}/tests

clean:
	rm -rf ${BUILDDIR}/*	\
	       ${BINDIR}/*	\
	       ${TESTSDIR}/*    \
	       $(DEPDIR)/*;

.PHONY: target tests all dirs clean
	
.SECONDARY: ${OBJECTS}
	
