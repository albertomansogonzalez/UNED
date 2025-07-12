with Ada.Text_IO; -- Put y Put_Line de Strings y caracteres

with Ada.Integer_Text_IO; -- para Integers
with Ada.Float_Text_IO; -- para Float

procedure Main is

   Valor : Integer := 34;
   
   Nombre : String(1 .. 20);
   Longitud : Natural;
   
begin
   
   -- Put() para Strings y para caracteres
   Ada.Text_IO.Put("Hola, mundo!"); -- Put() no hace salto de linea
   Ada.Text_IO.Put_Line("Hola, mundo!"); -- Put_Line() mete un salto de linea al final
   Ada.Text_IO.Put('C');
   -- Ada.Text_IO.Put(3); -- error
   
   Ada.Text_IO.New_Line; -- salto de linea
   
   Ada.Text_IO.Put("El valor es: ");
   Ada.Text_IO.Put(Valor'Image); -- atributo 'Image para convertir a string
   
   Ada.Text_IO.New_Line;
   
   Ada.Integer_Text_IO.Put(3);
   Ada.Float_Text_IO.Put(3.14);
   
   
   
   Ada.Text_IO.New_Line;
   
   -- Get() para leer de stdin
   Ada.Text_IO.Get(Nombre);
   Ada.Text_IO.Put(Nombre);
   
   -- Get_Line para leer una linea entera con espacios, hasta un enter:
   -- Get_Line(Item : out String; Last : out Natural);
   -- Item: donde se escribe la cadena leida
   -- Last: numero de caracteres leidos
   Ada.Text_IO.Get_Line(Nombre, Longitud);
   Ada.Text_IO.Put("Has escrito: ");
   Ada.Text_IO.Put(Nombre(1 .. Longitud));
   
end Main;

