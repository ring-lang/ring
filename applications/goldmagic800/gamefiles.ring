# Gold Magic 800 3D Game
# 2018, Etqan Company

load "gameerror.ring"
load "gamebase.ring"
load "gamedata.ring"
load "gamecamera.ring"
load "gameresources.ring"
load "gamedraw.ring"
load "gamelevel.ring"
load "gameplayer.ring"
load "gamesound.ring"
load "gamemouse.ring"
load "gamescreen.ring"
load "gamelogo.ring"
load "gamestory.ring"
load "gamehowtoplay.ring"
load "gamemainmenu.ring"
load "gameselectlevel.ring"
load "gameengine.ring"


for cClass in [
	:GameResources,
	:GameDraw,
	:GameMouse,
	:GameLevel,
	:GamePlayer,
	:GameScreen,
	:GameLogo,
	:GameStory,
	:GameHowToPlay,
	:GameMainMenu,
	:GameSelectLevel
]
	mergemethods(:GameEngine,cClass)
next

