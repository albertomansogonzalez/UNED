es_fruta(pera).
es_fruta(naranja).
es_fruta(fresa).







ama(manuel, X) :- mujer(X). %manuel ama a cualquier mujer
mujer(X) :- ama(X, manuel). %solo las mujeres aman a manuel
hombre(francisco). %francisco es hombre
ama(francisco, teresa). %francisco ama a teresa


%factorial de un numero
%consulta: ?- factorial(3,X).  % respuesta: X = 6
factorial(0,1). %caso base, el 0! = 1
%el factorial de N! es M:
factorial(N,M) :- I is N-1, factorial(I,A), M is N*A.


