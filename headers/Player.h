#ifndef GAME2_PLAYER_H
#define GAME2_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>

using namespace sf;

class Player {
    RectangleShape shape;
    void initVariable();
    void initShape();
    float movementSpeed;
    int hp;
    int hpMax;

public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();
    const RectangleShape& getShape() const;
    const int & getHp() const;
    const int & getHpMax() const;
    void updateInput();
    void updateWindowBoundsCollision(const RenderTarget *target);
    void update(const RenderTarget *target);
    void render(RenderTarget *target);
    void takeDamage(const int damage);
    void gainHealth(const int health);

};


#endif //GAME2_PLAYER_H
