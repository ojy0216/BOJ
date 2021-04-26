#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> sorted = v;

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    // for(auto i : sorted)
    //     cout << i << " ";

    for(auto i : v){
        auto it = lower_bound(sorted.begin(), sorted.end(), i);
        cout << it - sorted.begin() << " ";
    }
}