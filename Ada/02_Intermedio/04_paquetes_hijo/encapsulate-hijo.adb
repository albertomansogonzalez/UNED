package body Encapsulate.Hijo is

   -- El Hijo puede acceder al paquete padre: a lo publico Y a los privado
   -- Pero solo si esta en el .ads del padre, (si solo lo tiene en el .adb no)
   
   procedure Foo is
   begin
      Hello;
      Hello2;
      -- Hello3; -- este metodo no esta en el .ads, no puede acceder
   end Foo;

end Encapsulate.Hijo;
