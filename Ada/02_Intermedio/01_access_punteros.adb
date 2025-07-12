with Ada.Text_IO; use Ada.Text_IO;

procedure Main is
   
   -- para que una variable pueda ser apuntada por un puntero
   -- hay que indicarlo explicitamente con "aliased"
   X : aliased Integer := 10;

   -- declaramos un nuevo Tipo de Dato "puntero a entero" con "access all"
   type Int_Ptr is access all Integer;

   -- Puntero P
   P : Int_Ptr;
begin
   
   -- puntero apunta a direccion de X:
   P := X'Access; -- p = &X;
   
   -- Mostrar valor apuntado
   Put_Line("Valor apuntado: " & Integer'Image(P.all)); -- ".all" para acceder al puntero

   -- Modificar valor a través del puntero,
   P.all := 99; -- (se esta modificando el valor de X)

   -- Mostrar nuevo valor de X
   Put_Line("Nuevo valor de X: " & Integer'Image(X));
end Main;
