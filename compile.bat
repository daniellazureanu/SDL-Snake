g++ -Isrc/include -Lsrc/lib -o Snake snake.cpp renderwindow.cpp entity.cpp -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image