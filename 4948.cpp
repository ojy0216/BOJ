#include <iostream>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0)  
            break;

        bool* pArr = new bool [2 * n + 1];

        for(int i = 2; i < (2 * n + 1); i++)
            pArr[i] = true;

        pArr[1] = false;

        for(int i = 2; i * i <= 2 * n; i++){
            if(pArr[i])
                for(int j = i * i; j <= 2 * n; j += i)
                    pArr[j] = false;
        }

        int count = 0;
        for(int i = n + 1; i <= (2 * n); i++){
            if(pArr[i])
                count++;
        }

        delete [] pArr;

        cout << count << "\n";
    }
}