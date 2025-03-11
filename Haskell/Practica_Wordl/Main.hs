module Main where
-- Modulo principal con las funciones para interactuar con el usuario

-- Implementacion en Haskell del juego del Wordle

-- letras duplicadas:
-- palabra clave: b r a g a
--                r a p a r  : la primera 'r' debe ser amarilla, pero la segunda gris!!! (porque "ya no quendan mas")
--                g a l g o  : la primera 'g' gris, la segunda 'g' verde



import Ansi
import Wordle
import Data.Char
import System.IO

-- showTry: utliza modulo Ansi. Colorea las letras de un intenro o de las letras utilizadas. 
showTry :: Try -> IO ()
showTry [] = putStrLn ""
showTry ((l,c):xs)
  | c == C = do { ansiSetInkColor Bright Green;
                  putStr [l];
                  showTry xs
                }
  | c == I = do { ansiSetInkColor Bright Yellow;
                  putStr [l];
                  showTry xs
                }
  | c == N = do { ansiSetInkColor Dark Red;
                  putStr [l];
                  showTry xs
                }
  | c == U = do { ansiSetInkColor Dark Black;
                  putStr [l];
                  showTry xs
                }

-- showAllTries: mostrar coloreados los intentos y las letras ya utilizadas
showAllTries :: [Try] -> Try -> IO ()
showAllTries [] ls = do { ansiBold;
                          putStr "\nLetras usadas: ";
                          showTry ls;
                          putStrLn "";
                          ansiReset;
                        }
showAllTries (x:xs) ls = do { ansiBold;
                              showTry x;
                              ansiReset;
                              showAllTries xs ls;
                            }

-- addTry: aniadir nuevo intento etiquetado a la lista de intentos de adiviar la palabra
addTry :: String -> String -> [Try] -> [Try]
addTry word correct tries = tries ++ [newTry word correct]

-- inputError: muestra error de entrada, como palabras de longitud incorrecta o uso de letras no permitidas
inputError :: String -> IO ()
inputError e = do { ansiBold;
                    ansiBlinking;
                    ansiSetInkColor Dark Red;
                    ansiEraseLine;
                    putStrLn ("¡Error! "++e);
                    ansiReset;
                    ansiCursorUp 2;
                    ansiEraseLine;
                  }

-- getLineLC: lee una cadena de caracteres y la devuelve convertida a minusculas.
getLineLC :: IO [Char]
getLineLC = do { w <- getLine;
                 return (map toLower w);
               }

-- inputWord: pide al segundo jugador que introduzca la palabra de intento.
inputWord :: Int -> IO [Char]
inputWord l = do { putStr "Teclee su palabra: ";
                   hFlush stdout;
                   w <- getLineLC;
                   if ((length w) /= l)
                      then do { inputError ("Se busca una palabra de "++(show l)++" letras.");
                                inputWord l;
                              }
                      else if (not (validLetters w))
                              then do { inputError "Esa palabra contiene letras no permitidas.";
                                        inputWord l;
                                      }
                              else do { ansiEraseLine;
                                        return w;
                                      }
                 }


-- guessWord: funcion bucle principal del programa.
guessWord :: String -> Int -> [Try] -> Try -> Bool -> Int -> IO ()
guessWord c l trs ls hit nt = do { ansiClearScreen;
                                   ansiBold;
                                   ansiUnderline;
                                   ansiSetInkColor Bright White;
                                   putStrLn ("Adivina una palabra de "++(show l)++" letras\n");
                                   hFlush stdout;
                                   ansiReset;
                                   showAllTries trs ls;
                                   if (not hit)
                                      then do { w <- inputWord l;
                                                let try = newTry w c in do {
                                                  guessWord c l (trs++[try]) (updateLS ls try) (w == c) (nt + 1);
                                              }
                                      }
                                      else putStrLn ("¡Acertó la palabra tras "++(show nt)++" intento"++(if (nt > 1) then "s" else "")++"!");
                            }


-- secretWord: pide al primer jugador la palabra secreta.
secretWord :: IO String
secretWord = do { putStr "Teclee la palabra a adivinar: ";
                  hFlush stdout;
                  w <- getLineLC;
                  if (not (validLetters w))
                     then do { inputError "La palabra a adivinar contiene letras no permitidas.";
                               secretWord;
                             }
                     else return w;
                }


-- FUNCIÓN PRINCIPAL --
main :: IO ()
main = do { hSetBuffering stdin LineBuffering;           -- Permite que la entrada pueda ser editada
            ansiClearScreen;                             -- Borramos la consola
            w <- secretWord;                             -- Pedimos la palabra a adivinar
            guessWord w (length w) [] initialLS False 0; -- Ejecutamos el "bucle" principal
          }

