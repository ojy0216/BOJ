#include <iostream>
#include <vector>
using namespace std;

int g(vector<int> v, vector<int> v_pick, int n, int level){
    int count = 0;
    for(auto it = v.begin(); it != v.end(); it++){
        int pick = *it;
        bool invalid = false;
        for(int i = 0; i < level - 1; i++){
            if(pick == v_pick[i] - (level - i - 1) || pick == v_pick[i] + (level - i - 1)){
                invalid = true;
                break;
            }
        }
        if(level == n){
            if(invalid)
                return 0;
            else{
                /*
                printf("Case found\n");
                for(auto it = v_pick.begin(); it != v_pick.end(); it++)
                    printf("%d ", *it);
                printf("%d\n", v[0]);
                */
                return 1;
            }
        }

        if(invalid)
            continue;

        it = v.erase(it);
        v_pick.push_back(pick);
        count += g(v, v_pick, n, level + 1);
        v_pick.pop_back();
        v.insert(it, pick);
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);

    vector<int> v, v_pick;
    for(int i = 0; i < n; i++)
        v.push_back(i);

    int count = g(v, v_pick, n, 1);

    printf("%d", count);  
}