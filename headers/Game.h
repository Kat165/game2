#ifndef GAME2_GAME_H
#define GAME2_GAME_H

#include <vector>
#include <sstream>

#include "Player.h"
#include "SwagBall.h"

using namespace sf;
using namespace std;

class Game
{
    VideoMode videoMode;
    RenderWindow *window;
    Event sfmlEvent;
    Font font;
    Text text;
    Text endGameText;
    Player player;
    vector<SwagBall> swagBalls;
    float spawnTimerMax;
    float spawnTimer;
    int maxSpawnedBalls;
    int points;
    bool endGame;
    void initWndow();
    void initVariables();
    void initFont();
    void initText();
public:
    Game();
    ~Game();
    void update();
    void updateCollision();
    void updateText();
    void updatePlayer();
    void render();
    void renderGui(RenderTarget *target);
    void pollEvents();
    void spawnSwagBalls();
    static int randomizeBallType() ;
    const bool& getEndGame() const;
    bool running() const;
};


#endif //GAME2_GAME_H
