with Ada.Text_IO; use Ada.Text_IO;

procedure Main is
   Dia : Integer := 3;
begin
   case Dia is
      when 1 =>
         Put_Line("Lunes");
         -- el "break" es implicito
      when 2 .. 3 => -- se puede usar un rango
         Put_Line("Martes o Miercoles");
      when 4 | 5 =>  -- Operador "|" para multiples opciones
         Put_Line("Jueves o Viernes");
      when others => -- OBLIGATORIO si no se cubren todos los casos
         Put_Line("Fin de semana o día inválido");
   end case;
end Main;
