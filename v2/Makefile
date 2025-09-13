# Pending binaries
# formatVhdlFiles.py
# ghdlSanitize.sh

# Pending libs (not sure if to be built)
# FLI Fli ModelsimFLI

# ILIBS are .a, not to be installed, consumed for build (to be confirmed)
# .so exist, but have to confirm whether they are to be installed

# Dependencies: boost, antlr2, llvm (once llvm2aa is merged)

ifeq ($(OS),NetBSD)
PREFIX	?=	/usr/pkg
else
PREFIX	?=	/usr/local
endif

INSTALL	?=	install

BINDIR	?=	$(PREFIX)/bin
LIBDIR	?=	$(PREFIX)/lib

CFLAGS	+=  -I$(PREFIX)/include -MMD -MP -fPIC
CXXFLAGS+=	$(CFLAGS) --std=c++17
ANTLR	=	antlr
AR		=	ar
ARFLAGS	=	rcs
LDFLAGS	+=	-L$(PREFIX)/lib -lantlr -lboost_filesystem -Wl,-rpath,$(PREFIX)/lib
SOFLAGS	+=	-shared

# LLVM2AA will be built from a separate git repo. Eventually it will be merged back here.
PROJECTS	=	AHIRASM HIERSYS LIBAHIR BITVECS VALUE FNLIB IOLIB VERSION #LLVM2AA
PROJECTS	+=	PIPEHANDLER RTL2AAMATCHER CTESTBENCH
PROJECTS	+=	BGLWRAP PTHREADUTILS

AHIRASM_DIR	=	Ahir-asm/devel
AHIRASM_BINS=	Aa2C Aa2VC AaLinkExtMem AaOpt AaPreprocess
AHIRASM_ILIBS=	Aa
AHIRASM_GRAM=	Aa

HIERSYS_DIR	=	HierSysBuild
HIERSYS_BINS=	hierSys2C hierSys2Vhdl hierSysCheck hierSysGenVhdlComponentsPackage hierSysPartition hierSysUniquify
HIERSYS_ILIBS=	HierSys
HIERSYS_GRAM=	hierSys

LIBAHIR_DIR	=	libAhirV2
LIBAHIR_BINS=	vc2vhdl vcAnalyze vcFormat vcParse vhdlFormat
LIBAHIR_ILIBS=	VC
LIBAHIR_GRAM=	vc
vcParse_SRCS=	$(LIBAHIR_DIR)/util/vcParseMain.cpp

#LLVM2AA_DIR	=	llvmbc2Aa
#LLVM2AA_BINS=	llvm2aa
#llvm2aa_SRCS=	$(wildcard $(LLVM2AA_DIR)/src/*.cpp)

BITVECS_DIR	=	BitVectors
BITVECS_ILIBS=	BitVectors

VALUE_DIR	=	Value
VALUE_ILIBS	=	Value

FNLIB_DIR	=	functionLibrary
FNLIB_ILIBS	=	fpu llvm_intrinsics timer

IOLIB_DIR	=	iolib
IOLIB_ILIBS	=	io

VERSION_DIR	=	version
VERSION_ILIBS=	AhirVersion

CTESTBENCH_DIR				=	CtestBench
CTESTBENCH_LIBS				=	SockPipes SocketLibPipeHandler Vhpi
SockPipes_SRCS				=	$(addprefix $(CTESTBENCH_DIR)/src/, $(addsuffix .c, SocketLib SockPipes))
SocketLibPipeHandler_SRCS	=	$(addprefix $(CTESTBENCH_DIR)/src/, $(addsuffix .c, SocketLib Pipes SockPipes pipeHandler))
Vhpi_SRCS					=	$(addprefix $(CTESTBENCH_DIR)/src/, $(addsuffix .c, Vhpi SocketLib))

PIPEHANDLER_DIR	=	pipeHandler
PIPEHANDLER_LIBS=	PipeHandler

RTL2AAMATCHER_DIR	=	rtl2AaMatcher
RTL2AAMATCHER_LIBS	=	Rtl2AaMatcher

BGLWRAP_DIR	=	BGLWrap

PTHREADUTILS_DIR=	pthreadUtils


# # # # # Usually no change should be required below this point # # # # #

# Convention:
# For BINS, binary name has a corresponding utils/<bin>.cpp program, unless <BIN>_SRCS is defined
# If a project has a single LIB, build from src/*.cpp
# If a project has multiple ILIBS, for each source there is corresponding src/<lib>.c
# If a project has no ILIBS, use all sources for the BIN
# We use all include directories for compilation and all libs for linking, to keep it simple


BINS	=	$(foreach p,$(PROJECTS), $(addprefix $($(p)_DIR)/bin/, $($(p)_BINS)))
LIBS	=	$(foreach p,$(PROJECTS), $(addsuffix .so,$(addprefix $($(p)_DIR)/lib/lib, $($(p)_LIBS))))
ILIBS	=	$(foreach p,$(PROJECTS), $(addsuffix .a,$(addprefix $($(p)_DIR)/lib/lib, $($(p)_ILIBS))))
INCDIRS	+=	$(foreach p,$(PROJECTS), $($(p)_DIR)/include)
INCDIRS	+=	$(foreach p,$(PROJECTS),$(foreach g,$($(p)_GRAM),$($(p)_DIR)/src))
CFLAGS	+=	$(addprefix -I,$(INCDIRS))


%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

define f_ANTLROPS
$(addprefix $($(1)_DIR)/src/, $(foreach g,$($(1)_GRAM), $(foreach suf,Lexer Parser, $(foreach ext,.hpp .cpp, $(g)$(suf)$(ext)))))
endef

define f_ANTLRINP
$(foreach g,$($(1)_GRAM),$($(1)_DIR)/grammar/$(g).g)
endef

define f_ILIBSRCS
$(if $(filter-out 1,$(words $($(1)_ILIBS))),\
	$($(1)_DIR)/src/$(2).c,\
	$(sort $(wildcard $($(1)_DIR)/src/*.cpp) $(filter %.cpp,$(call f_ANTLROPS,$(1)))))
endef

define f_LIBSRCS
$(if $($(2)_SRCS),\
	$($(2)_SRCS),\
	$(wildcard $($(1)_DIR)/src/*.c))
endef

define f_BINSRCS
$(if $($(2)_SRCS),\
	$($(2)_SRCS),\
	$($(1)_DIR)/util/$(2).cpp)
endef

define f_SRC2O
$(subst .c,.o,$(subst .cpp,.o,$(1)))
endef

define ILIBRULES
$($(1)_DIR)/lib/lib$(2).a: $(call f_SRC2O, $(call f_ILIBSRCS,$(1),$(2)))
	mkdir -p $($(1)_DIR)/lib && \
	$(AR) $(ARFLAGS) $($(1)_DIR)/lib/lib$(2).a $(call f_SRC2O, $(call f_ILIBSRCS,$(1),$(2)))

endef

define LIBRULES
$($(1)_DIR)/lib/lib$(2).so: $(call f_SRC2O, $(call f_LIBSRCS,$(1),$(2)))
	mkdir -p $($(1)_DIR)/lib && \
	$(CXX) $(SOFLAGS) $(LDFLAGS) $(call f_SRC2O, $(call f_LIBSRCS,$(1),$(2))) -o $($(1)_DIR)/lib/lib$(2).so

endef

define BINRULES
$($(1)_DIR)/bin/$(2): $(call f_SRC2O, $(call f_BINSRCS,$(1),$(2))) $(ILIBS)
	mkdir -p $($(1)_DIR)/bin && \
	$(CXX) $(call f_SRC2O, $(call f_BINSRCS,$(1),$(2))) $(ILIBS) $(LDFLAGS) -o $($(1)_DIR)/bin/$(2)

endef

define PROJRULES

$(call f_ANTLROPS,$(1)) &: $(call f_ANTLRINP,$(1))
	$(ANTLR) -o $($(1)_DIR)/src $(call f_ANTLRINP,$(1))

$(foreach l,$($(1)_ILIBS),$(call ILIBRULES,$(1),$(l)))

$(foreach l,$($(1)_LIBS),$(call LIBRULES,$(1),$(l)))

$(foreach b,$($(1)_BINS),$(call BINRULES,$(1),$(b)))

endef

define GENSRCDEPRULE
$(1)	:	$(GENSRCS)

endef


all: $(BINS) $(LIBS)


GENSRCS=	$(foreach p,$(PROJECTS),$(call f_ANTLROPS,$(p)))
BINOBJS=	$(foreach p,$(PROJECTS),$(foreach b,$($(p)_BINS),$(call f_SRC2O,$(call f_BINSRCS,$(p),$(b)))))
ILIBOBJS=	$(foreach p,$(PROJECTS),$(foreach l,$($(p)_ILIBS),$(call f_SRC2O,$(call f_ILIBSRCS,$(p),$(l)))))
LIBOBJS=	$(foreach p,$(PROJECTS),$(foreach l,$($(p)_LIBS),$(call f_SRC2O,$(call f_LIBSRCS,$(p),$(l)))))
OBJS=		$(BINOBJS) $(ILIBOBJS) $(LIBOBJS)
DFILES=		$(OBJS:.o=.d)
-include $(DFILES)

install: all
	$(INSTALL) -d -m 755 $(DESTDIR)$(BINDIR) $(DESTDIR)$(LIBDIR)
	$(INSTALL) -m 755 $(BINS) $(DESTDIR)$(BINDIR)
	$(INSTALL) -m 644 $(LIBS) $(DESTDIR)$(LIBDIR)

clean: clean-bins clean-libs clean-objs clean-gensrcs

clean-bins:
	rm -f $(BINS)
clean-libs:
	rm -f $(ILIBS) $(LIBS)
clean-gensrcs:
	rm -f $(GENSRCS)
clean-objs:
	rm -f $(OBJS) $(DFILES)

$(foreach p, $(PROJECTS), $(eval $(call PROJRULES,$(p))))

$(foreach o, $(OBJS), $(eval $(call GENSRCDEPRULE,$(o))))

