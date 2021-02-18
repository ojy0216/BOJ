#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int tmp_a, tmp_b;
        scanf("%d %d", &tmp_a, &tmp_b);
        v.push_back(make_pair(tmp_a, tmp_b));
    }

    sort(v.begin(), v.end(), compare);

    /*
    printf("--------------------\n");
    for(auto i : v)
        printf("%d %d\n", i.first, i.second);
    */

    int now = v[0].second;
    int cnt = 1;
    for(auto it = v.begin() + 1; it != v.end(); it++){
        if(now <= (*it).first){
            cnt++;
            now = (*it).second;
        }
    }

    /*
    printf("--------------------\n");
    for(auto i : v)
        printf("%d %d\n", i.first, i.second);
    */

    printf("%d", cnt);
}