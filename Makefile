OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.o: main.cc Problema.o Problemas.o
	g++ -c main.cc $(OPCIONS)

Problemas.o: Problemas.cc
	g++ -c Problemas.cc $(OPCIONS)

Problema.o: Problema.cc
	g++ -c Problema.cc $(OPCIONS)

clean:
	rm *.o
