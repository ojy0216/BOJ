#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    double *arr = new double [n];
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    for(int i = 0; i < n; i++)
        arr[i] = arr[i] / max * 100;    

    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    cout << sum / n;

    delete [] arr;
}