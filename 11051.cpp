#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> v(1001, vector<int> (1001, 0));

int coef(int n, int k){
    if(k == 0 || k == n)
        v[n][k] = 1;
    else if(v[n][k] == 0)
        v[n][k] = (coef(n - 1, k - 1) + coef(n - 1, k)) % 10007;
    return v[n][k];
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d", coef(n, k));
}