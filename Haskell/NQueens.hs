-- Resolver el problema de las N reinas.
-- Uso: nReinas 8
-- devuelve una lista, con cada una de las posibles soluciones.
-- cada solucion es una lista de tuplas con las coordenadas de las reinas

-- se utiliza List Comprehensions, pero haskell por dentro hace Backtracking

nReinas :: Int -> [[(Int, Int)]]
nReinas n = solve n -- se utiliza funcion intermedia para fijar parametro "n"
  where
    solve 0 = [[]] --caso base
    -- se resuelve mediante recursion. Primero 1xN, luego 2xN, luego 3xN...
    -- se van aniadiendo columnas, aniadiendo reinas a las soluciones de (k-1)
    solve k = [(r,k): qs | qs <- solve (k-1), r <- [1..n], all (safe (r,k)) qs]
      -- safe: dadas 2 reinas, devuelve True si no se atacan
      where safe :: (Int, Int) -> (Int, Int) -> Bool
            safe (r1, c1) (r2, c2) =
                r1 /= r2 && c1 /= c2 && abs (r1 - r2) /= abs (c1 - c2) --comprueba columnas, filas y diagonales
  