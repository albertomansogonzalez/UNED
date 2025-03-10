module Wordle where

-- Modulo para programar las funciones: validLetters, newTry, initialLS y updateLS

-- tipo de dato que almacena las pistas
-- Correctly placed | Incorrectly | Not in secret word | Unused (esta pista solo se utiliza en la lista de letras utilizadas) 
data Clue = C | I | N | U
  deriving (Eq,Ord,Read,Show)

-- lista de tuplas (caracter, pista), asocia a cada letra de la palabra intento (o la lista de palabras usadas) la pista correspondiente
type Try = [(Char,Clue)]

-- lista de letras validas
letters :: [Char]
letters = "abcdefghijklmnopqrstuvwxyz"

-- recibe una cadena de caracteres y devuelve si todas las letras de la cadena estan en la lista de letras validas
validLetters :: String -> Bool
validLetters [] = True
validLetters (x:xs) = (isValid x) && (validLetters xs)
  where
    isValid :: Char -> Bool
    isValid c = elem c letters


-- recibe la palabra intento, y la palabra secreta. Devuelve tipo Try: se marcan todas las letras de la palabra con las pistas
-- ej: newTry "camisa" "cierre" devuelve: [('c',C),('a',N),('m',N),('i',I),('s',N),('a',N)]
newTry :: String -> String -> Try
newTry [] _ = []
newTry (x:xs) secreata@(y:ys) -- ir recorriendo la palabra intento
                              -- Usamos "ys++[y]" para ir almacenando por detras de la palabra las letras que ya hemos recorrido, para buscar el toda la palabra secreta.
  | x == y          = (x, C):newTry xs (ys++[y])  -- si coincide la letra -> Correcta
  | elem x secreata = (x, I):newTry xs (ys++[y])  -- si no coincide, pero si se encuentra en la palabra secreta
  | otherwise       = (x, N):newTry xs (ys++[y]) -- si no coincide, y tampoco se encuentra en la palabra secret

-- devuelve Try con todas las letras posibles coom aun no utilizadas en ningun intento
initialLS :: Try
initialLS = initialLSStep letters
  where
    initialLSStep [] = []
    initialLSStep (x:xs) = (x, U):initialLSStep xs
-- otra opcion seria: initialLS = map (\x -> (x, U)) letters

-- recibe lista actual de letras utilizadas (ya etiquetadas segun su uso en intentos anteriores), otr
--   tipo Try conteniendo todas las letras de la palabra intento etiquetadas por "newTry"
-- devuelve la lista de letras utilizadas actualizando las etiquetas segun el nuevo intento
-- updateLS :: Try -> Try -> Try

