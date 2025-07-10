with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

   -- ENUMERADO
   type Color is (Rojo, Verde, Azul);

   -- Variable del tipo enumerado
   Mi_Color : Color;

begin

   Mi_Color := Verde;

   if Mi_Color = Rojo then
      Put_Line("El color es Rojo");
   elsif Mi_Color = Verde then
      Put_Line("El color es Verde");
   else
      Put_Line("El color es Azul");
   end if;

   --  Existe un bucle for para recorrer un tipo enumerado:
   for Mi_Color in Color loop
      null;
   end loop;


   -- No hay conversion implicita de Enumerado a Integer


end Main;

