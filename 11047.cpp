#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        v.insert(v.begin(), tmp);
    }

    int count = 0;
    for(auto i : v){
        count += (k / i);
        k %= i;
    }
    printf("%d", count);
}