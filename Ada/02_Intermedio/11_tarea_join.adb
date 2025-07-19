with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

   -- se pueden tener multiples Tareas
   task Tarea1;
   task Tarea2;

   task body Tarea1 is
   begin
      for I in 1 .. 5 loop
         Put_Line("Tarea1: " & Integer'Image(I));
         delay 0.5; -- espera pasiva
      end loop;
   end Tarea1;

   task body Tarea2 is
   begin
      for I in 1 .. 5 loop
         Put_Line("Tarea2: " & Integer'Image(I));
         delay 0.8; -- espera pasiva
      end loop;
   end Tarea2;


begin

   Put_Line("Inicio del hilo principal.");
   delay 1.0;
   Put_Line("Fin del hilo principal.");

end Main; -- implicitamente, el hilo principal espera a que acabe la tarea, join() implicito
          -- si alguna de las Tareas no acaba, el programa no termina nunca
