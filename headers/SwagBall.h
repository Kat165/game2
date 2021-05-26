#ifndef GAME2_SWAGBALL_H
#define GAME2_SWAGBALL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;

enum swagBallType{DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

class SwagBall {
    CircleShape shape;
    int type;
    void initShape(const RenderWindow& window);
public:
    SwagBall(const RenderWindow& window, int type);
    virtual ~SwagBall();

    const CircleShape& getShape() const;
    const int & getType()const;
    void update();
    void render(RenderTarget& target);
};


#endif //GAME2_SWAGBALL_H
