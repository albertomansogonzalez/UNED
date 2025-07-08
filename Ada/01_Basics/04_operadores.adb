procedure Main is
  A, B, Resultado : Integer := 10;
  X, Y, Res : Boolean := True;
begin
   -- OPERADORES ARITMETICOS
   Resultado := A + B;
   Resultado := A - B;
   Resultado := A * B; -- multiplicacion
   Resultado := A / B;
   Resultado := A rem B; -- resultado mismo signo que el dividendo
   Resultado := A mod B; -- resultado mismo signo que el divisor
   Resultado := A ** B; -- potencia (elevado a)

   -- OPERADORES RELACIONALES
   Res := X = Y; -- compara si X es igual a Y
   Res := X /= Y; -- distinto de
   Res := X < Y;
   Res := X <= Y;
   Res := X > Y;
   Res := X >= Y;

   -- OPERADORES LOGICOS
   Res := X and Y;
   Res := X or Y;
   Res := not X;
   Res := X xor Y;
end Main;
