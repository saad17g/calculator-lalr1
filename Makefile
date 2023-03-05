CC = g++

TARGET = main

main: main.o automate.o lexer.o symbole.o etat.o
	$(CC) -o main main.o automate.o lexer.o symbole.o etat.o

automate.o: automate.cpp automate.h etat.h symbole.h
	$(CC) -c automate.cpp

lexer.o: lexer.cpp lexer.h symbole.h
	$(CC) -c lexer.cpp

main.o: main.cpp lexer.h
	$(CC) -c main.cpp

etat.o: etat.cpp etat.h automate.h
	$(CC) -c etat.cpp

symbole.o: symbole.cpp symbole.h
	$(CC) -c symbole.cpp

clean:
	rm *.o main