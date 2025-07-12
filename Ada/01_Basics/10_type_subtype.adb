with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

   -- "type": Nuevo tipo llamado "tipo derivado", no compatible con el tipo base, excepto casteo explicito
   type Contador is new Integer; -- sin limitar el rango
   type Edad is range 0 .. 130; -- limitado al rango (0,130), basado en Integer
   type Dia is (Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo); -- tipo enumerado (ya visto)
   type Day is new Dia; -- nuevo tipo enumerado

   -- "subtype": Subtipo, mismo tipo, pero con restriccion del tipo base, 100% compatible
   subtype Edad_Adulta is Edad range 18 .. 100; -- limitado al rango (18,100)
   subtype ContadorNew is Integer; -- es como si fuera un simple alias
   subtype Dias_Laborales is Dia range Lunes .. Viernes; -- subtipo de enumerado

   C1 : Contador;
   C2 : ContadorNew;
   A : Integer;
   Anios_Paco : Edad := 20;
   Anios_Maria : Edad_Adulta;

begin
   
   -- TYPE VS SUBTYPE:
   
   -- C1 es un nuevo tipo Contador, no compatible con Integer
   C1 := 10; -- pero si se puede asignar literal numerico como "25", ya el compilador no lo considera obligatoriamente Integer
   --C1 := Integer(10); -- si da error
   C2 := Integer(10); -- C2 es de tipo ContadorNew que si es un subtipo de Integer, si es compatible

   -- A := Edad;         -- Error porque Edad es un nuevo tipo (no hay conversion implicita)
   -- A := Edad_Adulta;  -- Tampoco funciona con el subtipo
   
   -- si es compatible el subtipo con SU tipo
   Anios_Maria := Anios_Paco; -- Si sale de rango, salta excepcion CONSTRAINT_ERROR
   Anios_Paco := Anios_Maria;


   -- Conversion, Casteo explicito de tipos, (como en C)
   A := Integer(C1); -- casteo de tipo deribado a tipo base
   C1 := Contador(A); -- casteo de tipo base a tipo derivado
   A := Integer(Anios_Paco); -- tipo derivado Edad se castea a tipo base Integer
   A := Integer(Anios_Maria); -- Anios_Maria es de tipo Edad_Adulta, que es subitpo de Edad, -> se castea a tipo base Integer
   Anios_Paco := Edad(A); -- tipo base Integer se castea a tipo derivado Edad
   Anios_Maria := Edad_Adulta(A); -- tipo base Integer se castea a subtipo Edad_Adulta (porque es un subtipo del tipo derivado Edad)

end Main;
