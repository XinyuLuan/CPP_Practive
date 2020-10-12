#include "game.h"
#include <iostream>

Game::Game()
{
    window.create( sf::VideoMode(LAYOUT_WINDOW_WIDTH, LAYOUT_WINDOW_HEIGHT),
                   "Tetris 2019", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(30);

    //_____________________________________
    tetriminoInPlay = nullptr;
    tetriminoNext = nullptr;
    if (!font.loadFromFile("RobotoSlab-Regular.ttf"))
    {
        std::cout << "the ttf file loading failed..." << std::endl;
    }
    score = 0;
    curr_Game_State = GameState::TETRIS_SPLASH;
    //______________________________________
}

void Game:: playGame(){
    switch (curr_Game_State) {
        case GameState::TETRIS_SPLASH:
            curr_Game_State = GameState::TETRIS_PLAY;
            processSplash();
            break;
        case GameState::TETRIS_PLAY:
            curr_Game_State = GameState::TETRIS_GAME_OVER;
            processGame();
            break;
        case GameState::TETRIS_GAME_OVER:
            curr_Game_State = GameState::TETRIS_PLAY;
            processGameOver();
            break;
        default:
            break;
    }
}

sf::Color Game::convertToSfmlColor(char c){
    //marked

    if(c == 'I') return sf::Color::Cyan;
    else if(c == 'J') return sf::Color::Blue;
    else if(c == 'L') return sf::Color(255, 100, 0);
    else if(c == 'O') return sf::Color::Yellow;
    else if(c == 'S') return sf::Color::Green;
    else if(c == 'T') return sf::Color::Magenta;
    else if(c == 'Z') return sf::Color::Red;
}

void Game::drawWell(Well w, int top_of_well, int left_of_well, int width_of_block){
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(width_of_block, width_of_block));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);

    char board[BOARD_ROW][BOARD_COL];
    w.getBoard(board);

    for(int i = 0; i < BOARD_ROW; i++ ){
        for(int j = 0; j < BOARD_COL; j++){
            //mark
            if(board[i][j] == ' '){
                rect.setFillColor(sf::Color::White);
            }
            else{
                rect.setFillColor(convertToSfmlColor(board[i][j]));
            }
            rect.setPosition(left_of_well+j*width_of_block, top_of_well+i*width_of_block);
            window.draw(rect);
        }
    }
}

//change t to pointer
void Game::drawTetrimino(Tetrimino* t, int top_of_well, int left_of_well, int width_of_block){
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(width_of_block, width_of_block));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);

    sf::Color temp = convertToSfmlColor(t->getColor());
    rect.setFillColor(temp);

    int grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
    t->getGrid(grid);

    Location curr = t->getLocation();

    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++ ){
        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
            if(grid[i][j] == 1){
                rect.setPosition(left_of_well+(curr.col+j)*width_of_block, top_of_well+(curr.row+i)*width_of_block);
                window.draw(rect);
            }
        }
    }
}

//new
void Game::processSplash(){
    sf::RenderWindow window0;
    window0.create( sf::VideoMode(LAYOUT_WINDOW_WIDTH, LAYOUT_WINDOW_HEIGHT),
                   "Tetris 2019", sf::Style::Titlebar | sf::Style::Close);
    window0.setFramerateLimit(30);

    sf::Text text1("Tetrimino", font);
    text1.setCharacterSize(30);
    text1.setStyle(sf::Text::Regular);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(100, 100);

    sf::Text text2("Press Enter \nto start", font);
    text2.setCharacterSize(30);
    text2.setStyle(sf::Text::Regular);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(100, 300);

    while(window0.isOpen()){
        sf::Event e;
        while(window0.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                window0.clear();
                window0.close();
            }
            if(e.type = sf::Event::KeyPressed){
                if(e.key.code == sf::Keyboard::Enter){
                    window0.clear();
                    window0.close();
                    playGame();
                }
            }
//            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//                sf::Vector2i mousePos = sf::Mouse::getPosition(window0);
//                if(sprite.getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y))){
//                    std::cout << "haha the button works!!" << std::endl;
//                    window0.clear();
//                    window0.close();
//                    playGame();
//                }
//            }
        }
//        window0.draw(sprite);
        window0.draw(text1);
        window0.draw(text2);
        window0.display();
    }
}

void Game::processGame(){
    gameWell = new Well();
    tetriminoInPlay = new Tetrimino(7);
    tetriminoInPlay->setLocation(-1,2);
    tetriminoNext = new Tetrimino(7);
    score = 0;
    int counter = 0;
    bool gameOver = false;

    sf::RectangleShape rect;
    rect.setPosition(40, 300);
    rect.setFillColor(sf::Color::White);
    rect.setSize(sf::Vector2f(100,100));

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.clear();
                window.close();
            }
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Left){
                    tetriminoInPlay->moveLeft();
                    if(!gameWell->tetriminoFit(*tetriminoInPlay))tetriminoInPlay->moveRight();
                }
                if(event.key.code == sf::Keyboard::Right){
                    tetriminoInPlay->moveRight();
                    if(!gameWell->tetriminoFit(*tetriminoInPlay))tetriminoInPlay->moveLeft();
                }
                if(event.key.code == sf::Keyboard::Up){
                    tetriminoInPlay->rotateRight();
                    if(!gameWell->tetriminoFit(*tetriminoInPlay))tetriminoInPlay->rotateLeft();
                }
                if(event.key.code == sf::Keyboard::Down){
                    tetriminoInPlay->moveDown();
                    if(!gameWell->tetriminoFit(*tetriminoInPlay)){
                        tetriminoInPlay->moveUp();
                        gameWell->addTetriminoToWell(*tetriminoInPlay);

                        delete tetriminoInPlay;

                        int num_full_row = gameWell->clearFullRows();
                        score += 10 * num_full_row;

                        drawScore(-1, 10, 10);
                        drawScore(score, 10, 10);

                        gameOver = gameWell->topReached();
                        if(!gameOver){
                            tetriminoInPlay = tetriminoNext;
                            tetriminoInPlay->setLocation(-1,2);
                            tetriminoNext = new Tetrimino(7);
                        }
                        else{
                            window.clear();
                            playGame();
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 80000000; i++){
            counter++;
        }
        counter = 0;
        tetriminoInPlay->moveDown();
        if(!gameWell->tetriminoFit(*tetriminoInPlay)){
            tetriminoInPlay->moveUp();
            gameWell->addTetriminoToWell(*tetriminoInPlay);

            delete tetriminoInPlay;

            int num_full_row = gameWell->clearFullRows();
            score += 10 * num_full_row;

            drawScore(-1, 10, 10);
            drawScore(score, 10, 10);

            gameOver = gameWell->topReached();
            if(!gameOver){
                tetriminoInPlay = tetriminoNext;
                tetriminoInPlay->setLocation(-1,2);
                tetriminoNext = new Tetrimino(7);
            }
            else{
                window.clear();
                playGame();
            }
        }
        window.clear();

        window.draw(rect);
        drawTetrimino(tetriminoNext, 300, 40, BLOCK_SIZE_PIXELS);

        drawWell(*gameWell, LAYOUT_BOARD_TOP, LAYOUT_BOARD_LEFT, BLOCK_SIZE_PIXELS);
        drawTetrimino(tetriminoInPlay, LAYOUT_BOARD_TOP, LAYOUT_BOARD_LEFT, BLOCK_SIZE_PIXELS);

        drawScore(score, 10, 10);

        window.display();
    }
}

bool Game::processGameOver(){
    sf::RenderWindow window2;
    window2.create( sf::VideoMode(LAYOUT_WINDOW_WIDTH, LAYOUT_WINDOW_HEIGHT),
                   "Tetris 2019", sf::Style::Titlebar | sf::Style::Close);
    window2.setFramerateLimit(30);

    sf::Text lost("You Lose! \nPlay Again?", font);
    lost.setCharacterSize(30);
    lost.setStyle(sf::Text::Regular);
    lost.setFillColor(sf::Color::White);
    lost.setPosition(10, 100);

    // Declare and load a texture
    sf::Texture texture_Yes;
    texture_Yes.loadFromFile("Yes.png");
    // Create a sprite
    sf::Sprite sprite_Yes;
    sprite_Yes.setTexture(texture_Yes);
    sprite_Yes.setTextureRect(sf::IntRect(10, 10, 60, 40));
    sprite_Yes.setColor(sf::Color(255, 255, 255, 200));
    sprite_Yes.setPosition(10, 200);

    sf::Texture texture_No;
    texture_No.loadFromFile("No.png");
    // Create a sprite
    sf::Sprite sprite_No;
    sprite_No.setTexture(texture_No);
    sprite_No.setTextureRect(sf::IntRect(10, 10, 60, 40));
    sprite_No.setColor(sf::Color(255, 255, 255, 200));
    sprite_No.setPosition(100, 208);

    while(window2.isOpen()){
        sf::Event e;
        while(window2.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                window2.clear();
                window2.close();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window2);
                if(sprite_Yes.getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y))){
//                    std::cout << "haha the |Yes| button works!!" << std::endl;
                    window2.clear();
                    window2.close();
                    playGame();
                }
                if(sprite_No.getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y))){
                    window2.clear();
                    window2.close();
                    processSplash();
                }
            }
            if(e.type = sf::Event::KeyPressed){
                if(e.key.code == sf::Keyboard::Enter){
                    window2.clear();
                    window2.close();
                    playGame();
                }
            }
        }
        window2.draw(lost);
        window2.draw(sprite_Yes);
        window2.draw(sprite_No);

        window2.display();
    }
}

void Game::drawScore(int s, int top, int left){
    std::string score_string;
    if(s == 0) score_string = "0";
    else if(s == -1) score_string = "";
    else{
        while(s!=0){
            score_string.push_back(s%10+'0');
            s/=10;
        }
        reverse(score_string.begin(), score_string.end());
    }
    score_string = "Score: \n\t\t\t" + score_string;

    sf::Text score_text(score_string, font);
    score_text.setCharacterSize(30);
    score_text.setStyle(sf::Text::Regular);
    score_text.setFillColor(sf::Color::White);
    score_text.setPosition(top, left);

    sf::RectangleShape rect;
    rect.setPosition(top+70,left+40);
    rect.setFillColor(sf::Color::Blue);
    rect.setSize(sf::Vector2f(100,50));

    sf::Text next("Next", font);
    next.setCharacterSize(30);
    next.setStyle(sf::Text::Regular);
    next.setFillColor(sf::Color::White);
    next.setPosition(20, 250);

    window.draw(rect);
    window.draw(score_text);
    window.draw(next);
}
