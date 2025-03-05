-- Realizar raiz cuadrada mediante algoritmo tradicional, con infinitos decimales
-- Autor: Profesor Fernando Lopez
-- mySQRT dada una String como "320.831" -> devuelve la raiz en string infinita "17.91178..."
-- mySQRT :: String -> String
-- Ejemplo de uso: take 20 (mySQRT "320.831")
-- Utilizaremos una lista infinita string, para trabajar con el punto decimal.
-- Pasos del algoritmo implementado:
-- Paso 1. separar el numero en grupos de 2 cifras
--      123463.51234   ->   12 34 63 . 51 23 4   
-- Paso 2. Dado un resto y una raiz, calcular el siguiente digito, resto y raiz "bajando" el siguiente grupo

-- Modificacion respecto original:
-- He cambiado de "splitINT (x:y:zs) = [y,x]:(splitINT zs)""
-- a "splitINT (x:y:zs) = (splitINT zs)++[[y,x]]"", para no tener que usar "revert" despues

---------------------------------------------------------------------------------
-- Paso 1.Separar en grupos de 2 cifras
-- Entrada -> String : string con el numero (entero o con punto decimal)
-- Salida -> [String] :lista infinita de strings con los grupos de 2 cifras y el punto decimal
-- Ejemplo: "320.831" -> ["3", "20", ".", "83", "10", "00", "00"...]

-- Paso 1.1 distributeDigits: separa la parte entera de la decimal
-- aunque la parte entera queda invertida
-- Funcionamiento: recorre la string desde la izquierda, caractera a caracter.
--  hasta que llega a final de string, o al ".", mientras va guardando en el acumulador "revIntPart"
--  Cuando alcanza el fin de string, o el ".", ya termina, devolviendo la tupla, con la parte entera (aunque invertida), de la parte decimal
--
-- Ej: "320.831" -> ("023", "83100000...")
--
-- Entrada: String: numero
-- Entrada: revIntPart::String : Acumulador. Va construyendo la parte entera invertida
--                  Se inicializa a ""
-- Salida: tupla con (parte entera invertida, parte decimal)
--
distributeDigits :: String -> String -> (String, String)
distributeDigits [] revIntPart = (revIntPart, repeat '0') -- :si no hay punto decimal  
distributeDigits (x:xs) revIntPart
    | x == '.' = (revIntPart, xs ++ (repeat '0')) -- encuentra el punto, devuelve la tupla
    | otherwise = distributeDigits xs (x:revIntPart) -- llamada recursiva. En el acumulador se va guardando la parte entera, invertida


-- Paso 1.2A splitDEC: separa la parte decimal en grupos de 2 cifras
-- (la parte decimal siempre tiene infinitos ceros al final)
-- "83100000" -> ["83", "10", "00", "00"...]
splitDEC :: String -> [String]
splitDEC (x:y:zs) = [x,y]:(splitDEC zs) -- va creando la lista añadiendo "xy" (grupos de 2)
-- no se necesita caso base. porque la parte decimal es infinita 00000....

-- Paso 1.2B splitINT: separar la parte entera en grupos de 2 cifras
-- Ejemplo: "023" -> ["3", "20"]
splitINT :: String -> [String]
-- la parte entera si necesita caso base, porque si es finita
splitINT [] = [] --caso base. si tiene un nº par de cifras
splitINT [x] = [[x]] --caso base. si tiene un nº impar de cifras
splitINT (x:y:zs) = (splitINT zs)++[[y,x]] --como en el Paso 1. distributeDigits nos invertia la parte entera
                                        -- ahora a desinvertimos con "[y,x]" (en vez de [x,y])
                                        -- y tambien desinvertimos el orden de los grupos en si,

-- Paso 1 splitNumber: llama a Paso1. distributeDigits. Paso2A splitDEC y 2B splitINT
-- "320.831" -> ["3", "20", ".", "83", "10", "00", "00"...]
splitNumber :: String -> [String]
splitNumber n = (splitINT revIntPart) ++ ["."] ++ (splitDEC decPart)
    where (revIntPart, decPart) = distributeDigits n ""



-------------------------------------------------------------------
-- Paso 2. Ya tenemos la lista con los grupos de 2 en 2 digitos.
--  Aplicar el algoritmo de la raiz cuadrada



-- Recibe 3 parametros
--  rest: resto
--  root: la raiz
--  d : digitlo por el que se multiplica en el algoritmo tradicional: xxxxxd * d
--      se empieza probando con d=9, luego d=8, d=7... Hay que buscar el digito d maximo 
--      tal que (root*2) concatenado con el digito d * d sea <= que el resto actual
--      (equivalente a ((root*2) * 10 + d) *d < resto   
-- Salida: tupla con
--  Char: nuevo digito de la raiz, en ASCII
--  Integer: nuevo resto de la raiz
-- Integer: nuevo resultado de la raiz (sin punto decimal)
nextStep :: Integer -> Integer -> Integer -> (Char, Integer, Integer)
nextStep rest root d
    | rest >= product   = (head (show d), rest-product, root*10+d) --head (show d) para el ASCII
    | otherwise     = nextStep rest root (d-1)
    where product = (root*20+d)*d


--funcion iSQRT va produciendo el resutlado de la raiz cuadrada en forma de string.
--   cuando encuentra el "." simplemente lo aniade al resultado (raiz) y sigue con los decimales
--Parametros:
-- [String] Recive la lista de Strings calculada en el Paso 1
-- rest: resto 
-- root: raiz
-- Salida: String: resultado raiz cuadrada
iSQRT :: [String] -> Integer -> Integer -> String
-- no se necesita caso base porque la lista es infinita, (infinitos digitos decimales 0000...)
iSQRT (x:xs) rest root
    | x == "." = '.':(iSQRT xs rest root)   -- si se encuentra el ".", se aniade al String resultado
    | otherwise = nDigit:(iSQRT xs nRest nRoot) --va aniadiendo los digitos del resultado, aplicando el algoritmo definido en nextStep
                                                -- pasando el nuevo resto la nueva raiz
    where 
    (nDigit,nRest,nRoot) = nextStep (rest*100+iX) root 9 -- va "bajando" un nuevo grupo de 2 digitos (iX)
    iX = read x::Integer -- transforma de String ASCII a entero "83" a 83.



-----------------------------------------------------------
-- Unificar Paso 1 y Paso 2
mySQRT :: String -> String
mySQRT n = iSQRT (splitNumber n) 0 0



