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
-- newTry :: String -> String -> Try

-- devuelve Try con todas las letras posibles coom aun no utilizadas en ningun intento
-- initialLS :: Try

-- recibe lista actual de letras utilizadas (ya etiquetadas segun su uso en intentos anteriores), otr
--   tipo Try conteniendo todas las letras de la palabra intento etiquetadas por "newTry"
-- devuelve la lista de letras utilizadas actualizando las etiquetas segun el nuevo intento
-- updateLS :: Try -> Try -> Try

