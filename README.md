# EVALUATOR: plataforma de gestió de problemes i cursos de programació

## Pràctica de l'assignatura de PRO2 de la FIB.

Los  comandos  aceptados  se  describen  a  continuación.  Todo  ellos  se  presentan  en dos versiones, una con el nombre completo y otra con el nombre abreviado. La sintaxisexacta de la entrada y la salida de cada comando se podrá derivar del juego de pruebaspúblico del ejercicio creado en el Jutge para cada entrega.

1. `nuevo_problema p`: añade un problema nuevo con identificadorp. El comandoadmite la forma abreviada `np p`. Si ya existía un problema en la plataforma con elmismo identificador se imprime un mensaje de error. En caso contrario se imprimeel número de problemas P en la colección después de añadirlo.
2. `nueva_sesion s`: añade una sesión nueva con identificadors. El comando admite la forma abreviada `ns s`. Primero se debe leer la estructura de problemas de lasesión, de la misma manera que se hizo en las sesiones iniciales (se garantiza quelos problemas existen y no están repetidos). Si ya existía una sesión en la plataforma con el mismo identificador se imprime un mensaje de error. En caso contrariose imprime el número de sesiones Q en el repositorio después de añadirla.
3. `nuevo_curso`: añade un nuevo curso con identificador N+1 en caso de que cumpla la restricción de no repetición de problemas en el mismo curso. El comando admite la forma abreviada `nc`. Primero se lee un número de sesiones S<sub>N+1</sub>>0 y luego una secuencia de S<sub>N+1</sub> identificadores válidos de sesiones. Si no hay intersección de problemas entre las sesiones, se añade el curso al conjunto de cursos yse imprime su identificador. En caso contrario, no se añade al conjunto (por lo queNno varía) y se imprime un mensaje de error.
4. `alta_usuario u`: registra un usuario nuevo con identificadoru. El comando admite la forma abreviada `a u`. Si ya existía un usuario en la plataforma con el mismo identificador se imprime un mensaje de error. En caso contrario se imprime el número de usuarios registrados M después de añadirlo.
5. `baja_usuario u`: da de baja un usuario con identificadoru. El comando admitela forma abreviada `b u`. Si no existe un usuario en la plataforma con identificadoruse  imprime  un  mensaje  de  error.  En  caso  contrario  se  imprime  el  número  deusuarios registrados M después de borrarlo. Si más tarde se da de alta otro usuario con el mismo nombre es como si el anterior no hubiera existido.
6. `inscribir_curso u c`: inscribe un usuario *u* en el curso con identificador *c*. El comando admite la forma abreviada `i u c`. Si el usuario *u* no existe en la plataforma o ya está inscrito en otro curso que no ha sido completado, o si el curso c no existe, se imprime un mensaje de error. En caso contrario se imprime el número de usuarios inscritos en el cursoc después de añadirlo.
7. `curso_usuario u`: consulta el curso en el que está inscrito un usuario *u*. El comando admite la forma abreviada `cu u`. Si el usuario *u* no existe en la plataformase imprime un mensaje de error. En caso contrario, se imprime el identificador del curso o un cero si no está inscrito en ningún curso.
