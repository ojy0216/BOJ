#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> line;
    int a, b;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        line.push_back(make_pair(a, b));
    }

    sort(line.begin(), line.end(), compare);

    vector<int> dp;
    vector<int> length = { 1 };
    for(auto it = line.begin(); it != line.end(); it++)
        dp.push_back((*it).second);

    for(int i = 1; i < n; i++){
        int max = 0;
        for(int j = 0; j < i; j++){
            if(dp[j] < dp[i] && length[j] > max)
                max = length[j];
        }
        if(max == 0)
            length.push_back(1);
        else
            length.push_back(max + 1);
    }

    int result = *max_element(length.begin(), length.end());

    printf("%d", n - result);
}