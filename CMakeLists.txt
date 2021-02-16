cmake_minimum_required(VERSION 3.17)
project(lassoProject)

set(CMAKE_CXX_STANDARD 11)
find_package(X11 REQUIRED)

include_directories(.)
include_directories(/usr/include/X11)

include_directories(/home/sankalp/simplecpp/include)





link_directories(/usr/X11R6/lib)

link_directories(/home/sankalp/simplecpp/lib)


add_executable(lassoProject
        GameObjects/coin/coin.cpp
        GameObjects/coin/coin.h
        GameObjects/lasso/lasso.cpp
        GameObjects/lasso/lasso.h
        main.cpp
        GameObjects/MO/MovingObject.cpp
        GameObjects/MO/MovingObject.h
        Misc/Vector2D/Vector2D.cpp
        Misc/Vector2D/Vector2D.h Manager/CoinManager.cpp Manager/CoinManager.h GameObjects/bomb/bomb.cpp GameObjects/bomb/bomb.h Manager/BombManager.cpp Manager/BombManager.h GameHandlers/Engine/GameEngine.cpp GameHandlers/Engine/GameEngine.h GameHandlers/Levels/GameLevel.cpp GameHandlers/Levels/GameLevel.h Misc/GameConstants.h GameHandlers/State/GameState.cpp GameHandlers/State/GameState.h UI/PrelimRenderer/PrelimLevelRender.cpp UI/PrelimRenderer/PrelimLevelRender.h UI/Util/UIUtil.cpp UI/Util/UIUtil.h UI/Heart/HeartUI.cpp UI/Heart/HeartUI.h Misc/Magnet/Magnet.cpp Misc/Magnet/Magnet.h UI/Coin/CoinUI.cpp UI/Coin/CoinUI.h UI/Key/KeyUI.cpp UI/Key/KeyUI.h GameObjects/MagnetGiver/MagnetGiver.cpp GameObjects/MagnetGiver/MagnetGiver.h Misc/Magnet/Sprite/MagnetSprite.cpp Misc/Magnet/Sprite/MagnetSprite.h UI/TimeLeft/TimeUI.cpp UI/TimeLeft/TimeUI.h GameHandlers/LevelClass/Level1.cpp GameHandlers/LevelClass/Level1.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

target_link_libraries(lassoProject sprite X11)
