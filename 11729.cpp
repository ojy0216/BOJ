#include <iostream>
#include <cmath>
using namespace std;

void f(int num, int from, int by, int to){
    if(num == 1)
        cout << from << " " << to << '\n';
    else{
        f(num - 1, from, to, by);
        cout << from << " " << to << '\n';
        f(num - 1, by, from, to);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << pow(2, n) - 1 << '\n';

    f(n, 1, 2, 3);
}