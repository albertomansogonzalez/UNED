package Encapsulate is
   
   procedure Hello;

private ------ a partir de aqui, no es visible para unidades externas

   procedure Hello2; -- si es accesible para los hijos
   
   
   -- procedure Hello3; -- si ni siquiera esta aqui en el .ads, tampoco es accesible desde el hijo
   
end Encapsulate;
