#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> count(int n){
    int count2 = 0, count5 = 0;

    for(long long i = 2; i <= n; i *= 2)
        count2 += n / i;
    
    for(long long i = 5; i <= n; i *= 5)
        count5 += n / i;

    return make_pair(count2, count5);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int k = n - m;

    auto countM = count(m);
    auto countN = count(n);
    auto countK = count(k);

    auto count2 = countN.first - (countM.first + countK.first);
    auto count5 = countN.second - (countM.second + countK.second);
    printf("%d\n", min(count2, count5));
}