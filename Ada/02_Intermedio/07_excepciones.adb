with Ada.Text_IO; use Ada.Text_IO;

-- En Ada se lanzan excepciones predefinidas y tambien se puede crear excepciones propias
--    Contraint_Error: rangos, overflow, null dereferences, division entre 0
--    Program_Error: menos habitual
--    Storage_Error: sin memoria Stack
--    Tasking_Error: tareas (multihilo)


procedure Main is

   -- en Ada las excepciones no son Tipos, son directamente Objetos
   Mi_Excepcion : exception; -- instancia de excepcion propia


   procedure Foo is
   begin
      -- do something
      raise Mi_Excepcion; -- lanzar la excepcion (usamos el objeto que hemos creado)
   end Foo;


begin

   Foo; -- como Foo devuelve una excepcion, el flujo ya no sigue por aqui

   -- o si se necesita lanzar aqui directamente:
   raise Mi_Excepcion;


exception --------------- bloque para capturar las excepciones ---------------
   when Mi_Excepcion => -- excepcion propia
      Put_Line("Se ha capturado la excepcion Mi_Excepcion");
   when Constraint_Error => -- excepcion predefinida
      Put_Line("Error: division por cero");
   when Program_Error => -- excepcion predefinida
      Put_Line("Error de programa");
   when others =>
      Put_Line("error desconocido");

end Main;
