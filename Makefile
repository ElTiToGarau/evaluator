OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o Problema.o Problemas.o Usuari.o
	g++ -o main.exe main.o Problema. Problemas.o Usuari.o Usuarios.o Sesiones.o Sesion.o Curso.o Cursos.o
	rm *.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

Cursos.o: Cursos.cc
	g++ -c Cursos.cc $(OPCIONS)

Curso.o: Curso.cc
	g++ -c Curso.cc $(OPCIONS)

Sesiones.o: Sesiones.cc
	g++ -c Sesiones.cc $(OPCIONS)

Sesion.o: Sesion.cc
	g++ -c Sesion.cc $(OPCIONS)

Usuarios.o: Usuarios.cc
	g++ -c Usuarios.cc $(OPCIONS)

Usuari.o: Usuari.cc
	g++ -c Usuari.cc $(OPCIONS)

Problemas.o: Problemas.cc
	g++ -c Problemas.cc $(OPCIONS)

Problema.o: Problema.cc
	g++ -c Problema.cc $(OPCIONS)

clean:
	rm *.o
