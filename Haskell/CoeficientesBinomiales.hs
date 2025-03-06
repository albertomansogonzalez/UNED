-- Funcion "binomial" que calcula el binomial de 2 numeros utilizando el triangulo de pascal
-- Uso: binomial 5 2  -> resultado 10
-- Profesor Fernando Lopez Ostenero

-- Paso 1. Crear el Triángulo de Pascal
-- Paso 2 Obtener la fila n-énisima con el elemento k-ésimo

-- Paso 1.Crear el triangulo de Pascal -----------------------------------------------
--      1
--     1 1
--    1 2 1
--   1 3 3 1
--  1 4 6 4 1
-- 1 5 10 10 5 1
--Ej: para calcular el 4, es la suma de los 2 nº de arriba:
--          4 = p + x = 1 + 3

-- pascalTriangle devuelve el triangulo de pascal.
-- devuelve una lista de listas, (lista de filas)
pascalTriangle :: [[Integer]]
pascalTriangle = iterate nextRow [1] --iterate es una funcion predefinida, crea una lista infinita aplicando x, f(x), f(f(x))...
    -- nextRow: recibe una fila previa del triangulo y devuelve la fila de abajo
    -- Ej. [1 3 3 1] -> devuelve [1 4 6 4 1]
    where nextRow :: [Integer] -> [Integer]
          nextRow pr =  iNextRow 0 pr
            where iNextRow :: Integer -> [Integer] -> [Integer]
            -- Parametro Integer p: guarda el digito anterior
            -- Parametro [Integer]: guarda la lista que queda por recorrer (fila previa)
            -- Salida [Integer]: devuelve la nueva fila 
                  iNextRow _ [] = [1] -- ultimo digito de la fila
                  iNextRow p (x:xs) = (p + x):(iNextRow x xs) --el nuevo elemento (p+x) es la suma de los 2 anteriores


-- Paso 2 Obtener la fila n-énisima con el elemento k-ésimo -----------------------------
binomial :: Int -> Int -> Integer
binomial n k
  | k > div n 2 = binomial n (n-k) -- propiedad matematica, (optimizacion opcional): el binamial de n k es igual que binomial de n (n-k)
  | otherwise = (pascalTriangle !! n) !! k