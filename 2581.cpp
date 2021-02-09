#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    int sum = 0, min;
    for(int i = m; i <= n; i++){
        if(i == 1)
            continue;

        bool isPrime = true;
        for(int j = 2; j <= i - 1; j++){
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            if(sum == 0)
                min = i;
            sum += i;
        }
    }
    if(sum == 0)
        cout << -1;
    else{
        cout << sum << "\n" << min;
    }
}