#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> um;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        um[tmp]++;
    }

    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int tmp;
        scanf("%d", &tmp);
        printf("%d ", um[tmp]);
    }
}