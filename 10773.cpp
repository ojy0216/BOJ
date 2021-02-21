#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    int k;
    cin >> k;

    vector<int> v;

    for(int i = 0; i < k; i++){
        int n;
        cin >> n;
        
        if(n == 0)
            v.pop_back();
        else
            v.push_back(n);
    }

    int result = accumulate(v.begin(), v.end(), 0);

    cout << result;
}