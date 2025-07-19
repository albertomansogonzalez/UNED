with Ada.Text_IO; use Ada.Text_IO;

-- Si tenemos una Tarea corriendo en un bucle infinito (servidor):
-- utilizamos "select ... or terminate" para que automaticamente
-- finalice cuando ya no hay mas posibles llamadas

procedure Main is

   task T is
      entry Reset;
      entry Increment;
   end T;

   task body T is ------------- hilo Tarea -----------
      Cnt : Integer := 0;
   begin
      loop
         select
            accept Reset do
               Cnt := 0;
            end Reset;
            Put_Line ("Reset");
         or
            accept Increment do
               Cnt := Cnt + 1;
            end Increment;
            Put_Line ("In T's loop (" & Integer'Image (Cnt) & " )");
         or
            terminate;
         end select;
      end loop;
   end T;

begin ----------  Hilo principal -----------------

   Put_Line ("In Main");

   for I in 1 .. 4 loop
      T.Increment; -- se llama a la entry multiples veces
   end loop;

   T.Reset;

   for I in 1 .. 4 loop
      T.Increment; -- se  llama a la entry multiples veces
   end loop;

   -- Aqui ya Task termina automaticamente, porque ya no se la puede llamar mas
end Main;
