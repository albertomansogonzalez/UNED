procedure Main is

   -- Hay 3 tipos de parametros
   -- in (por defecto): solo lectura, como paso por valor y ademas constante "const"
   -- out: solo escritura, para devolver datos
   -- in out: lectura y escritura (como paso por referencia)

   procedure Procesar_Valores(X : in Integer; Y : out Integer; Z : in out Integer) is
   begin
      -- X se puede usar pero no modificar
      -- Y debe asignarse antes de salir
      -- Z puede usarse y modificarse
      Y := X * 2;
      Z := Z + 10;
   end Procesar_Valores;

   A : Integer;
   B : Integer := 4;

begin
   Procesar_Valores(4, A, B);
end Main;

