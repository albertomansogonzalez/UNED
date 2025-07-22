with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

   -- MONITOR -----------------------------------------------------
   protected Obj is
      procedure Set (V : Integer);
      entry Get (V : out Integer); -- entry para que la funcion tenga una barrera bajo una condicion
   private
      Local  : Integer;
      Is_Set : Boolean := False;
   end Obj;

   protected body Obj is
      procedure Set (V : Integer) is
      begin
         Local := V;
         Is_Set := True;
      end Set;

      entry Get (V : out Integer) when Is_Set is --Is_Set es la condicion de barrera
         --  Entry is blocked until the condition is true. The barrier is evaluated at call of entries
         --  and at exits of procedures and entries. The calling task sleeps until the barrier is released.
      begin
         V := Local;
         Is_Set := False;
      end Get;
   end Obj;
   -- FIn MONITOR -----------------------------------------------------



   N : Integer := 0;

   task T;

   task body T is
   begin
      Put_Line("Task T will delay for 4 seconds...");
      delay 4.0;

      Put_Line("Task T will set Obj...");
      Obj.Set (5);

      Put_Line("Task T has just set Obj...");
   end T;

begin

   Put_Line("Main application will get Obj...");
   Obj.Get (N);

   Put_Line("Main application has retrieved Obj...");
   Put_Line("Number is: " & Integer'Image (N));

end Main;
