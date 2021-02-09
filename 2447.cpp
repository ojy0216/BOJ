#include <iostream>
#include <cmath>
using namespace std;

void f(int level, int x, int y, char **arr){
    // cout << "Level / x / y >> " << level << " " << x << " " << y << endl;
    if(level == 1){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == 1 && j == 1)
                    arr[x + i][y + j] = ' ';
                else
                    arr[x + i][y + j] = '*';
            }
        }
        return;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != 1 || j != 1)
                f(level - 1, x + pow(3, level - 1) * i, y + pow(3, level - 1) * j, arr);
        }
    }
}

int main(){
    int n;
    cin >> n;

    int level = 0;
    while(n > 1){
        n /= 3;
        level++;
    }
    n = pow(3, level);
    // cout << "Level >> " << level << endl;

    char **arr = new char* [n];
    for(int i = 0; i < n; i++){
        arr[i] = new char [n];
        for(int j = 0; j < n; j++)
            arr[i][j] = ' ';
    }

    f(level, 0, 0, arr);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << arr[i][j];
        cout << endl;
    }

    for(int i = 0; i < n; i++)
        delete [] arr[i];
    delete [] arr; 
}