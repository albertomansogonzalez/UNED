
-- Factorial de n mediante If else
fact1 :: Integer -> Integer
fact1 n = if n == 0 then 1
                    else n * fact1 (n-1)

-- Factorial de n mediante guardas
fact2 :: Integer -> Integer
fact2 n
    | n == 0    = 1
    | otherwise = n * fact2 (n-1)

-- Factorial de n mediante patrones
fact3 :: Integer -> Integer
fact3 0 = 1
fact3 n = n * fact3 (n-1)

-- Factorial de n
fact4 :: Integer -> Integer
fact4 n = case n of
    0 -> 1
    otherwise -> n * fact4 (n-1)

-- Factorial de n
fact5 :: Integer -> Integer
fact5 n = case n of
    0 -> 1
    _ -> n * fact4 (n-1)

fact6 ::  Integer -> Integer
fact6 n = product [1..n]

fact7 :: Integer -> Integer
fact7 n = foldr (*) 1 [1..n]

-- Coeficiente binomial mediante recursion
binRec :: Int -> Int -> Integer
binRec n k
  | k == 0 || k == n = 1
  | otherwise        = (binRec (n-1) (k-1)) + (binRec (n-1) k)


-- Rotation a la izquierda
rotarleft :: [a] -> [a]
rotarleft (x:xs) = xs ++ [x]


-- combinaciones (Producto Cartesiano)
combinaciones :: [a] -> [[a]]
combinaciones [] = [[]]  -- Caso base, el conjunto vacio solo tiene la combinacion vacia
combinaciones (x:xs) =
  let
    sinElemento = combinaciones xs -- combinaciones sin incluir el primer elemento
    conElemento = map (x:) sinElemento -- añadir el primer elemento a cada combinacion
  in
    sinElemento ++ conElemento -- combinar ambas posibilidades


-- comprobar rango
in_range :: Integer -> Integer -> Integer -> Bool
in_range min max x = x >= min && x <= max

-- invertir string
invertir :: String -> String
invertir [] = []
invertir (x:xs) = invertir xs ++ [x]

-- factores de un numero por lista por comprension
factores :: Int  -> [Int]
factores n = [x | x <- [1..n], mod n x == 0]

-- buscar en una lista de tuplas, un elemento caracter:
busca :: Char -> [(Char, Int)] -> Int
busca _ [] = error "No encontrada"
busca i ((i',v):xs)
  | i == i' = v
  | otherwise = busca i xs

-- aplanar listas
concatenar :: [[a]] -> [a]
concatenar [] = []
concatenar (x:xs) = x ++ concatenar xs

concatenar2 :: [[a]] -> [a]
concatenar2 xs = foldr (++) [] xs


-- elemento maximo de una lista
maximo :: (Ord a) => [a] -> a
maximo [x] = x
maximo (x:xs) = max x (maximo xs)

-- zipwith
zipWith' _ [] _ = []
zipWith' f (x:xs) (y:ys) = (f x y):(zipWith' f xs ys)

--collatz
collatz :: Int -> [Int]
collatz 1 = [1]
collatz n
  | even n = n:collatz(div n 2)
  | odd n = n:collatz(n*3+1)




-- tipo de dato recursivo
data Natural = Cero | Suc Natural

naturalAInt :: Natural -> Int
naturalAInt Cero = 0
naturalAInt (Suc n) = 1 + (naturalAInt n)


