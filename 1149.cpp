#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int a, b, c, a_next, b_next, c_next, a_tmp, b_tmp, c_tmp;
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 1; i < n; i++){
        scanf("%d %d %d", &a_next, &b_next, &c_next);
        a_tmp = min(a_next + b, a_next + c);
        b_tmp = min(b_next + a, b_next + c);
        c_tmp = min(c_next + a, c_next + b);
        a = a_tmp;
        b = b_tmp;
        c = c_tmp;
    }
    printf("%d", min(a, min(b, c)));
}