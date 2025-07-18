with Ada.Text_IO; use Ada.Text_IO;

-- Para sincronizar 2 tareas, (o main con una tarea), se utiliza objeto "entry"
-- es un Rendezvous, "accept" y "entry" se tienen que encontrar a la vez, (la que llegue antes espera a la otra)

-- Si el Main llega antes al entry, espera hasta el accept de la Tarea
    -->-- Main -->- .<entry>|          -------->--------  (Cliente)
--><                                  |
    -->-- Task -->--------->-------"accept"---->-------- (Servidor)


-- Si la Tarea llega antes al accept, espera al entry del Main
    -->-- Main -->--------->-------.<entry>----->-------  (Cliente)
--><                                  |
    -->-- Task -->-"accept"|          --------->--------  (Servidor)


procedure Main is

   -- declaracion de la tarea
   task T is
      entry Start; -- contiene objeto "entry" util para Sincronizacion, que llamamos Start
   end T;

   task body T is
   begin

      Put_Line ("Doing something");
      delay 1.0;
      accept Start; -- bloquea hasta que alguien llame a la entry          <- Sincronizacion
      -- continua la tarea concurrentemente:
      Put_Line ("In T");

   end T;

begin

   Put_Line ("In Main");
   delay 4.0;
   T.Start; -- bloquea hasta que alguien "acepte"                          <- Sincronizacion
   -- continua las instrucciones concurrentemente
   Put_Line ("In Main");

end Main;

