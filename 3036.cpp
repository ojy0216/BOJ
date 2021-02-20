#include <cstdio>
#include <vector>
using namespace std;

int GCD(int x, int y){
    int r;
    while(y){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for(auto& i : v)
        scanf("%d", &i);

    for(int i = 1; i < n; i++){
        int gcd = GCD(v[0], v[i]);
        printf("%d/%d\n", v[0] / gcd, v[i] / gcd);
    }
}