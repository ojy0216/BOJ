#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    int sum;
    int max_sum = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                sum = v[i] + v[j] + v[k];
                if(sum <= m && sum > max_sum)
                    max_sum = sum;
            }
        }
    }
    printf("%d", max_sum);
}