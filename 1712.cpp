#include <iostream>
using namespace std;

int main(){
    unsigned int a, b, c;

    cin >> a >> b >> c;

    if(c <= b)
        cout << -1;
    else
        cout << a / (c - b) + 1;
}