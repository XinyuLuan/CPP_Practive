#include "tetrimino.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <ctime>
using namespace std;

//random number generator
int randNum()
{
        int randNum = 0;
        int high = 6;
        int low = 0;
        srand(static_cast<unsigned int>(time(NULL)));
//        srand (time(NULL));
        int rm = rand();
        randNum = rm % 7;

        cout << "The randNum is: " << rm << "    " << randNum << endl;
        return randNum;
}

Tetrimino::Tetrimino(int type)
{
    location.row = 0;
    location.col = 0;
    if(type >= 7 || type < 0){
        srand(time(NULL));
        std::cout <<rand() << std::endl;
        std::cout <<rand() << std::endl;
        std::cout <<rand() << std::endl;
        int r = rand() % 7;
        defineGridandColor(r);
    }
    else{
        defineGridandColor(type);
    }
};
/**




//        //check to see if type is 0-6, if not set to 7
//        if (type < 0 || type >= 7)
//        {
//            type = randNum();
//        }

//        cout << "There is the type!! " << type << endl;
//        //set associated type to a tetrimino
//        if (type == 0)
//        {
//                for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
//                        for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
//                                grid[i][j] = g_collection[type][i][j];
//                        }
//                }
//                //set color to teal
//                color = 't';

//                //initialize starting position
//                location.row = 0;
//                location.col = 0;
//        }
//        else if (type == 1)
//        {
//        //set grid to j tetro
//        for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
//                for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
//                        grid[i][j] = g_collection[type][i][j];
//                }
//        }
//                //set color to blue
//                color = 'b';

//                //initialize starting position
//                location.row = 0;
//                location.col = 0;
//        }
//        else if (type == 2)
//        {
//                //set grid to L tetro
//                for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
//                        for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
//                                grid[i][j] = g_collection[type][i][j];
//                        }
//                }
//                //set color to orange
//                color = 'o';

//                //initialize starting position
//                location.row = 0;
//                location.col = 0;
//        }
//        else if (type == 3)
//        {
//                //set grid to o tetro
//                for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
//                        for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
//                                grid[i][j] = g_collection[type][i][j];
//                        }
//                }
//                //set color to yellow
//                color = 'y';

//                //initialize starting position
//                location.row = 0;
//                location.col = 0;
//        }
//        else if (type == 4)
//        {
//                //set grid to s tetro
//                for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
//                        for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
//                                grid[i][j] = g_collection[type][i][j];
//                        }
//                }
//                //set color to green
//                color = 'g';

//                //initialize starting position
//                location.row = 0;
//                location.col = 0;
//        }
//        else if (type == 5)
//        {
//                //set grid to T tetro
//                for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
//                        for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
//                                grid[i][j] = g_collection[type][i][j];
//                        }
//                }
//                //set color to purple
//                color = 'p';

//                //initialize starting position
//                location.row = 0;
//                location.col = 0;
//        }
//        else if (type == 6)
//        {
//                //set grid to z tetro
//                for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
//                        for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
//                                grid[i][j] = g_collection[type][i][j];
//                        }
//                }
//                //set color to red
//                color = 'r';

//                //initialize starting position
//                location.row = 0;
//                location.col = 0;
//        }
    */

//accessors
char Tetrimino::getColor()
{
        return color;
}
Location Tetrimino::getLocation()
{
        return location;
}
void Tetrimino::getGrid(int gridOut[][TETRIMINO_GRID_SIZE])
{
//        gridOut = grid;
    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
            gridOut[i][j] = grid[i][j];
        }
    }
}

//mutators
void Tetrimino::setLocation(Location newLocation) {
        location.row = newLocation.row;
        location.col = newLocation.col;
}

void Tetrimino::setLocation(int row, int col) {
        location.row = row;
        location.col = col;
}

void Tetrimino::rotateLeft() {
        int res[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
        for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
                for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
                        res[TETRIMINO_GRID_SIZE - 1-j][i] = grid[i][j];
                }
        }
        for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
                for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
                        grid[i][j] = res[i][j];
                }
        }
}

void Tetrimino::rotateRight() {
        int res[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
        for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
                for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
                        res[j][TETRIMINO_GRID_SIZE - 1 - i] = grid[i][j];
                }
        }
        for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
                for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
                        grid[i][j] = res[i][j];
                }
        }
}

void Tetrimino::moveLeft() {
        location.col--;
}

void Tetrimino::moveRight() {
        location.col++;
}

void Tetrimino::moveDown() {
        location.row++;
}

void Tetrimino::moveUp() {
        location.row--;
}


// others
void Tetrimino::printGrid() {
        //loop goes through each row
        for (int row = 0; row < TETRIMINO_GRID_SIZE; row++)
        {
                //goes through each col of current row
                for (int column = 0; column < TETRIMINO_GRID_SIZE; column++)
                {
                        cout << grid[row][column] << " ";
                }
                //new line between rows
                cout << endl;
        }
}

void Tetrimino::dataDump() {
        //loop goes through each row
        for (int row = 0; row < TETRIMINO_GRID_SIZE; row++)
        {
                //goes through each col of current row
                for (int column = 0; column < TETRIMINO_GRID_SIZE; column++)
                {
                        cout << grid[row][column] << " ";
                }
                //new line between rows
                cout << endl;
        }
        cout << "color: " << color << endl;
        cout << "location: (" << location.row << "," << location.col << ")" << endl;
}

void Tetrimino::defineGridandColor(int type){
    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
            grid[i][j] = g_collection[type][i][j];
        }
    }
    color = color_collection[type];
}

//int main(int argc, char *argv[])
//{
//        Tetrimino test(7);
//        test.dataDump();

//        char c = test.getColor();
//        test.dataDump();

//        test.getLocation();
//        test.dataDump();

//        int g[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
//        test.getGrid(g);
//        test.dataDump();

//        test.setLocation(100, 101);
//        test.dataDump();
//        return 0;
//}






//#include "tetrimino.h"
//#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
//#include <iostream>
//#include <cstdlib>


//Tetrimino::Tetrimino(int type)
//{
//    location.row = 0;
//    location.col = 0;
//    if(type == 7){
//        /* initialize random seed: */
//        srand (time(NULL));
//        std::cout <<rand() << std::endl;
//        std::cout <<rand() << std::endl;
//        std::cout <<rand() << std::endl;

//        int r = rand() % 7;
//        std::cout << "---- " << r << " -----" << std::endl;
//        // rand() function return a integer from 0 to RAND_MAX
//        defineGridandColor(r);
//    }
//    else defineGridandColor(type);
//}

////// print array
//void Tetrimino::printArr(){
//    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
//        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
//            std::cout << grid[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//}

////--------------------------------------------
////accessors
//// returns the color of the tetrimino object
//char Tetrimino::getColor(){
//    return color;
//}
//// return the location of the Tetrimino
//Location Tetrimino::getLocation(){
//    return location;
//}
//// return the location of the Tetrimino
//void Tetrimino::getGrid(int gridOut[][TETRIMINO_GRID_SIZE]){
//    gridOut = grid;
//    // I need to test if this part works: if the gridOut will updated
//}

////--------------------------------------------
////mutators
//// modify location.row and location.col
//void Tetrimino::setLocation(Location newLocation){
//    location.row = newLocation.row;
//    location.col = newLocation.col;
//}

//// modify location.row and location.col
//void Tetrimino::setLocation(int row, int col){
//    location.row = row;
//    location.col = col;
//}

//void Tetrimino::rotateLeft(){
//    int res[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
//    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
//        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
//            res[TETRIMINO_GRID_SIZE-1-j][i] = grid[i][j];
//        }
//    }
//    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
//        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
//            grid[i][j] = res[i][j];
//        }
//    }
//}
//void Tetrimino::rotateRight(){
//    int res[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
//    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
//        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
//            res[j][TETRIMINO_GRID_SIZE-1-i] = grid[i][j];
//        }
//    }
//    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
//        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
//            grid[i][j] = res[i][j];
//        }
//    }
//}
//void Tetrimino::moveLeft(){
//    location.col--;
//}
//void Tetrimino::moveRight(){
//    location.col++;
//}
//void Tetrimino::moveDown(){
//    location.row++;
//}
//void Tetrimino::moveUp(){
//    location.row--;
//}

////--------------------------------------------
////others
//// print out the value of grid, color, and location
//void Tetrimino::dataDump(){
//    //grid
//    std::cout << "grid: " << std::endl;
//    printArr();
//    //color
//    std::cout << "color: " << color << std::endl;
//    //location
//    std::cout << "location: (" << location.row << ","
//              << location.col <<")"<< std::endl<< std::endl;
//}

//////function for defineGrid
//void Tetrimino::defineGridandColor(int type){
//    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
//        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
//            grid[i][j] = g_collection[type][i][j];
//        }
//    }
//    color = color_collection[type];
////    if(type == 0)
////        int g[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE]
////                = {{0,0,0,0},{0,1,0,0},{0,1,1,1},{0,0,0,0}};
////    else if(type == 1)
////        int g[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE]
////                = {{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}};
////    else if(type == 2)
////        int g[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE]
////                = {{0,0,0,0},{0,0,1,0},{1,1,1,0},{0,0,0,0}};
////    else if(type == 3)
////        int g[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE]
////                = {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}};
////    else if(type == 4)
////        int g[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE]
////                = {{0,0,0,0},{0,0,1,1},{0,1,1,0},{0,0,0,0}};
////    else if(type == 5)
////        int g[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE]
////                = {{0,0,0,0},{0,0,1,0},{0,1,1,1},{0,0,0,0}};
////    else if(type == 6)
////        int g[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE]
////                = {{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}};
//}
