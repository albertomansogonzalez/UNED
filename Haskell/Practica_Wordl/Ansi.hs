module Ansi where
-- Modulo para colorear el texto mostrado por consola

-- tipo colores posibles
data Color = Black | Red | Green | Yellow | Blue | Magenta | Cyan | White | Default
  deriving (Enum,Show)

-- tipo para indicar si el color sera oscuro o brillante
data Intensity = Dark | Bright
  deriving (Enum,Show)

-- dada una intensidad y un color, prepara la consola para que el siguiente texto se dibuje en ese color
ansiSetInkColor :: Intensity -> Color -> IO ()
ansiSetInkColor i c = putStr ("\ESC[" ++ show ((fromEnum c)+30+(fromEnum i)*60) ++ "m")

-- dada una intensidad y un color, prepara la consola para que el siguiente texto se dibuje con ese color de fondo
ansiSetBackColor :: Intensity -> Color -> IO ()
ansiSetBackColor i c = putStr ("\ESC[" ++ show ((fromEnum c)+40+(fromEnum i)*60) ++ "m")

-- devuelve la consola a su configuracion por defecto
ansiReset = putStr "\ESC[0m"
-- para siguiente texto en negrita
ansiBold = putStr "\ESC[1m"
-- para siguiente texto en cursiva
ansiItalic = putStr "\ESC[3m"
-- para siguiente texto en subrayado
ansiUnderline = putStr "\ESC[4m"
-- para siguiente text parpadeando
ansiBlinking = putStr "\ESC[5m"
-- borra la linea en la que se encuentra el cursor
ansiEraseLine = putStr "\ESC[2K"
-- borra toda la consola
ansiClearScreen = putStr "\ESC[2J\ESC[H"

-- recibe un entero n, mueve el cursor n lineas hacia arriba
ansiCursorUp :: Int -> IO ()
ansiCursorUp n = putStr ("\ESC["++show(n)++"A")
