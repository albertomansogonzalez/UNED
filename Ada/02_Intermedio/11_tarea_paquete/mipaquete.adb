with Ada.Text_IO; use Ada.Text_IO;

package body MiPaquete is

   -- cuerpo de la tarea
   task body T is
   begin
      for I in 1 .. 6 loop
         Put_Line ("hello");
         delay 0.5;
      end loop;
   end T;

end MiPaquete;
