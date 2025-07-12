with Ada.Text_IO;

with Math_Utils; -- with para poder usar el paquete
-- use Math_Utils; para acceder sin tener que poner el nombre del paquete primero

procedure Main is
   Res : Integer;
begin

   -- Acceso a una funcion publica del Paquete "Math_Utils"
   Res := Math_Utils.Square(5);
   Ada.Text_IO.Put_Line("El cuadrado de 5 es" & Integer'Image(Res));

   -- No se puede acceder a funcion privada del paquete:
   --Res := Math_Utils.Identidad(5);  -- esta definida en el Package Body pero no declarada en el Package Specificacion (.ads)

end Main;

