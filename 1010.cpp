#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> v(31, vector<int> (31, 0));

int coef(int n, int k){
    if(k == 0 || k == n)
        v[n][k] = 1;
    else if(v[n][k] == 0)
        v[n][k] = coef(n - 1, k - 1) + coef(n - 1, k);
    return v[n][k];
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int n, m;
        scanf("%d %d", &n, &m);

        printf("%d\n", coef(m, n));
    }
}