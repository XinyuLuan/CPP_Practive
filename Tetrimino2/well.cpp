///*
//@file well.cpp
//@author	Max Zaloznyi
//@version 1.0
//Class implementation of Well
//*/

//#include <iostream>
//#include <iomanip>
//#include "well.h"
//#include "tetrimino.h"

////================================================================
//// Function:   Well
//// Description: Well constructor for Well class
////================================================================

//Well::Well() {
//    height = BOARD_ROW;
//    width = BOARD_COL;

//    for (int row = 0; row < height; row++)
//        for (int col = 0; col < width; col++)
//            board[row][col] = ' ';
//}

////================================================================
//// Function:   tetriminoFit
//// Description: Checks if the tetrimino that is passsed fits in the
////  board
//// Arguments:
////	Tetrimino& piece - piece to check
//// Return value:
////	true if it can fit
////  false if it cannot fit
////================================================================
//bool Well::tetriminoFit(Tetrimino& piece) {
//    Location locationCheck;
//    locationCheck = piece.getLocation();

//    int localGrid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
//    piece.getGrid(localGrid);

//    //check left, right, under
//    for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
//        for (int col = 0; col < TETRIMINO_GRID_SIZE; col++)
//            if (localGrid[row][col] == 1) {
//                if (locationCheck.col + col < 0)
//                    return false;
//                if (locationCheck.col + col > BOARD_COL - 1)
//                    return false;
//                if (locationCheck.row + row > BOARD_ROW - 1)
//                    return false;
//                if (board[locationCheck.row + row][locationCheck.col + col] != ' ')
//                    return false;
//            }
//    }
//    return true;
//};


////================================================================
//// Function: topReached
//// Description: Checks if the top row is reached
//// Return value:
////	true if the top has been reached
////  false if the top has not been reached
////================================================================
//bool Well::topReached() {
//    for (int i = 0; i < BOARD_COL; i++) {
//        if (board[0][i] != ' ')
//            return true;
//    }
//    return false;
//};

////================================================================
//// Function:   getBoard
//// Description: returns a copy of the board
//// Arguments:
//// boardOut - board
////================================================================

//void Well::getBoard(char boardOut[BOARD_ROW][BOARD_COL]) const {
//    for (int row = 0; row < BOARD_ROW; row++)
//        for (int col = 0; col < BOARD_COL; col++)
//            boardOut[row][col] = board[row][col];
//};

////================================================================
//// Function: addTetriminoToWell
//// Description: adds the tetrimino piece to the well and changes its color
//// Arguments:
////	piece - tetrimino piece being added to the well
////================================================================

//void Well::addTetriminoToWell(Tetrimino piece) {
//    int localGrid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
//    piece.getGrid(localGrid);

//    Location locationToAdd;
//    locationToAdd = piece.getLocation();


//    char localColor;
//    localColor = piece.getColor();

//    if (tetriminoFit(piece) == true) {
//        for (int row = 0; row < TETRIMINO_GRID_SIZE; row++)
//            for (int col = 0; col < TETRIMINO_GRID_SIZE; col++)
//                if (localGrid[row][col] == 1)
//                    board[locationToAdd.row + row][locationToAdd.col + col] = localColor;
//    }
//};

////================================================================
//// Function: clearFullRows
//// Description: Clears the full rows
//// Return value:
////	the total number of rows cleared
////================================================================
//int Well::clearFullRows() {
//    int totalRows = 0;

//    for (int row = 0; row < BOARD_ROW; row++) {
//        if (rowIsFull(row))
//            moveRowsDown(row);
//        totalRows++;
//    }
//    return totalRows;
//};

////================================================================
//// Function: boardDump
//// Description: prints the board out
////================================================================

//void Well::boardDump() {

//    for (int row = 0; row < BOARD_ROW; row++) {
//        for (int col = 0; col < BOARD_COL; col++) {
//            if (board[row][col] != ' ')
//                std::cout << std::setw(1) << "1";
//            else
//                std::cout << std::setw(1) << "0";
//        }
//        std::cout << std::endl;
//    }
//};

////================================================================
//// Function: rowIsFull
//// Description: Checks if the row is full
//// Arguments:
////	row (I) - row to be checked
//// Return value:
////	true if the row is full
////  false if the row is not full
////================================================================

//bool Well::rowIsFull(int row) {
//    int counter = BOARD_COL;

//    for (int col = 0; col < BOARD_COL; col++) {
//        if (board[row][col] != ' ')
//            counter--;
//    }

//    if (counter == 0)
//        return true;
//    else
//        return false;
//};

////================================================================
//// Function: moveRowsDown
//// Description: moves rows down
//// Arguments:
////	firstRowToMove (I) - first row to start moving down
////================================================================

//void Well::moveRowsDown(int firstRowToMove) {
//    for (int row = firstRowToMove; row >= 0; row--)
//        for (int col = 0; col < BOARD_COL; col++)
//            board[row][col] = board[row - 1][col];

//    for (int col = 0; col < BOARD_COL; col++)
//        board[0][col] = ' ';
//};

#include "well.h"
#include <iostream>
#include <iomanip>

Well::Well()
{
    height = BOARD_ROW;
    width = BOARD_COL;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            board[i][j] = ' ';
        }
    }
}

// determines if row is full, returns true or false
bool Well::rowlsFull(int row){
    for(int j = 0; j < BOARD_COL; j++){
        if(board[row][j] == ' ') return false;
    }
    return true;
}

// moves all rows above firstRowToMove down by 1 row in the well
// start by moving the lowest row down and work your way up in the well to
// avoid over-writing good data
// remember to clear the top row when you’re done
void Well::moveRowsDown(int firstRowToMove){
    if(firstRowToMove >= BOARD_ROW) return;
    for(int i = firstRowToMove; i >= 0; i--){
        for(int j = 0; j < BOARD_COL; j++){
            board[i+1][j] = board[i][j];
        }
    }
    for(int j = 0; j < BOARD_COL; j++){
        board[0][j] = ' ';
    }
}

/*
Determines if the given Tetrimino will fit in the well at its location. Recall that
tetrimino store their location internally -- assume that the location of the Tetrimino
represents the location of its upper-left squate. All spots on the board that the
tetrimino will occupy must be inside the well and not at a location already occupied.
Exception: the tetrimino MAY strick out the top. Keep in mind that only the 1's in a
Tetrimino have to fit. The 0's in a Tetrimino just represent blank.
*/
bool Well::tetriminoFit(Tetrimino piece){
    Location locationCheck;
    locationCheck = piece.getLocation();

    int localGrid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
    piece.getGrid(localGrid);

    //check left, right, under
    for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
        for (int col = 0; col < TETRIMINO_GRID_SIZE; col++)
            if (localGrid[row][col] == 1) {
                if (locationCheck.col + col < 0)
                    return false;
                if (locationCheck.col + col > BOARD_COL - 1)
                    return false;
                if (locationCheck.row + row > BOARD_ROW - 1)
                    return false;
                if (board[locationCheck.row + row][locationCheck.col + col] != ' ')
                    return false;
            }
    }
    return true;
//    int t_grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
//    t.getGrid(t_grid);
//    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
//        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
//            if(t_grid[i][j] == 1){
//                if( t.getLocation().row+i >= BOARD_ROW
//                        || t.getLocation().col+j < 0 || t.getLocation().col+j >= BOARD_COL ){
//                    return false;
//                }
//                else if(t.getLocation().row+i >= 0
////                        && t.location.col+j >= 0 && t.location.row+i < BOARD_ROW && t.location.col < BOARD_COL
//                        && board[t.getLocation().row+i][t.getLocation().col+j] != ' '){
//                    return false;
//                }
//            }
//        }
//    }
//    return true;
}

/*
Changes the Well's board squeares occupied by the given Tetrimino to it's color
(location of the tetrinimo is still stored in the tetrimino). If the tetrimino stircks out the
top of the well, that portion of the tetrimino is ignored. Keep in mind that only this 1's
in a Tetrimino will be translated into colors on the board. The )'s are just blank spots.
*/
void Well::addTetriminoToWell(Tetrimino t){
    int t_grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
    t.getGrid(t_grid);

    for(int i = 0; i < TETRIMINO_GRID_SIZE; i++){
        for(int j = 0; j < TETRIMINO_GRID_SIZE; j++){
            if(t_grid[i][j] == 1 && t.getLocation().row+i >= 0){
                board[t.getLocation().row+i][t.getLocation().col+j] = t.getColor();
            }
        }
    }
}

/*
Finds any rows in the Well that are completely occupied( no squares are ' ' in that
row), clears the rows(by setting all squares in that row to ' '), and drops all rows
above the cleared row(s) down one row. Return the number of rows cleared.
The clearFullRows() method is somewhat complex, so to make the code easier to
write, debug, and understand, you should implement some of its logic in additonal
functions.
*/
int Well::clearFullRows(){
    int deletedRow = 0;
    for(int i = 0; i < BOARD_ROW; i++){
        if(rowlsFull(i) == true){
            moveRowsDown(i-1);
            deletedRow++;
        }
    }
    boardDump(true);
    return deletedRow;
}

// Returns true if the well’s top row has at least one square occupied. False otherwise.
bool Well::topReached(){
    for(int i = 0; i < width; i++){
        if(board[0][i] != ' ') return true;
    }
    return false;
}

// Returns a copy of the board to the caller (via a reference parameter)
void Well::getBoard(char b[][BOARD_COL]){
    for(int i = 0; i < BOARD_ROW; i++){
        for(int j = 0; j < BOARD_COL; j++){
            b[i][j] = board[i][j];
        }
    }
}

// Prints the Well’s board to cout in readable fashion
void Well::boardDump(bool fited, bool top){
    if(fited && !top){
        for (int row = 0; row < BOARD_ROW; row++) {
                for (int col = 0; col < BOARD_COL; col++) {
                    if (board[row][col] != ' ')
                        std::cout << std::setw(1) << "1";
                    else
                        std::cout << std::setw(1) << "0";
                }
                std::cout << std::endl;
            }
    }
    else if(!fited){
        std::cout << "The new tetrimino can not fit" << std::endl;
    }
    else if(top){
        std::cout << "The top row has at least one square occupied" << std::endl;
    }

    std::cout << std::endl;
}

