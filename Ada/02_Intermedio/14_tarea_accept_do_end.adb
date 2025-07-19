with Ada.Text_IO; use Ada.Text_IO;

-- Poner bloque "do ... end" en "accept" sirve para
-- ejecutar ese bloque justo cuando se alcanca la "cita" (rendezvous).
-- El Cliente (Main) sigue bloqueado mientras la Tarea ejecuta el bloque.
-- Util para acceso seguro a recursos compartidos

procedure Main is

   task T is
      entry Start;
   end T;

   task body T is
   begin

      Put_Line ("Doing something");
      delay 1.0;
      accept Start do -- bloquea hasta que alguien llame a la entry          <- Sincronizacion
         Put_Line("Acceso seguro");
         delay 4.0;
      end Start;
      -- continua la tarea concurrentemente:
      Put_Line ("In T");

   end T;

begin

   Put_Line ("In Main");
   delay 4.0;
   T.Start; -- bloquea hasta que alguien "acepte" y se complete el bloque do .. end  <- Sincronizacion
   -- continua la tarea concurrentemente:
   Put_Line ("In Main");

end Main;
