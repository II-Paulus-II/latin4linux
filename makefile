CC = g++

VH = src/headers/verbs.h
MH = src/headers/mainheader.h

all: latin

latin: obj/main.o obj/verbs.o
	${CC} $^ -o $@

obj/main.o: src/main.cpp ${MH} ${VH}
	${CC} -c -Wall src/main.cpp -o $@

obj/verbs.o: src/verbs.cpp ${VH}
	${CC} -c -Wall src/verbs.cpp -o $@
