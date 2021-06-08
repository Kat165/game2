#include <iostream>
#include "headers/Game.h"
#include "headers/Controls.h"

using namespace sf;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Controls controls;
    controls.run();

    Game game;

    while (game.running() /*&& !game.getEndGame()*/)
    {
        game.update();
        game.render();
    }

    return 0;
}
