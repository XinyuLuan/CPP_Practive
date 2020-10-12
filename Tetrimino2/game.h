#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <time.h>
#include "tetrimino.h"
#include "well.h"

const int LAYOUT_WINDOW_WIDTH = 400;
const int LAYOUT_WINDOW_HEIGHT = 500;
const int LAYOUT_BOARD_TOP = 10;
const int LAYOUT_BOARD_LEFT = 200;
const int BLOCK_SIZE_PIXELS = 20;

//new
enum class GameState { TETRIS_SPLASH, TETRIS_PLAY, TETRIS_GAME_OVER };

class Game
{
public:
    Game();
    void playGame();
private:
    sf::Color convertToSfmlColor(char c);
    void drawWell(Well w, int top_of_well, int left_of_well, int width_of_block);
    void drawTetrimino(Tetrimino* t, int top_of_well, int left_of_well, int width_of_block);

    //new
    void processSplash();
    void processGame();
    bool processGameOver();
    void drawScore(int s, int top, int left);

    sf::RenderWindow window;

    sf::Font font;
    Well* gameWell;
    Tetrimino* tetriminoInPlay;
    Tetrimino* tetriminoNext;
    int score;

    GameState curr_Game_State;
};

#endif // GAME_H
