-- Boggle
-- Reglas
-- Secuencia de numeros y operaciones
-- Sin numeros repetidos
-- Sin saltar numeros
-- El ultimo nº es el resultado
-- Profesor Fernando Lopez Ostenero

-- Ejemplo de uso (tarda bastante tiempo): booble (problems !! 0) 

-- Ejemplo 7 + 8 = 15, (6+5)*2=22, 6+5+2=13
--  7 15 9 6    --Ejemplo, 6 + 9 = 15
--  3 8 12 5
-- 19 4 13 2
-- 14 1 22 10

-- Tipos de operaciones: igual, suma, resta, multiplicacion y division
-- Tipo de salida:       bool,  int,  int         int            int
-- Entrada: dos enteros

module Boggle where
 
import System.Directory
 


-- Tipos de Datos
type Size = Int    -- tipo para el tamanio de la matriz cuadrada
type Value = Int   -- tipo para el valor de cada casilla
type Position = Int -- tipo para la posicion de cada casilla en la matriz
data Operation = Eq | Add | Sub | Mult | Div
  deriving (Eq,Show)
data Result = Z Int | B Bool | Error --tipo Error po si sale numero negativo o division decimal 
  deriving (Eq, Show)

type Problem = (Size, [Value]) --tipo de dato que representa una partida inicial del Boggle, contiene el tamanio del tablero y la lista de valores de la matriz

type Node = (Size, [Value], [Position], [Operation], Result) -- Tipo para el nodo para el BackTraking
--   [Position]: lista de posiciones, la ultima_pos:pos-1:pos-2:...
--   [Operation]: lista de operaciones sobre las posiciones
-- (la lista de posiciones tendra siempre 1 elemento mas que la lista de operacionees, Ej: 4+5+7 son 2 operaciones y 3 elementos)

-- Esquema de Backtracking
-- necesita 3 parametros
-- param1: funcion "isSol": dado 1 nodo, devuelve si es solucion o no
-- param2: funcion "comp": funcion de compleciones. dado un nodo, devuelve una lista de nodos
-- param3: nodo: el nodo que estamos explorando
-- return: devuelve la lista de nodos solucion, a los que se llega desde el nodo dado.
backtrackin :: (a -> Bool) -> (a -> [a]) -> a -> [a]
backtrackin isSol comp nodo
 | isSol nodo = [nodo]   -- si el nodo de partida ya es solucion, la lista devuelta es solo el propio nodo
 -- mediante recursion, (y currificaion)
 -- 1º se calcula la lista de nodos alcanzables con "comp nodo"
 -- 2º con "map", a cada nodo, se le calcula a su vez la lista de nodos solucion
 -- 3º con "concat", se aplanan todas las listas, quedando una unica lista con los nodos solucion
 | otherwise = concat (map (backtrackin isSol comp) (comp nodo))

-- ¿es el nodo una solucion?
isSol :: Node -> Bool
isSol (_,_,_,_,r) = r == B True -- un nodo, cuyo resultado sea un booleano True es una solcion
                                -- ya que la operacion "=" es la unica que devuelve el booleano True

-- Ejecutar las operaciones
operate :: Operation -> Int -> Int -> Result
operate Eq x y = B (x == y)
operate Add x y = Z (x + y)
operate Sub x y
 | x >= y = Z (x -y)
 | otherwise = Error -- para no trabajar con valores negativos
operate Mult x y = Z (x * y)
operate Div x y
 | mod x y == 0 = Z (div x y)
 | otherwise = Error






-- Posiciones adyacentes
-- dada una posicion en la matriz, devuelve las posiciones adyacentes 
-- Ej:
-- (filas y columnas empienzan en '0')
-- 0 1 2   Ej: las posiciones adyacentes a la pos 1 son: 0,3,4,5,2 
-- 3 4 5
-- 6 7 8
--
-- segun la notacion, para calcula la posicion de una celda segun su fila y columna: 
--  posicion = col + fila * tamanio    (ej 5 = 2 + 1 * 3)
--
-- Ejemplo: positions 1 3 -> devuelve [0,2,3,4,5]

positions :: Position -> Size -> [Position]
-- posible celda colindante la llamamos (xx,yy)
positions p s = [xx + yy * s | yy <- [y-1..y+1], yy < s, yy >= 0, -- filas colindantes son y-1 e y+1, comprobando los limites
                               xx <- [x-1..x+1], xx < s, xx >= 0, -- columnas colindantes son x-1 e x+1, comprobando los limites
                               not (xx == x && yy == y)]          -- y quitando la propia casilla en si
  where x = mod p s  -- x es la columna
        y = div p s  -- y es la fila




-- ¿La lista contiene el valor?
contains :: Eq a => [a] -> a -> Bool
contains [] _ = False
contains (y:ys) x = x == y || contains ys x 


-- Compleciones, dado un nodo, devuelve la lista de nodos
comp :: Node -> [Node]
comp (s,vs,(p:ps),os,Z r) = filter (\(a,b,c,d,e) -> validR e ) [completion np no | np<-nextPos, no <- (Eq:ops)] --ops es para elegir si solo queremos usar ciertas operaciones
  where nextPos :: [Position]
        nextPos = filter (\x -> not (contains ps x)) (positions p s) --nextPos: posiciones adyacentes que aún no hemos visitado
        completion :: Position -> Operation -> Node
        completion np no = (s,vs,(np:p:ps),(no:os),nr)
          where nr :: Result 
                nr = operate no r (vs!!np) --nr: Nuevo Resultado
        validR :: Result -> Bool -- un resultado es válido cuando:
        validR (Z _) = True -- cualquier entero si es valido
        validR (B r) = r -- si bool es true, si es valido
        validR Error = False -- si da error, no es valido
comp _ = []


-- FUNCIÓN QUE CALCULA LOS NODOS INICIALES DEL PROBLEMA --
-- dado una matriz con los valores, nos da la lista de Nodos (con los campos rellenos iniciales)
-- por cada una de las posiciones de la matriz, para probar empezando con todas
initial :: Problem -> [Node]
initial (s,vs) = map (\x -> (s,vs,[x],[],Z (vs!!x))) [0..s*s-1] -- si la matriz es de 3x3, habra 9 nodos iniciales

-- Arrancar el Backtraking
solutions :: Problem -> [Node]
-- hay que empezar el bactraking, pero un backtraking por cada uno de los nodos iniciales.
-- Por eso esta funion "solutions" unifica todas las soluciones de todos los backtrakings
solutions problem = concat (map (backtrackin isSol comp) (initial problem)) 


-- Para printearlo por pantalla
printSol :: Node -> String
printSol (_,vs,ps,os,_) = (printLN ps os) ++ "\n"
  where printLN :: [Position] -> [Operation] -> String
        printLN (p:ps) os = (printLO ps os) ++ (show (vs!!p))
        printLO :: [Position] -> [Operation] -> String
        printLO [] [] = ""
        printLO ps (o:os)
          | o == Eq   = (printLN ps os) ++ "="
          | o == Add  = (printLN ps os) ++ "+"
          | o == Sub  = (printLN ps os) ++ "-"
          | o == Mult = "(" ++ (printLN ps os) ++ ")*"
          | o == Div  = "(" ++ (printLN ps os) ++ ")/"


-- FUNCIÓN QUE CONSTRUYE UN STRING CON TODAS LAS SOLUCIONES DEL PROBLEMA --
solString :: Problem -> String
solString problem = concat (map printSol (solutions problem))

-- FUNCIÓN QUE MUESTRA LAS SOLUCIONES POR PANTALLA --
boggle :: Problem -> IO ()
boggle problem = putStr (solString problem)


-- FUNCIÓN QUE GRABA LAS SOLUCIONES A UN FICHERO --
saveBoggle :: Problem -> FilePath -> IO ()
saveBoggle problem f = do { putStr("Saving solutions...");
                            let sol = solString problem in do
                                writeFile f sol;
                                putStr("done!\n");  
                          }
 
 -- PROBLEMAS DE EJEMPLO --
 -- 17 6 2
 -- 5 11 9
 -- 1 10 3
problems :: [Problem]
problems = [(3,[17,6,2,5,11,9,1,10,3]),
            (4,[7,15,9,6,3,8,12,5,19,4,13,2,14,1,22,10])
           ]

-- OPERACIONES A CONSIDERAR PARA EL PROBLEMA --
ops :: [Operation]
ops = [Add,Sub,Mult,Div]