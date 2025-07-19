with Ada.Text_IO; use Ada.Text_IO;

-- MONITOR: (mediante keyword "protected") asegura la exclusion mutua
-- estructura parecida a un Package
-- Un monitor puede contener, procedimientos, funciones y variables.
-- Solo un hilo puede ejecutar a la vez alguno de los procedimientos
-- Las variables son accedidas por los procedimientos.
-- Las funciones si se pueden ejecutar en paralelo solo si no modifican datos protegidos
-- Si la funcion accede a datos protegidos (incluso lectura), sigue habiendo exclusion.
-- Bloquea en una cola de espera a la Tarea
-- Se recomienda usar Monitores aun solo para proteger una sola variable, en vez de mutex explicitos como en C

procedure Main is

   -- MONITOR Specificacion
   protected Obj is -------------------------------------
      --  Operations go here (only subprograms)
      procedure Set (V : Integer);
      function Get return Integer;
   private
      --  Data goes here
      Local : Integer := 0;
   end Obj; ---------------------------------------------


   -- MONITOR Cuerpo
   protected body Obj is --------------------------------
      --  procedures can modify the data
      procedure Set (V : Integer) is
      begin
         Local := V;
      end Set;

      --  functions cannot modify the data
      function Get return Integer is
      begin
         return Local;
      end Get;
   end Obj; ---------------------------------------------

begin
   -- Utilizacion del MONITOR
   Obj.Set (5); -- asegura acceso con exclusion mutura
   Put_Line ("Number is: " & Integer'Image (Obj.Get)); -- asegura acceso con exclusion mutura
end Main;
