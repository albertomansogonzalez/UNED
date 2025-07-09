with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

   -- "type": Nuevo tipo Rango, no compatible con el tipo base
   type Edad is range 0 .. 130; -- limitado al rango (0,130)
   type Contador is new Integer; -- sin limitar el rango
   type Dia is (Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo); -- tipo enumerado (ya visto)
   type Day is new Dias_Semana; -- nuevo tipo enumerado

   -- "subtype": Subtipo, mismo tipo, pero con restriccion del tipo base, 100% compatible
   subtype Edad_Adulta is Edad range 18 .. 100; -- limitado al rango (18,100)
   subtype Edad is Integer; -- es como si fuera un simple alias
   subtype Dias_Laborales is Dias_Semana range Lunes .. Viernes; -- subtipo de enumerado

   A : Integer;
   Anios_Paco : Edad := 20;
   Anios_Maria : Edad_Adulta;

begin

   -- A := Edad;         -- Error porque Edad es un nuevo tipo (no hay conversion implicita)
   -- A := Edad_Adulta;  -- Tampoco funciona con el subtipo

   -- si es compatible el subtipo con SU tipo
   Anios_Maria := Anios_Paco; -- Si sale de rango, salta excepcion CONSTRAINT_ERROR
   Anios_Paco := Anios_Maria;


   -- Conversion, Casteo explicito de tipos, (como en C)
   A := Integer(Anios_Maria);
   A := Integer(Anios_Paco);
   Anios_Paco := Edad(A);
   Anios_Maria := Edad_Adulta(A);
end Main;

