with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

   type Dia_Semana is (Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo);

   -- ARRAY INDEXADO POR ENUM, que guarda booleanos
   type Laboral_Array is array (Dia_Semana) of Boolean; -- en ada, los array a parte de tener indice un entero, pueden tener de indice un enumerado

   Es_Laboral : Laboral_Array := (
      Lunes     => True,
      Martes    => True,
      Miercoles => True,
      Jueves    => True,
      Viernes   => True,
      Sabado    => False,
      Domingo   => False
   );

begin
   -- Recorremos el array y mostramos la información
   for Dia in Dia_Semana loop -- es equivalente iterar sobre el enumerado a iterar el array en sí, ya que el array esta indexado por el enumerado
      if Es_Laboral(Dia) then
         Put_Line("Laboral");
      else
         Put_Line("No Laboral");
      end if;
   end loop;
