%Entrantes: Paella, Gazpacho y Potaje
%Pesados: Besugo, Bacalao
%Carnes: Filete, Pollo
%Postres: Tarta Helada, Nueces con miel, Naranja

%La carta
entrante(paella).
entrante(gazpacho).
entrante(potaje).

plato_de_carne(filete).
plato_de_carne(pollo).
plato_de_pescado(besugo).
plato_de_pescado(bacalao).

postre(tarta_helada).
postre(nueces_con_miel).
postre(naranja).

%Plato principal
plato_fuerte(X) :- plato_de_carne(X).
plato_fuerte(X) :- plato_de_pescado(X).
% o tambien: plato_fuerte(X) :- plato_de_carne(X); plato_de_pescado(X).

%Composicion de una comida
menu(X,Y,Z) :- entrante(X), plato_fuerte(Y), postre(Z).

%Tambien se puede decir:
menu(X,Y,Z) :- entrante(X), (plato_de_carne(Y); plato_de_pescado(Y)), postre(Z).
%o tambien
%    menu(X,Y,Z) :- entrante(X), plato_de_carne(Y), postre(Z).
%    menu(X,Y,Z) :- entrante(X), plato_de_pescado(Y), postre(Z).
%



%Consultas
% ?- menu(X,Y,Z).  ¿Cuales son los menus contenidos en la carta?
% ?- menu(paella, filete, naranja). ¿forman un menu?
% ?- menu(paella, X, naranja).
