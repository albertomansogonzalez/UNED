with Ada.Text_IO; use Ada.Text_IO;

-- En ada para crear hilos se utilizan Tareas, Task
-- La Task se ejecuta directamente cuando se llama la funcion que la contiene

-- En este ejemplo, como esta definida en la funcion Main, la tarea comienda al empezar el programa

    -->-- Main -->-
--><                    (se ejecutan concurrentemente, no hay un orden)
    -->-- Task -->-

-- Tarea esta compuesta por: Declaracion + Cuerpo


procedure Main is

   task T; -- declaracion de la tarea (se puede poner en un Package Specification)

   task body T is -- cuerpo de la tarea (se puede poner en un Package Body)
   begin
      Put_Line ("In task T");
   end T;


begin

   -- Hilo del Main principal
   Put_Line ("In main");

end Main;
