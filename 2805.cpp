#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long parametric_search(vector<int>& v, int target, long long low, long long high){
    long long result = 0;
    long long mid;

    while(low <= high){
        mid = (low + high) / 2;

        long long sum = 0;
        for(auto i : v){
            if(i >= mid)
                sum += (i - mid);
        }

        if(sum >= target){
            if(result < mid)
                result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return result;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(auto& i : v)
        cin >> i;

    long long max = *max_element(v.begin(), v.end());

    cout << parametric_search(v, m, 0, max);
}