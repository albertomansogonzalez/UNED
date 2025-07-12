-- Los rangos se usan en:

-- Tipos derivados: "type Edad is range 0 .. 130;"
-- Subtipos: "subtype Adulto is Edad range 18 .. 130;"
-- Subtipo valores negativos: "subtype Rango_Limitado is Integer range -10 .. 10;"
-- Subtipo valores decimales: "subtype Temperatura_Ambiente is Float range -50.0 .. 100.0;"
-- Subtipo de enumerado: "subtype Dias_Laborales is Dia range Lunes .. Viernes;"
-- Subtipo rango de caracteres: "subtype Letras_Minusculas is Character range 'a' .. 'z';"
-- Arrays: "type Mi_Array is array (1 .. 5) of Integer;"
-- Array Slice: "Valores (2 .. 4) := (3, 4, 5);"
-- bucle for: "for i in 1 .. 10 loop"
-- en un case: "when 2 .. 3 =>"

procedure Main is

   type Edad is range 0 .. 130; -- limitado al rango (0,130), basado en Integer

   -- el subtipo tiene que tener un rango contenido en el rango base
   subtype Edad_Adulta is Edad range 18 .. 100;  -- (18,100) C (0,130)
   
   -- el subtipo es compatible con el tipo base, pero mucho cuidad con los valores asignados y los rangos -> "Constraint_Error"


   EdadPaco : Edad := 150; -- cuidado que no da error en tiempo de compilacion (si warning), solamente lanza excepcion en tiempo de ejecucion
   
begin
   EdadPaco := 170;  -- cuidado que no da error en tiempo de compilacion (si warning), solamente lanza excepcion en tiempo de ejecucion
   
end Main;
