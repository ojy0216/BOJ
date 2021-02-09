#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        bool* pArr = new bool [n + 1];
        for(int j = 0; j <= n; j++)
            pArr[j] = true;

        pArr[1] = false;

        for(int j = 2; j * j <= n; j++){
            if(pArr[j])
                for(int k = j * j; k <= n; k += j)
                    pArr[k] = false;
        }

        for(int j = n / 2; j >= 2; j--){
            if(pArr[j] && pArr[n - j]){
                cout << j << " " << n - j << endl;
                break;
            }
        }

        delete [] pArr;
    }
}