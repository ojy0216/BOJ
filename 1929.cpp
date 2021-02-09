#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    bool* pArr = new bool [n + 1];

    for(int i = 0; i < (n + 1); i++)
        pArr[i] = true;

    for(int i = 2; i * i <= n; i++){
        if(pArr[i])
            for(int j = i * i; j <= n; j += i)
                pArr[j] = false;
    }

    for(int i = 2; i < (n + 1); i++){
        if(pArr[i] && i >= m)
            cout << i << "\n";
    }

    delete [] pArr;
}