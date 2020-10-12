#include <iostream>
//#include "tetrimino.h"
//#include "well.h"
#include "game.h"

using namespace std;

//void printSomething(Well &w, Tetrimino t);

int main()
{
    Game game;

    game.playGame();

     return 0;
}

//void printSomething(Well& w, Tetrimino t){
//    bool b = w.tetriminoFit(t);
//    if(b){
//        cout << "the result is true" << endl;
//    }
//    else
//        cout << "The result is false" << endl;

//    if(b){
//        w.addTetriminoToWell(t);
//        w.boardDump(true);
//    }
//}

/*
        Tetrimino test(7);
        test.dataDump();

        char c = test.getColor();
        test.dataDump();

        test.getLocation();
        test.dataDump();

        int g[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
        test.getGrid(g);
        test.dataDump();

        Location newLocation;
        newLocation.row = 1000;
        newLocation.col = 1001;
        test.setLocation(newLocation);
        test.dataDump();

        test.setLocation(100, 101);
        test.dataDump();

        test.rotateLeft();
        test.dataDump();

        test.rotateRight();
        test.dataDump();

        test.moveLeft();
        test.dataDump();

        test.moveRight();
        test.dataDump();

        test.moveDown();
        test.dataDump();

        test.moveUp();
        test.dataDump();





            Assignment 3
        Well test;
        test.boardDump(true);

        Tetrimino t1(1);
        t1.setLocation(20,-1);
        bool a = test.tetriminoFit(t1);

        if(a){
            test.addTetriminoToWell(t1);
            test.boardDump(a);
        }

        Tetrimino t2(3);
        t2.setLocation(18, -1);
        bool b = test.tetriminoFit(t2);

        if(b){
            test.addTetriminoToWell(t2);
            test.boardDump(b);
        }

        Tetrimino t3(3);
        t3.setLocation(17,-1);
        bool c = test.tetriminoFit(t3);

        if(c)
            cout << "the result is true" << endl;
        else
            cout << "The result is false" << endl;

        if(c){
            test.addTetriminoToWell(t3);
        }
        test.boardDump(c);

        Tetrimino t4(7);
        t4.setLocation(2,2);
        bool d = test.tetriminoFit(t4);
        if(d){
            test.addTetriminoToWell(t4);
        }
        test.boardDump(d);

        Tetrimino t5(0);
        t5.setLocation(18,2);
        bool e = test.tetriminoFit(t5);
        if(e){
            test.addTetriminoToWell(t5);
        }
        test.boardDump(e);

        Tetrimino t6(3);
        t6.setLocation(18,5);
        bool f = test.tetriminoFit(t6);
        if(f){
            test.addTetriminoToWell(t6);
        }
        test.boardDump(f);

        Tetrimino t7(0);
        t7.setLocation(17,2);
        bool g = test.tetriminoFit(t7);
        if(g){
            test.addTetriminoToWell(t7);
        }
        test.boardDump(g);

        test.clearFullRows();
        test.boardDump(true);


        Tetrimino t8(4);
        t8.setLocation(-1, 3);
        bool h = test.tetriminoFit(t8);
        if(h){
            test.addTetriminoToWell(t8);
        }
        test.boardDump(h);

        bool topreached = test.topReached();
        test.boardDump(h, topreached);


        char bo[BOARD_ROW][BOARD_COL];
        test.getBoard(bo);
        test.boardDump(true);
        */


