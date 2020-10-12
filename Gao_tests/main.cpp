#include <iostream>

using namespace std;

int getSum();



int main(int argc, char *argv[])
{
    //part 1
    static int a = 10, b = 100;
    int sum = getSum();
    cout << "the sum: " << sum << endl;


    //part 2
    const int SIZE = 5;
    int tests[SIZE] = {1,2,3,4,5};
//    int tests[SIZE];

    for(int i = 0; i < SIZE + 2; i++){
//        tests[i] = 2*i;
        cout << tests[i] << " ";
    }
    cout << endl;


    //part 3
    const int ROW = 2, COL = 2;
    int exams[ROW][COL] = { 84,78, 92 };
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cout << exams[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


int getSum(){
//    static int a = 100000, b = 1000;
//    static int a = 0, b = 1;
    return a + b;
}
