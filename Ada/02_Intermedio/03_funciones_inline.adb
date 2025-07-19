procedure Main is

   function Suma(X, Y : Integer) return Integer with Inline is -- "with Inline" para funciones Inline
   begin
      return X + Y;
   end Suma;

   A : Integer;


begin

   A := Suma(3,5);

end Main;
