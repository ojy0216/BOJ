#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> v;
    while(n > 0){
        v.push_back(n % 10);
        n /= 10;
    }

    sort(v.begin(), v.end(), greater<int>());

    for(auto it = v.begin(); it != v.end(); it++)
        printf("%d", *it);
}