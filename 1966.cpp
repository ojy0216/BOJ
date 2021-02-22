#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int n, m;
        scanf("%d %d", &n, &m);

        priority_queue<int> pq;

        queue<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            int tmp;
            scanf("%d", &tmp);
            v.push(make_pair(tmp, i));
            pq.push(tmp);
        }

        queue<int> printq;
        while(!v.empty()){
            if(v.front().first != pq.top()){
                auto tmp = v.front();
                v.push(tmp); 
            }
            else{
                printq.push(v.front().second);
                pq.pop();
            }
            v.pop();
        }

        int count = 0;
        while(!printq.empty()){
            count++;
            if(printq.front() == m)
                break;
            printq.pop();
        }
        printf("%d\n", count);
    }
}