#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>&v, int target, int low, int high){
    int mid;
    int result = 0;

    while(low <= high){
        mid = (low + high) / 2;

        int before_idx = 0;
        int num = 1;    

        for(int i = 1; i < v.size(); i++){
            if(v[i] - v[before_idx] >= mid){
                before_idx = i;
                num++;
            }
        }

        if(num >= target){
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return result;
}

int main(){
    int n, c;
    cin >> n >> c;

    vector<int> v(n);
    for(auto& i : v)
        cin >> i;

    sort(v.begin(), v.end());

    cout << binarySearch(v, c, 1, v.back() - v.front());
}