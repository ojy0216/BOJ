#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    vector<int> p;

    for(auto& i : v)
        cin >> i.first >> i.second;
    
    for(auto i : v)
        p.emplace_back(i.first);
    p.emplace_back(v.back().second);

    vector<vector<int>> m(n, vector<int>(n, 0));

    for(int l = 1; l < n; l++){
        for(int i = 0; i < n - l; i++){
            int j = i + l;
            int q;

            m[i][j] = m[i][i] + m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];

            for(int k = i + 1; k < j; k++){
               q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if(q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    cout << m[0][n - 1];
}