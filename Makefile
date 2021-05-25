OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Problema.o Problemas.o Sesiones.o Sesion.o Curso.o Cursos.o Usuari.o Usuarios.o
	g++ -o program.exe program.o Problema.o Problemas.o Usuari.o Usuarios.o Sesiones.o Sesion.o Curso.o Cursos.o
	rm *.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

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
	rm *.exe
	rm *.o
	rm *.tar

html:
	doxygen Doxyfile

tar: html
	zip -r html.zip html
	zip jp_gerard.oliva.vinas.zip jp_gerard.oliva.vinas.txt jp_nico.rivera.txt jp_noa.yu.ventura.txt
	tar -cvf practica.tar *.cc Makefile Curso.hh Cursos.hh Problema.hh Problemas.hh Sesion.hh Sesiones.hh Usuari.hh Usuarios.hh html.zip jp_gerard.oliva.vinas.zip
	rm *.zip
