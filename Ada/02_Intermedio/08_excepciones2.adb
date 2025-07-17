with Ada.Text_IO; use Ada.Text_IO;
with Ada.Exceptions;

procedure Main is
   mi_excepcion : exception;
begin

   begin -- subbloque interno para capturar excepcion, equivalente a bloque Try-Catch
      raise mi_excepcion with "Ha habido un error";
   exception
      when E : mi_excepcion => -- se aniade "E" para acceder a la informaion de la excepcion
         Put ("El error es: ");
         Put_Line (Ada.Exceptions.Exception_Message (E)); -- "Exception_Message()" para el mensaje que lanza el with
         Put_Line (Ada.Exceptions.Exception_Name (E)); -- "Exception_Name()" para el nombre

         raise; -- "raise;" sirve para relanzar otra vez la excepcion hacia arriba en la pila de llamadas
   end;

exception
   when others =>
      Put_Line("Capturada!"); -- aqui se vuelve a captura, porque "raise;" la ha vuelvo a lanzar hacia arriba

end Main;
