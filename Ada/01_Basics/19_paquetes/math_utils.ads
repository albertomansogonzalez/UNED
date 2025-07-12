-- en el fichero .ads ponemos el Package Specification (como fichero .h)

-- Solo lo declarado en el Package Specification es Visible desde fuera del paquete (Public)

package Math_Utils is

   function Square(X: Integer) return Integer; -- signatura de la funcion
   
   -- funcion "Identidad" es privada, porque no esta aqui declarada
   
   
   Pi : constant Float := 3.14159265358979; -- un paquete tambien puede contener variables y constantes

end Math_Utils;
