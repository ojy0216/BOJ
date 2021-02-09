#include <iostream>
using namespace std;

#define PI 3.1415926535897932

int main(){
    int r;
    cin >> r;

    cout.precision(6);
    cout << fixed << PI * r * r << endl;
    cout << fixed << (double)2 * r * r;
}