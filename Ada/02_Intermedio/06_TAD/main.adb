with Mi_paquete;

-- Mejor TAD que Clase (POO) si:
-- máximo control de los datos y de la interfaz pública.
-- tipo no necesita herencia ni polimorfismo.
-- rendimiento optimo sin dinamic dispatch.


--TAD vs Paquetes: si no se quiere tener instancias ni un tipo de datos -> usar simplemente Package


procedure Main is

   A : Mi_paquete.MiTAD; -- instancia del TAD MiTAD

begin

   -- no es notacion objeto.metodo(), si no que es Paquete.metodo(objeto, ... )
   -- es decir, el objeto se pasa como uno de los parametros
   Mi_paquete.Inicializar(A);
   Mi_paquete.Mostrar(A);
   Mi_paquete.MostrarN(A, 2);

end Main;
