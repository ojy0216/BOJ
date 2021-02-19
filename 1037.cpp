#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for(auto& i : v)
        scanf("%d", &i);

    sort(v.begin(), v.end());

    int result = v.front() * v.back();

    printf("%d", result);
}