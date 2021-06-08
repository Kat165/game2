#include "../headers/Player.h"

Player::Player(float x,float y) {
    this->shape.setPosition(x, y);
    this->initVariable();
    this->initShape();
}

Player::~Player() = default;

void Player::initVariable() {
    this->movementSpeed = 5.f;
    this->hpMax = 10;
    this->hp = hpMax;
}

void Player::initShape() {
    this->shape.setFillColor(Color::Green);
    this->shape.setSize(Vector2f(50.f,50.f));
}

void Player::update(const RenderTarget* target) {
    this->updateInput();
    this->updateWindowBoundsCollision(target);
}

void Player::render(RenderTarget *target) {
    target->draw(this->shape);
}

void Player::updateInput() {
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        this->shape.move(-this->movementSpeed,0.f);
    }
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        this->shape.move(this->movementSpeed,0.f);
    }

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        this->shape.move(0.f,-this->movementSpeed);
    }
    else if (Keyboard::isKeyPressed(Keyboard::S))
    {
        this->shape.move(0.f,this->movementSpeed);
    }
}

void Player::updateWindowBoundsCollision(const RenderTarget *target) {

    FloatRect playerBounds = this->shape.getGlobalBounds();
    //player left
    if (this->shape.getGlobalBounds().left <= 0.f)
        this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
    //right
    if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
        this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width,this->shape.getGlobalBounds().top);
    //player top
    if (this->shape.getGlobalBounds().top <= 0.f)
        this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
    //bottom
    if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
        this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);

}

const RectangleShape &Player::getShape() const {
    return this->shape;
}

const int &Player::getHp() const {
    return this->hp;
}

const int &Player::getHpMax() const {
    return this->hpMax;
}

void Player::takeDamage(const int damage) {
    if (this->hp > 0)
        this->hp -= damage;
    if (this->hp < 0)
        this->hp = 0;
}

void Player::gainHealth(const int health) {
    if (this->hp < this->hpMax)
        this->hp += health;
    if (this->hp > this->hpMax)
        this->hp = hpMax;

}
