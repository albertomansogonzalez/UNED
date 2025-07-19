with Ada.Text_IO; use Ada.Text_IO;

-- Las "entry" es como una funcion, puede tener parametros.
-- Util para comunicarse con la tarea

-- Ademas puede haber multiples "funciones" entry


procedure Main is

   task Worker is
      entry Delete_Data(Value : Integer);                -- COMO FUNCIONES!!!
      entry Add_Data(Value : Natural; Car : Character);  -- ademas puede haber varias entrys
   end Worker;

   task body Worker is
   begin
         accept Delete_Data(Value : Integer) do
            Put_Line("Tarea recibio: " & Integer'Image(Value));
         end Delete_Data;

         accept Add_Data(Value : Natural; Car : Character) do
            Put_Line("Tarea recibio: " & Integer'Image(Value) & Car);
         end Add_Data;
   end Worker;

begin

   Worker.Delete_Data(42);  -- El hilo principal envia el valor 42 a la tarea
   Worker.Add_Data(99, 'C');

end Main;
