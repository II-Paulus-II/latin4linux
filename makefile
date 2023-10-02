CC = g++

all: latin

latin: obj/main.o obj/verbs.o
	${CC} $^ -o $@

obj/main.o: src/main.cpp
	${CC} -c -Wall src/main.cpp -o $@

obj/verbs.o: src/verbs.cpp
	${CC} -c -Wall src/verbs.cpp -o $@
