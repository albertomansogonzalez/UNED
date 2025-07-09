with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

   -- RECORD es equivalente a struct en C
   type Sensor is record
      ID        : Integer;
      Activo    : Boolean := False; -- valor por defecto
      Valor     : Float;
   end record;

   S : Sensor; -- variable sin inicializar
   S1 : Sensor := (101, True, 23.5); -- inicializacion mediante "aggregate" por posicion
   S2 : Sensor := (ID => 101, Activo => True, Valor => 23.5); -- inicializacion mediante "aggregate" por nombre
   S3 : Sensor := (       -- se puede poner en varias lineas:
      ID => 101,
      Activo => True,
      Valor => 23.5
   );
   S4 : Sensor := (ID => 101, Activo => True, others => 23.5); -- "others" para los campos restantes (tienen que ser del mismo tipo)


begin

   -- acceso al campo de un Record
   S.ID := 3;
   S.Activo := True;
   S.Valor  := 23.5;


end Main;

