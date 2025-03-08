-- Sucesion de Collatz
-- Dado un numero n, su sucesor es:
--   c(n) = {
--           n/2     si n es par
--           3n+1    si n es impar
--           }

-- Ej: 6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
-- Ej: 7 → 22 → 11 → 34 → 17 → 52 → 26 → 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1


-- Conjetura: la sucesion acaba en '1'.
-- Profesor Fernando Lopez Ostenero



-- La secuencia de Collats de 1 ha de ser [1]
-- La secuencia de Collatz de cualquier otro numero n, empieza por n, y le sigue la secuencia de Collats de su sucesor
collatzSeq :: (Integral a) => a -> [a]
collatzSeq 1 = [1]
collatzSeq n = n : collatzSeq (sucesor)
  where 
    sucesor
     | n `mod` 2 == 0 = n `div` 2  --si n es par
     | otherwise = 3 * n + 1       -- si n es impar
