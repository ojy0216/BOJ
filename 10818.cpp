#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int* arr = new int [n];

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[i] = x;
    }

    int min = arr[0];
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    cout << min << " " << max;

    delete [] arr;
}