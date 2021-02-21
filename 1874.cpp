#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> target(n);
    vector<int> erasedV(n + 1, 0);
    for(auto& i : target)
        scanf("%d", &i);
    target.insert(target.begin(), 0);

    vector<char> op;
    bool avail = true;
    int erased = 0;
    int cur = 0;

    for(int i = 1; i <= n; i++){
        int erased = 0;
        if(target[i] > cur){
            for(int j = cur + 1; j < target[i]; j++)
                erased += erasedV[j];

            for(int j = 0; j < target[i] - cur - erased; j++)
                op.push_back('+');
        }
        else{
            for(int j = target[i]; j < cur; j++)
                erased += erasedV[j];

            if(target[i] != cur - erased - 1){
                avail = false;
                break;
            }
        }
        op.push_back('-');
        erasedV[target[i]] = 1;
        cur = target[i];
    }

    if(avail){
        for(auto i : op)
            printf("%c\n", i);
    }
    else
        printf("NO");
}