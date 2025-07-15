with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

   
   -- Tipo PUNTO FLOTANTE
   altura : Float := 1.75; -- punto flotante clasico
   type Mi_Flotante is digits 6; -- con precision de 6 digitos (parte entera + decimal)
   type T6 is digits 6 range -2.0 .. 2.0; -- se puede limitar a un rango
   X : Mi_Flotante := 123.456;  -- el Punto Flotante tiene errores de redondeo
   
   -- Tipo PUNTO FIJO. "is delta" (no tiene los errores de redondeo del punto flotante)
   type T3_D3 is delta 0.01 digits 3;
   type Mi_Fijo is delta 10.0 ** (-3) range -100.0 .. 100.0; -- precision delta 0.01: 1.00, 1.01, 1.02, 1.03 ...                         
   
begin

   -- ejemplo error de precision con el punto flotante
   X := 0.0;
   for I in 1 .. 1_000_000 loop
      X := X + 0.1;
   end loop;
   
   Put(X'Image);
   
end Main;
