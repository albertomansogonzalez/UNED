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
-- 3. Juntando paso 1. y paso 2. Con la Funcion "incorrectas", aniadimos al Try del paso 1 las letras que no estan 'N' y las Incorrectas 'I'
--   Si la letra ya estaba marcada en el Try como correcta 'C', la mantiene como correcta y pasa a la siguiente letra
--   Si no, busca la letra en la palabra. Si si esta, se marca como 'I' y se elimina la primera por la izquierda con la funcion "delete_first"
--   si ni esta, se marca como 'N'

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
      | snd t == C     = (x,C):incorrectas xs ys ts     -- si ya estaba correcta, la deja correcta
      | elem x ys      = (x,I):incorrectas xs (delete_first x ys) ts   -- como si esta en la palabra secreta, la tiene que eliminar
      | otherwise      = (x,N):incorrectas xs ys ts  -- si no esta
        where
          delete_first :: Char -> String  -> String    -- devuelve la palabra secreta quitando la primera letra encontrada
          delete_first _ [] = []
          delete_first a (x:xs)
            | a == x = ' ':xs
            | otherwise = x : delete_first a xs





-- devuelve Try con todas las letras posibles como aun no utilizadas en ningun intento 'U'
initialLS :: Try
initialLS = initialLSStep letters
  where
    initialLSStep [] = []
    initialLSStep (x:xs) = (x, U):initialLSStep xs
-- otra opcion seria: initialLS = map (\x -> (x, U)) letters


-- recibe lista actual de letras utilizadas (ya etiquetadas segun su uso en intentos anteriores), otro
--   tipo Try conteniendo todas las letras de la palabra intento etiquetadas por "newTry"
-- devuelve la lista de letras utilizadas actualizando las etiquetas segun el nuevo intento
--      1. recorrer la pabra intento.
--      2. por cada letra, setear en el tipo try, 
updateLS :: Try -> Try -> Try
-- updateLS a b = a -- TODO!!! lo pongo solo para que me compile


-- recorremos cada letra de la palabra intento. (Usamos el parametro intento a modo de acumulador)
updateLS intento ((i,j):xi) = updateLS (set i intento j) xi
updateLS intento [] = intento -- si ya no quedan letras en la palabra intento, devolvemos el acumulador

-- busca la letra, en un tipo Try que contiene todas las letras con las pistas
--     y sustituye la pista en el caracter buscado.
set :: Char -> Try -> Clue -> Try
set letra ((l,m):xl) p
  | letra /= l = (l,m):set letra xl p -- si no la encuentra, sigue buscando
  -- si ya estamos en la posicion de la letra:
  | p < m = (l,p):xl -- si la nueva pista es mas util, la modifica.(gracias a Deriving Ord)
  | otherwise = (l,m):xl -- si ya tenia una pista mas util, la mantiene
