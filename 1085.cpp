#include <iostream>
using namespace std;

int main(){
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int x_min = x < (w - x) ? x : w - x;
    int y_min = y < (h - y) ? y : h - y;

    int min = (x_min > y_min) ? y_min : x_min;
    
    cout << min;
}