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
        coin.cpp
        coin.h
        lasso.cpp
        lasso.h
        main.cpp
        MovingObject.cpp
        MovingObject.h
        Vector2D.cpp
        Vector2D.h CoinManager.cpp CoinManager.h bomb.cpp bomb.h)

target_link_libraries(lassoProject sprite X11 )
