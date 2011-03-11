Marcus Höjvall
Joakim Berglund

_Balls of steel_
Spelet går ut på att hålla sig uppe och inte ramla ner nedanför spelplanen, håll dig uppe genom att studsa på de olika platformarna.
Spelare 1: Vänster- och högerpiltangent
Spelare 2: A och D

Filer i namespacet Game tillhör spelet:
Dot.*
Square.*
MovingSquare.*
GameGlobals.*

Filer i namespacet GameEng tillhör spelmotorn:
GameEngine.*
Image.*
Sprite.*
SpriteInput.*
Timer.*

Alla filer ligger i root mappen.

För att slippa skriva själv: g++ Image.cpp Sprite.cpp GameEngine.cpp Timer.cpp Globals.cpp Dot.cpp Square.cpp BallsOfSteel.cpp GameGlobals.cpp -lSDL -lSDL_image -o run
