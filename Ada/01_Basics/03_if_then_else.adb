with Ada.Text_IO;
use Ada.Text_IO; -- "use" para obviar nombre del paquete

procedure Main is
   N : Integer := -3;
begin

   if N > 0 then
      Put_Line("positivo");
   end if;


   if N > 0 then
      Put_Line("positivo");
   else
      Put_Line("negativo");
   end if;


   if N = 0 or N = 360 then
      null;                    -- ada obliga a que haya una expresion
   elsif N = 3 then
      null;
   elsif N = 4 then
      null;
   end if;

end Main;
