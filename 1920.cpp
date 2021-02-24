#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool binarySearch(int n, int left, int right){
    if(left > right)
        return false;

    int mid = (left + right) / 2;

    if(v[mid] == n)
        return true;
    else if(n < v[mid])
        return binarySearch(n, left, mid - 1);
    else
        return binarySearch(n, mid + 1, right);
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int target;
        scanf("%d", &target);
        printf("%d\n", binarySearch(target, 0, n - 1));
    }
}