% Hay una serie de individuos que forman la familia
% Que pueden ser hombre o mujeres
% Que entre algunos de ellos se verifica la relacion ser hijo o hija
% Dos personas son padres de una tercera si ésta es hijo-ja de los dos
% Que un padre (madre) es un hombre(mujer) que verifica la rela padres
% Los abuelos son los que a su vez son padres de los de esa persona
% un abuelo/a es un hombre/mujer que verifica la relacion de abuelos
% alguien es nieto/a si es un hombre/mujer que tiene abuelos
%
%
% Supongamos el caso concreto de familia formada por el matrimonio
% Miguel y Estefania que tienen dos hijos Francisco y Gloria. Estos
% estan casados con Teresa y Manuel respectivamente. Aranzazu y Bruno
% son hijos de Teresa y Francisco y Diego y Paula son hijos de Mnauel y
% Gloria.
%
%             Miguel - Estefania
%  Francisco - _Teresa_  y    Gloria _Manuel_
%  Aranzazu y Burno             Diego y Paula
%

%Afirmaciones
hombre(miguel).
hombre(bruno).
hombre(manuel).
hombre(francisco).
hombre(diego).

mujer(estefania).
mujer(aranzazu).
mujer(teresa).
mujer(gloria).
mujer(paula).

%Relaciones basicas
progenitores(miguel, estefania, francisco).
progenitores(migue, estefania, gloria).
progenitores(francisco, teresa, aranzazu).
progenitores(francisco, teresa, bruno).
progenitores(manuel, gloria, diego).
progenitores(manuel, gloria, paula).

%Relaciones causales:
hijo_ja(X,Y) :- progeniores(Y,Z,X). %si es su padre
hijo_ja(X,Y) :- progenitores(Z,Y,X). %si es su madre
hijo(X,Y) :- hombre(X), hijo_ja(X,Y).
hija(X,Y) :- mujer(X), hijo_ja(X,Y).

padres(X,Y,Z) :- hijo_ja(Z,X), hijo_ja(Z,Y), dif(X,Y).

padre(X,Y) :- padres(X,Z,Y), hombre(X).
madre(X,Y) :- padres(X,Z,Y), mujer(X).

abuelos(X,Y,Z) :- padres(U,V,Z), (padres(X,Y,U) ; padres(X,Y,V)).
%   U y V son variables intermedias

abuelo(X,Y) :- abuelos(X,Z,Y), hombre(X).
abuela(X,Y) :- abuelos(X,Z,Y), mujer(X).

nieto(X,Y) :- abuelo(Y,X), hombre(X).
nieto(X,Y) :- abuela(Y,X), hombre(X).
nieta(X,Y) :- abuelo(Y,X), mujer(X).
nieta(X,Y) :- abuela(Y,X), mujer(X).

%usando recursividad
antepasado(X,Y) :- hijo_ja(Y,X). %caso base
antepasado(X,Y) :- hijo_ja(Y,Z), antepasado(X,Z). %caso recursivo

