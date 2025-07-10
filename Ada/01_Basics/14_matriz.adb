with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure Main is

   -- Declaramos una matriz de 2 filas y 3 columnas
   type Matriz is array (1 .. 2, 1 .. 3) of Integer;

   -- Inicializamos la matriz
   M : Matriz := (
      1 => (1 => 10, 2 => 20, 3 => 30), -- fila 1
      2 => (1 => 40, 2 => 50, 3 => 60) -- fila 2
   );

begin
   -- Recorremos filas (1 y 2) y columnas (1, 2 y 3)
   for F in 1 .. 2 loop
      for C in 1 .. 3 loop
         Put(M(F, C)); -- acceso a elemento de la matriz
         New_Line;
      end loop;
   end loop;

end Main;
