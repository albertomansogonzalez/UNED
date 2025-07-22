with Ada.Text_IO; use Ada.Text_IO;

-- "task type" es como "task", pero crea un Tipo de dato, de forma que se pueden
-- crear multiples tareas con la misma "plantilla"

procedure Main is
   task type TT;

   task body TT is
   begin
      Put_Line ("In task type TT");
   end TT;

   A_Task : TT; -- en cuanto se crea la instancia, se inicia la Tarea

begin

   Put_Line ("In main");
end Main;
