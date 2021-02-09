#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        unsigned int x, y;
        cin >> x >> y;
        unsigned int l = y - x;

        int j = 1;
        while(j * j < l)
            j++;
        
        if(l <= j * j - j)
            cout << 2 * j - 2 << endl;
        else
            cout << 2 * j - 1 << endl;
    }
}