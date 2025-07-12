with Ada.Text_IO;

procedure Main is
-- region de Declaraciones

   peso : Integer;                 -- variable sin inicializar
   edad : Integer := 25;           -- variable inicializada
   id : constant Integer := 1234;  -- constante
   a, b : Integer := 0;                 -- declaracion multiple
   altura : Float := 1.75;
   distancia : Natural;            -- solo positivos
   nombre : String := "Ana";
   activo : Boolean := True;
   inicial : Character := 'A';

begin
-- region de expresiones

   peso := 30;              -- asignacion
   peso := 2 + peso;        -- expresion

end Main;
