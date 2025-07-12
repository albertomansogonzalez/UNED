with Ada.Text_IO; -- Put y Put_Line de Strings y caracteres

procedure Main is

   -- las Strings tiene longitud fija
   -- son como array de caracteres
   -- no almacenan caracter nulo de final de string
   
   Nombre : String(1 .. 20); -- -- Cadena de 20 caracteres fijos
   Saludo : String := "Hola";  -- Ada infiere tamaño: (1 .. 4) por la inicializacion con "Hola"
   
   
begin
   
   Nombre(1 .. 5) := "Perro"; -- (array slice), solamente se modifican los 5 primero caracteres, pero el resto siguen existiendo
   
   -- accedo a caracteres: Nombre(1) -- accede a la primera letra
   
end Main;

