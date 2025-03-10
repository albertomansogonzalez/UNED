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
--newTry :: String -> String -> Try
--newTry [] _ = []
--newTry (x:xs) secreata@(y:ys) -- ir recorriendo la palabra intento
--                              -- Usamos "ys++[y]" para ir almacenando por detras de la palabra las letras que ya hemos recorrido, para buscar el toda la palabra secreta.
--  | x == y          = (x, C):newTry xs ys  -- si coincide la letra -> Correcta
--  | elem x secreata = (x, I):newTry xs ys  -- si no coincide, pero si se encuentra en la palabra secreta
--  | otherwise       = (x, N):newTry xs (ys++[y]) -- si no coincide, y tampoco se encuentra en la palabra secret

-- aprox 20, 21 lineas

newTry :: String -> String -> Try
newTry intento secreta = foo intento (elimin_coincient intento secreta) (coincidentes intento secreta)

--Marcar las coincidentes, devolver tupla Try con las ‘C’, las otras poner a ‘U’
--Eliminar las coincidentes de la secreta. (recibir Try del paso 1) (devolver String)
--Recorrer palabra intento. Primera letra, y sobre esta:
--Recorrer la palabra secreta.
--    Si se encuentra, eliminar letra de palabra secreta, y devolver I
--    Si no se encuentra, devolver N

coincidentes :: String -> String -> Try
coincidentes [] [] = []
coincidentes (x:xs) (y:ys)
  | x == y = (x, C):coincidentes xs ys
  | otherwise = (x, U):coincidentes xs ys

elimin_coincient :: String -> String -> String
elimin_coincient [] [] = []
elimin_coincient (x:xs) (y:ys)
  | x == y = ' ':elimin_coincient xs ys
  | otherwise = y:elimin_coincient xs ys

-- intento, secreta sin coincidentes, try con coincidente, Devuelve try final
foo :: String -> String -> Try -> Try
foo [] _ _ = []
foo (x:xs) ys (t:ts) -- busca la letra en la palabra
  | elem x ys && (snd t /= C) = (x,I):foo xs (delete_first x ys) ts   --como si esta, la tiene que eliminar
  | snd t /= C = (x,N):foo xs ys ts  -- si no esta
  | otherwise = (x,C):foo xs ys ts

delete_first :: Char -> String  -> String
delete_first _ [] = []
delete_first a (x:xs)
  | a == x = ' ':xs
  | otherwise = x : delete_first a xs





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

