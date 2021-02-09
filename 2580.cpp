#include <iostream>
using namespace std;

int arr[9][9];

bool possible(int x, int y, int n){
    // x = j, y = i
    for(int i = 0; i < 9; i++){
        if(arr[i][x] == n)
            return false;
    }
    for(int j = 0; j < 9; j++){
        if(arr[y][j] == n)
            return false;
    }
    int gridX = (x / 3) * 3;
    int gridY = (y / 3) * 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[gridY + i][gridX + j] == n)
                return false;
        }
    }
    return true;
}

void printBoard(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

bool solve(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(arr[i][j] == 0){
                for(int n = 1; n <= 9; n++){
                    if(possible(j, i, n)){
                        arr[i][j] = n;
                        if(solve())
                            return true;
                        arr[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            scanf("%d", &arr[i][j]);
    }

    solve();
    printBoard();
}