with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

   -- en Ada existen las funciones/procedimientos internos

   -- PROCEDIMIENTOS: Sin return  --------------------------------
   procedure Saludar is
   begin
      Put_Line("Hola desde procedimiento");
   end Saludar;

   -- ejemplo procedimiento con parametros
   procedure MostrarSuma(A, B: Integer) is
   begin
      null;
   end MostrarSuma;



   -- FUNCIONES :  tienen return obligatoriamente -----------------------
   -- Nota: idealmente en ada las funciones no deberian tener Efectos Colaterales
   function Cuadrado(N: Integer) return Integer is
   begin
      return N * N;
   end Cuadrado;


   function Procesar(Dato: Integer; Nombre: String; Activo: Boolean) return Float is
   begin
      return 0.0;
   end Procesar;



   resultado : Integer;


begin
   Saludar; --llamada a procedimiento sin parametros
   Saludar;
   MostrarSuma(3,4); -- llamada a procedimiento con parametros

   -- llamada a funcion
   resultado := Cuadrado(2); -- funcion obliga a manejar el return
end Main;

