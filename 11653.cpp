#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    if(t == 1)
        return 0;

    int d = 2;
    while((t / d) >= 1){
        if(t % d == 0){
            t /= d;
            cout << d << "\n";
        }
        else
            d++;
    }
}