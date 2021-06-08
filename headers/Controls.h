#ifndef GAME2_CONTROLS_H
#define GAME2_CONTROLS_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;
using namespace std;

class Controls {
    RenderWindow* window;
    Font font;
    Text controlsText;
    void initWindow();
    void initCText();
public:
    Controls();
    ~Controls();
    void run();
    void updatePollEvents();
    void udpateCText();
    void update();
    void renderCTexT();
    void render();
};
#endif //GAME2_CONTROLS_H
