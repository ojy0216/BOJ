#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int c;
    cin >> c;

    for(int i = 0; i < c; i++){
        int n;
        cin >> n;
        int *arr = new int [n];
        int tmp, sum = 0;
        for(int j = 0; j < n; j++){
            cin >> tmp;
            arr[j] = tmp;
            sum += tmp;
        }

        double ave = sum / n;
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] > ave)
                count++;
        }
        cout << fixed;
        cout.precision(3);
        cout << ((double)count / n) * 100 << "%" << endl;

        delete [] arr;
    }
}