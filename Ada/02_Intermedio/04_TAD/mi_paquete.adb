with Ada.Text_IO; use Ada.Text_IO;

package body Mi_paquete is

   procedure Inicializar(X : out MiTAD) is
   begin
      X.Valor := 42;  -- this.Valor = 42
   end;

   procedure Mostrar(X : in MiTAD) is
   begin
      Put_Line("Valor = " & Integer'Image(X.Valor));
   end;
   
   procedure MostrarN(X : in MiTAD; N : in Integer) is
   begin
      for I in 1 .. N  loop
         Put_Line("Valor = " & Integer'Image(X.Valor));
      end loop;
   end;
   

end Mi_paquete;
