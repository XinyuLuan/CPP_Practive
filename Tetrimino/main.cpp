#include <iostream>

using namespace std;

void rotateLeft(int a[][4]);
void rotateRight(int a[][4]);

int main(int argc, char *argv[])
{
    int arr[4][4] = {{0,0,0,0},{0,1,0,0},{0,1,1,1},{0,0,0,0}};
    rotateLeft(arr);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << arr[i][j] << " ";
        }
        cout <<endl;
    }
    rotateRight(arr);
    rotateRight(arr);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << arr[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}
void rotateRight(int a[][4]){
    int res[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            res[3-j][i] = a[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] = res[i][j];
        }
    }
}

void rotateLeft(int a[][4]){
    int res[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            res[j][3-i] = a[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] = res[i][j];
        }
    }
}
