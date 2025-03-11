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
-- Cuidado letras repetidas; para nrewTry "aaab" "bbba" tiene que dar: [('a',I),('a',N),('a',N),('b',I)]
--
-- Pasos del algoritmo:
-- 1. Marcar las letras coincidentes. Funcion "coincidentes" que devuelve un tipo Try con las letras coincidentes marcadas 'C'
-- 2. Eliminar las coincidentes de la palabra secreta. Funcion "elimin_coincident" que devuelve string quitando las letras correctas con '_'
-- 3. Juntando paso 1. y paso 2. aniadimos al Try del paso 1 las letras que no estan 'N' y las Incorrectas 'I'
--   3.1 Busca la letra de la palabra intento en la palabra secreta

newTry :: String -> String -> Try
newTry intento secreta = incorrectas intento (elimin_coincident intento secreta) (coincidentes intento secreta)
  where
    coincidentes :: String -> String -> Try     -- Marca las letras coincidentes, devolviente un tipo Try
    coincidentes [] [] = []
    coincidentes (x:xs) (y:ys)
     | x == y = (x, C):coincidentes xs ys
     | otherwise = (x, U):coincidentes xs ys
    
    elimin_coincident :: String -> String -> String    -- Elimna las coincidentes por ' '
    elimin_coincident [] [] = []
    elimin_coincident (x:xs) (y:ys)
      | x == y = ' ':elimin_coincident xs ys
      | otherwise = y:elimin_coincident xs ys
    
    incorrectas :: String -> String -> Try -> Try   -- Teniendo la palabra secreta sin coincidentes y el Try marcado con las coincidente
    incorrectas [] _ _ = []
    incorrectas (x:xs) ys (t:ts) -- busca la letra de la palabra intento en la palabra secreta
      | elem x ys && (snd t /= C) = (x,I):incorrectas xs (delete_first x ys) ts   --como si esta, la tiene que eliminar
      | snd t /= C = (x,N):incorrectas xs ys ts  -- si no esta
      | otherwise = (x,C):incorrectas xs ys ts
        where
          delete_first :: Char -> String  -> String
          delete_first _ [] = []
          delete_first a (x:xs)
            | a == x = ' ':xs
            | otherwise = x : delete_first a xs


--Marcar las coincidentes, devolver tupla Try con las ‘C’, las otras poner a ‘U’
--Eliminar las coincidentes de la secreta. (recibir Try del paso 1) (devolver String)
--Recorrer palabra intento. Primera letra, y sobre esta:
--Recorrer la palabra secreta.
--    Si se encuentra, eliminar letra de palabra secreta, y devolver I
--    Si no se encuentra, devolver N












-- devuelve Try con todas las letras posibles coom aun no utilizadas en ningun intento
initialLS :: Try
initialLS = initialLSStep letters
  where
    initialLSStep [] = []
    initialLSStep (x:xs) = (x, U):initialLSStep xs
-- otra opcion seria: initialLS = map (\x -> (x, U)) letters


-- recibe lista actual de letras utilizadas (ya etiquetadas segun su uso en intentos anteriores), otro
--   tipo Try conteniendo todas las letras de la palabra intento etiquetadas por "newTry"
-- devuelve la lista de letras utilizadas actualizando las etiquetas segun el nuevo intento
updateLS :: Try -> Try -> Try
updateLS a b = a -- TODO!!! lo pongo solo para que me compile

