##############################################################################
# Program Name                                                               #
##############################################################################
BINARY=latin

##############################################################################
# Compiler Flags, Optimisation and Libraries                                 #
##############################################################################
CC=g++
LIB=-lncursesw -lformw
OPT=-O0
DEPFLAGS=-MT $@ -MMD -MP -MF $(DEPDIR)/$*.d
FLAGS=-c -g -Wall -Wextra -std=c++17 ${OPT} ${DEPFLAGS}

##############################################################################
# Folders                                                                    #
##############################################################################
SRCDIR=src
OBJDIR=.obj
DEPDIR=.dep
INCDIR=include

##############################################################################
# Files                                                                      #
##############################################################################
SRCEXT=cpp
OBJEXT=o
DEPEXT=d
PCH=${INCDIR}/precompiled.h
INC=-include ${PCH}
PCHOBJ=${INCDIR}/precompiled.h.gch
SOURCES = ${wildcard ${SRCDIR}/*.cpp}
OBJECTS = ${patsubst ${SRCDIR}/%,${OBJDIR}/%, $(SOURCES:.${SRCEXT}=.${OBJEXT})}
DEPFILES = ${patsubst ${SRCDIR}/%,${DEPDIR}/%, $(SOURCES:.${SRCEXT}=.${DEPEXT})}

all: ${BINARY}

${BINARY}: ${OBJECTS}
	${CC} -o $@ $^ ${LIB}

${OBJDIR}/%.${OBJEXT}: ${SRCDIR}/%.${SRCEXT} ${PCHOBJ}
	${CC} -H ${FLAGS} ${INC} -o $@ $<

${PCHOBJ}:${PCH}
	${CC} $^ ${FLAGS}

clean: 
	rm -rf ${OBJECTS} ${BINARY} ${DEPFILES} ${PCHOBJ}

run: ${BINARY}
	./${BINARY}

-include ${DEPFILES}

.PHONY: all clean run
