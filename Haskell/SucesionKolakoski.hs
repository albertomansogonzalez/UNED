-- Sucesion de Kolakoski en Haskell

-- Ejemplo de uso: ghci> take 20 (kolakoski [1,2])
--               genera: [1,2,2,1,1,2,1,2,2,1,2,2,1,1,2,1,1,2,2,1]


-- conjunto {1,2}
-- 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 2, 2, 1, 1, 2, 1, 1, 2, 2, 1, ...

-- Se compone por elementos individuales, o parejas:
-- Elementos individuales:
-- 1              2  1        1              2      ...
-- elementos en parejas:
--    2  2  1  1        2  2     2  2  1  1     1  1  2  2  

--Cumple propiedad que si se pone:
--  1: para elementos individuales
--  2: para los grupos de parejas
-- entonces se obtiene a su vez la propia sucesion
-- sucesion:  1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 2, 2, 1, 1, 2, 1, 1, 2, 2, 1, ...
-- nº grupo:  1   2      2   1  1    2   1    2    2    1    2    2 ...


-- Sucesion generalizada de Koakoski
-- a parte de la de {1,2}, hay muchas otras posibles como:
-- con {1,2,3} -> 1,2,2,3,3,1,1,1,2,2,2,3,1,2,3,3,1,1,2,2...
-- sucesion cont: 1  2   2   3     3    1 1 1  2   2 ....


-- Funcion sucesion contadora
-- (esta funcion no la usamos para construir la sucesion de Kolakoski)
-- (nos servira para comprobar)
-- Dada una sucesion, devuelve la lista con los numeros de cuenta segun el nº de elementos de cada grupo
-- si grupo de un elemento -> 1
-- si grupo de 2 elementos -> 2
-- si grupo de 2 elementos -> 3 
-- etc.
-- puede contar cualquier tipo (que sea Eq), ejem:
-- "aaaabbcddeffffgh" -> devuelve [4,2,1,2,1,4,1,1]
type Count = Int   -- tipo de datos para el elemento de la sucesion
sc :: (Eq value) => [value] -> [Count]
sc [] = [0]
sc (x:xs) = scAux x 1 xs
  --                         value: valor del elemento (se va recorriendo la lista, elemento a elemento)
  --                         Count: acumulador que va contando el nº de veces que se va leyendo el elemento
  where scAux :: (Eq value) => value -> Count -> [value] -> [Count]
        scAux _ n [] = [n]
        scAux x n (z:zs)
         | x == z  = scAux x (n+1) zs -- si el nuevo elemento es el mismo que el previo, se suma 1 al contador
         | otherwise = n:(scAux z 1 zs) -- si es un nuevo elemento, con "n:" ya lo ponemos como elemento de la lista, y se cuenta el siguiente elemento



-- Algoritmo:
-- utilizamos:
--     Alfabeto {1,2}
--     Memoria (a modo de cola FIFO): [] 
-- 1º emepezamos con el primer elemento del alfabero: '1'
-- 2º miramos en la memoria,
--     si mem vacia:  ponemos en la lista el elemento, tantas veces como indica el propio elemento
--     si mem no vacia:   "                   "      ,   "               "      el primer elemento de la memoria
-- 3º tambien lo metemos en la memoria FIFO
-- 4º una vez metido en la memoria, de esta eliminamos el primer elemento
-- 5º pasamos el siguiente elemento de alfabeto: '2'. y vamos al paso 2º.

type Alphabet = [Int] -- tipo para el conjunto de elementos del que queremos calcular la sucecion, Ej elemenos [1,2]
type Memory = [Int]   -- tipo para memoria que utilizaremos para el algoritmo

-- la funcion kolakoski, solo tiene de entrada el conjunto de alfabeto
kolakoski :: Alphabet -> [Int]
kolakoski a = kstep a []   -- para inicializar la memoria, (empieza vacia)
  where kstep :: Alphabet -> Memory -> [Int]
        -- si la memoria esta vacia:
        kstep alpha@(a:as) [] = memory ++ (kstep (suc alpha) (tail memory))  -- tail: elimina el primer elemento                                                   
          where memory :: Memory
                memory = take a (repeat a) -- tantas veces como el propio elemento: si a es 2 -> "22", 3 -> "333", o si a es 4 -> "4444"... 
        -- si la memoria no esta vacia:
        kstep alpha@(a:as) (x:xs) = memory ++ (kstep (suc alpha) (xs ++ memory))
          where memory :: Memory
                memory = take x (repeat a) -- tantas veces como indica el elemento de la memoria
        suc :: Alphabet -> Alphabet
        suc (a:as) = as ++ [a] -- coge el primer elemento, y lo pasa al final (generando un bucle)
