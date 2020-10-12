///*
//@file well.h
//@author	Max Zaloznyi
//@version 1.0
//The interface to my Well class, which contains the class
//definition and lists all of the members of the class
//*/

//#pragma once

//#ifndef TETRIS_WELL
//#define TETRIS_WELL

//#include "tetrimino.h"

//const int BOARD_ROW = 24;
//const int BOARD_COL = 8;

//class Well {
//public:
//    Well();
//    bool tetriminoFit(Tetrimino& piece);
//    bool topReached();
//    void getBoard(char boardOut[BOARD_ROW][BOARD_COL]) const;
//    void addTetriminoToWell(Tetrimino piece);
//    int clearFullRows();
//    void boardDump();
//    bool rowIsFull(int row);
//    void moveRowsDown(int firstRowToMove);

//private:
//    char board[BOARD_ROW][BOARD_COL];
//    int BOARD_ROW;
//    int width;
//};
//#endif

#ifndef WELL_H
#define WELL_H

#include "tetrimino.h"
#include <iostream>

const int BOARD_ROW = 24;
const int BOARD_COL = 8;

class Well
{
private:
    int height;
    int width;
    char board[BOARD_ROW][BOARD_COL];

    // determines if row is full, returns true or false
    bool rowlsFull(int row);
    // moves all rows above firstRowToMove down by 1 row in the well
    // start by moving the lowest row down and work your way up in the well to
    // avoid over-writing good data
    // remember to clear the top row when you’re done
    void moveRowsDown(int firstRowToMove);
public:
    Well();

    /*
    Determines if the given Tetrimino will fit in the well at its location. Recall that
    tetrimino store their location internally -- assume that the location of the Tetrimino
    represents the location of its upper-left squate. All spots on the board that the
    tetrimino will occupy must be inside the well and not at a location already occupied.
    Exception: the tetrimino MAY strick out the top. Keep in mind that only the 1's in a
    Tetrimino have to fit. The 0's in a Tetrimino just represent blank.
    */
    bool tetriminoFit(Tetrimino piece);
    /*
    Changes the Well's board squeares occupied by the given Tetrimino to it's color
    (location of the tetrinimo is still stored in the tetrimino). If the tetrimino stircks out the
    top of the well, that portion of the tetrimino is ignored. Keep in mind that only this 1's
    in a Tetrimino will be translated into colors on the board. The )'s are just blank spots.
    */
    void addTetriminoToWell(Tetrimino t);
    /*
    Finds any rows in the Well that are completely occupied( no squares are ' ' in that
    row), clears the rows(by setting all squares in that row to ' '), and drops all rows
    above the cleared row(s) down one row. Return the number of rows cleared.
    The clearFullRows() method is somewhat complex, so to make the code easier to
    write, debug, and understand, you should implement some of its logic in additonal
    functions.
    */
    int clearFullRows();
    // Returns true if the well’s top row has at least one square occupied. False otherwise.
    bool topReached();
    // Returns a copy of the board to the caller (via a reference parameter)
    void getBoard(char b[][BOARD_COL]);
    // Prints the Well’s board to cout in readable fashion
    void boardDump(bool fited, bool top = false);

};

#endif // WELL_H
