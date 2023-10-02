CC = g++
LIB = -lncurses -lform

VH = src/headers/verbs.h
WH = src/headers/window.h
MH = src/headers/mainheader.h

all: latin

latin: obj/main.o obj/verbs.o obj/window.o
	${CC} $^ -o $@ ${LIB}

obj/main.o: src/main.cpp ${MH} ${WH} ${VH}
	${CC} -c -Wall src/main.cpp -o $@

obj/verbs.o: src/verbs.cpp ${VH}
	${CC} -c -Wall src/verbs.cpp -o $@

obj/window.o: src/window.cpp ${WH}
	${CC} -c -Wall src/window.cpp -o $@

clean: 
	rm -rf obj/*.o latin
