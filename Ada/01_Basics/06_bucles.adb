with Ada.Text_IO; use Ada.Text_IO;

procedure Main is
   Condicion : Boolean;
begin
   -- el bucle for es siempre "Range-Based"
   for I in 1 .. 5 loop -- recorrer I=1, 2, 3, 4 y 5
      Put_Line("Hola");
      --  I := 5; Error: no se puede modificar la variable del bucle
   end loop;

   -- con "reverse" se recorrer el rango a la inversa: I=5, 4, 3, 2 y 1
   for I in reverse 1 .. 5 loop
      null;
   end loop;


   -- bucle WHILE
   while Condicion loop
      -- exit; -- para salir del bucle (tambien para bucle tipo for y loop)
      -- no existe "continue"
      null;
   end loop;


   -- bucle infinito
   loop
      null;
      exit when Condicion; -- para salir si se cumple una condicion
end loop;

end Main;
