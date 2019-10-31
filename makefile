enigma: main.o enigma.o
	g++ main.o enigma.o -o enigma 

main.o: main.cpp enigma.h
	g++ -Wall -g -c main.cpp

engima.o:enigma.cpp enigma.h
	g++ -Wall -g -c enigma.cpp
