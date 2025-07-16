-- el TAD tiene que estar dentro de un Paquete

package Mi_paquete is

   type MiTAD is private; -- inidica al exterior que hay un record privado llamado "Tipo"
   -- type Stack is limited private; -- igual, pero no tiene copia ni comparacion por defecto: S1 := S2; ni if S1 = S2 then ...

-- metodos publicos del TAD:
   procedure Inicializar(X : out MiTAD); -- los metodos interactuan con el Objeto por un Parametro!
   procedure Mostrar(X : in MiTAD); -- tipo in equivale a un metodo constante
   procedure MostrarN(X : in MiTAD; N : in Integer); -- metodo con un parametro N

private
   
-- atributos privados del TAD
   type MiTAD is record
      Valor : Integer;
   end record;

end Mi_paquete;
