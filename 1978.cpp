#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int count = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(x == 1){
            continue;
        }

        bool isPrime = true;
        for(int j = 2; j <= x - 1; j++){
            if(x % j == 0){
                isPrime = false;
                break;
            }
        }
        count += isPrime;
    }    
    cout << count;
}