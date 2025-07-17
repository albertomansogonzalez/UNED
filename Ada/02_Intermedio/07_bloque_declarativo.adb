with Ada.Text_IO; use Ada.Text_IO;

procedure Main is
begin
   loop
      Put_Line ("Please enter your name: ");

      -- con "declare" que crea un bloque que tiene el alcance limitado
      -- se crean variables locales al bloque, no accesibles desde fuera del bloque. Como  { ... } en C
      declare --------------------------------------
         Name : String := Get_Line;
      begin
         exit when Name = "";
         Put_Line ("Hi " & Name & "!");
      end; ----------------------------------------

   end loop;

  Put_Line ("Bye!");
end Main;
