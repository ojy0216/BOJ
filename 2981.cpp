#include <cstdio>
#include <vector>
#include <algorithm>
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

    sort(v.begin(), v.end());

    int gcd = v[1] - v[0];
    for(int i = 2; i < n; i++)
        gcd = GCD(gcd, v[i] - v[i - 1]);

    vector<int> result;
    for(int i = 2; i * i <= gcd; i++){
        if(gcd % i == 0){
            result.push_back(i);
            result.push_back(gcd / i);
        }
    }
    result.push_back(gcd);

    sort(result.begin(), result.end());

    result.erase(unique(result.begin(), result.end()), result.end());

    for(auto i : result)
        printf("%d ", i);
}