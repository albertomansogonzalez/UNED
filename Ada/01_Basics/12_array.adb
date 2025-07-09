procedure Main is

   -- ARRAYS

   -- ejemplo definicion de array parecido a lenguaje C
   Numeros : array (1 .. 10) of Integer; -- int Numeros[10]; pero con indice de 1-10

   -- En Ada se suele crear un tipo con nombre para cada array:
   type Mi_Array is array (1 .. 5) of Integer; -- creamos un tipo de dato
   Valores : Mi_Array;    -- declaramos una variable de ese tipo

begin

   Numeros := (10, 20, 30, 40, 50, others => 60); -- inicializacion mediante "aggregate" por posicion
   Valores := (1 => 10, 2 => 20, 3 => 30, 4 => 40, 5 => 50); -- aggregate por valor
   Valores(1) := 10; -- "()" : acceso a un elemento del arreglo



end Main;

