#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v(m);
    for(auto& i : v)
        scanf("%d", &i);

    deque<int> ldq, rdq;
    for(int i = 1; i <= n; i++){
        ldq.push_back(i);
        rdq.push_back(i);
    }

    int count = 0;
    for(auto i : v){
        int ldqCount = 0, rdqCount = 0;
        while(ldq.front() != i){
            auto tmp = ldq.front();
            ldq.pop_front();
            ldq.push_back(tmp);
            ldqCount++;
        }
        ldq.pop_front();
        while(rdq.front() != i){
            auto tmp = rdq.back();
            rdq.pop_back();
            rdq.push_front(tmp);
            rdqCount++;
        }
        rdq.pop_front();
        count += min(ldqCount, rdqCount);
    }
    printf("%d", count);
}