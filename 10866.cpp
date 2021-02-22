#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    deque<int> dq;
    for(int i = 0; i < n; i++){
        char op[11];
        scanf("%s", &op);

        if(strcmp(op, "push_front") == 0){
            int tmp;
            scanf("%d", &tmp);
            dq.push_front(tmp);
        }
        else if(strcmp(op, "push_back") == 0){
            int tmp;
            scanf("%d", &tmp);
            dq.push_back(tmp);
        }
        else if(strcmp(op, "pop_front") == 0){
            if(dq.empty())
                printf("-1\n");
            else{
                printf("%d\n", dq.front());
                dq.pop_front();
            }
        }
        else if(strcmp(op, "pop_back") == 0){
            if(dq.empty())
                printf("-1\n");
            else{
                printf("%d\n", dq.back());
                dq.pop_back();
            }
        }
        else if(strcmp(op, "size") == 0)
            printf("%d\n", dq.size());
        else if(strcmp(op, "empty") == 0)
            printf("%d\n", dq.empty());
        else if(strcmp(op, "front") == 0){
            if(dq.empty())
                printf("-1\n");
            else
                printf("%d\n", dq.front());
        }
        else{
            if(dq.empty())
                printf("-1\n");
            else
                printf("%d\n", dq.back());
        }
    }
}