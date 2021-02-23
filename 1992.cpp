#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

void f(int x_min, int x_max, int y_min, int y_max){
    if(x_min == x_max){
        printf("%d", v[y_min][x_min] - '0');
        return;
    }
    int sum = 0;
    for(int y = y_min; y <= y_max; y++){
        for(int x = x_min; x <= x_max; x++){
            sum += (v[y][x] - '0');
        }
    }
    if(sum == 0)
        printf("0");
    else if(sum == (y_max - y_min + 1) * (x_max - x_min + 1))
        printf("1");
    else{
        printf("(");
        f(x_min, (x_max + x_min) / 2, y_min, (y_max + y_min) / 2); // upper left
        f((x_max + x_min) / 2 + 1, x_max, y_min, (y_max + y_min) / 2); // upper right
        f(x_min, (x_max + x_min) / 2, (y_max + y_min) / 2 + 1, y_max); // lower left
        f((x_max + x_min) / 2 + 1, x_max, (y_max + y_min) / 2 + 1, y_max); // lower right 
        printf(")");
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    f(0, n - 1, 0, n - 1);
}