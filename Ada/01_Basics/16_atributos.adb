
-- ATRIBUTOS ' : se utiliza para acceser a atributos de un tipo u objeto

procedure Main is


   type Dias is range 1 .. 7;
   A : Dias;
   
   type Vector is array (2 .. 5) of Integer;
   
   num : Integer;
   Texto : String(1 .. 20);
   
begin
   
   -- <tipo>'First sobre rango: devuelve el ultimo valor posible del rango (el valor devuelto es del tipo en cuestion)
   -- <tipo>'Last sobre rango : devuelve el ultimo valor posible del rango (el valor devuelto es del tipo en cuestion)
   A := Dias'First; -- ultimo valor del tipo Dias del rango
   A := Dias'Last; -- ultimo valor del tipo Dias del rango
   
   -- <tipo>'First sobre tipo array: devuelve el primer indice
   -- <tipo>'Last sobre tipo array: devuelve el ultimo indice
   num := Vector'First; -- 2
   num := Vector'Last; -- 5
   
   -- <tipo>'Range: para referirse al rango o de un escalar o de un array
   for I in Vector'Range loop -- recorrer I=(2 .. 5)
      null;
   end loop;
   
   
   -- <tipo>'Image(variable)
   num := 43;
   Texto := Integer'Image(num);  -- Texto contendrá " 43" (con un espacio inicial)
   -- Boolean'Image( )
   -- Dias'Image( )  tambien para Enumerados
                                 
   
   -- 'Value: al reves que 'Image
   -- type Dias is (Lunes, Martes, Miercoles);
   -- D : Dias;
   -- D := Dias'Value("MARTES");
   -- I := Integer'Value("123");
   
end Main;
