#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int i = 1   ;
    int x = 1;
    while(true){
        if(n <= x)
            break;
        x += (6 * i);
        i++;
    }
    cout << i;
}