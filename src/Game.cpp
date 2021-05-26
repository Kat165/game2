#include "../headers/Game.h"

Game::Game() {
    this->initWndow();
    this->initVariables();
    this->initFont();
    this->initText();
}

Game::~Game() {
    delete this->window;

}

void Game::initVariables() {
    this->endGame = false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxSpawnedBalls = 10;
    this->points = 0;

}

void Game::initWndow() {
    this->videoMode = VideoMode(800, 600);
    this->window = new RenderWindow(this->videoMode, "Game 2", Style::Close | Style::Titlebar);
    this->window->setFramerateLimit(60);

}

bool Game::running() const {
    return this->window->isOpen();
}

void Game::update() {
    this->pollEvents();
    if (!this->endGame)
    {
        this->spawnSwagBalls();
        this->updatePlayer();
        this->updateCollision();
        this->updateText();
    }

}

void Game::render() {
    this->window->clear();
    this->player.render(this->window);
    for(auto i : this->swagBalls)
    {
        i.render(*this->window);
    }
    this->renderGui(this->window);

    if (this->endGame)
    {
        this->window->draw(this->endGameText);
    }

    this->window->display();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->sfmlEvent))
    {
        switch (this->sfmlEvent.type) {
            case Event::Closed:
                this->window->close();
                break;

            case Event::KeyPressed:
                if (this->sfmlEvent.key.code == Keyboard::Escape)
                    this->window->close();
                break;
            default:
                break;
        }
    }

}

void Game::spawnSwagBalls() {
    if(this->spawnTimer < this->spawnTimerMax)
        this->spawnTimer += 1.f;
    else
    {
        if(this->swagBalls.size()<maxSpawnedBalls){
            this->swagBalls.emplace_back(*this->window, this->randomizeBallType());
            this->spawnTimer = 0.f;
        }
    }

}

void Game::updateCollision() {
    for(size_t i = 0; i < this->swagBalls.size(); ++i)
    {
        if(this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
        {
            switch (this->swagBalls[i].getType()) {
                case swagBallType::DEFAULT:
                    this->points++;
                    break;
                case swagBallType::DAMAGING:
                    this->player.takeDamage(1);
                    break;
                case swagBallType::HEALING:
                    this->player.gainHealth(1);
                    break;

                
            }
            this->swagBalls.erase(this->swagBalls.begin() + i);

        }
    }

}

void Game::initFont() {
    if (!this->font.loadFromFile(R"(C:\Users\kasia\Documents\Fonts\Dosis-Light.ttf)"))
    {
        cout<<"Failed to load font";
    }

}

void Game::initText() {
    this->text.setFont(this->font);
    this->text.setCharacterSize(24);
    this->text.setFillColor(Color::White);
    this->text.setString("NONE");

    this->endGameText.setFont(this->font);
    this->endGameText.setCharacterSize(32);
    this->endGameText.setFillColor(Color::Red);
    this->endGameText.setPosition(Vector2f(200,300));
    this->endGameText.setString("YOU ARE DEAD, EXIT THE GAME");
}

void Game::renderGui(RenderTarget *target) {
    target->draw(this->text);
}

void Game::updateText() {
    stringstream ss;
    ss<<"Points: "<<this->points<<"\n"<<"Health: "<<this->player.getHp()<<" / "<<this->player.getHpMax()<<"\n";
    this->text.setString(ss.str());

}

int Game::randomizeBallType() {

    int type = swagBallType::DEFAULT;
    int randValue = rand()&100 + 1;
    if (randValue > 60 && randValue <= 80)
        type = swagBallType::DAMAGING;
    if (randValue > 80 && randValue <= 100)
        type = swagBallType::HEALING;

    return type;

}

const bool &Game::getEndGame() const {
    return this->endGame;
}

void Game::updatePlayer() {
    this->player.update(this->window);
    if (this->player.getHp() <= 0)
        this->endGame = true;

}
