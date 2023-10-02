CC = g++

all: latin

latin: src/main.cpp
	${CC} src/main.cpp -o $@
