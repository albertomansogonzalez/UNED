-- en el fichero .adb ponemos el Package Body (como fichero .c)

package body Math_Utils is

   -- Definicion de la funcion
   function Square(X: Integer) return Integer is
   begin
      return X*X;
   end Square;

   -- Definicion de la funcion
   function Identidad(X: Integer) return Integer is
   begin
      return X;
   end Identidad;
   
end Math_Utils;
