#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for(auto &i : v)
        scanf("%d", &i);
    
    sort(v.begin(), v.end());

    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += (v[i] * (n - i));
    
    printf("%d", sum);
}