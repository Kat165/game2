//
// Created by kasia on 26.05.2021.
//

#include "../headers/SwagBall.h"

SwagBall::SwagBall(const RenderWindow& window, int type) : type(type) {
    this->initShape(window);
}

SwagBall::~SwagBall() = default;

void SwagBall::initShape(const RenderWindow& window) {
    this->shape.setRadius(static_cast<float>(rand()%10 + 10));
    Color color;
    switch (this->type) {
        case DEFAULT:
            color = Color(rand()%255 + 1, rand()%255 + 1, rand()%255 + 1);
            break;
        case DAMAGING:
            color = Color::Red;
            break;
        case HEALING:
            color = Color::Green;
            break;

        
    }
    Color color1(rand()%255 + 1, rand()%255 + 1, rand()%255 + 1);
    this->shape.setFillColor(color);
    this->shape.setOutlineColor(color1);
    this->shape.setOutlineThickness(rand()%10 + 5);
    this->shape.setPosition(Vector2f(
            static_cast<float>(rand()%window.getSize().x - this->shape.getGlobalBounds().width),
            static_cast<float>(rand()%window.getSize().y - this->shape.getGlobalBounds().height)));
}

void SwagBall::render(RenderTarget &target) {
    target.draw(this->shape);

}

const CircleShape &SwagBall::getShape() const {
    return this->shape;
}

const int &SwagBall::getType() const {
    return this->type;
}
