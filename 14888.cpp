#include <iostream>
#include <vector>
using namespace std;

enum {ADD, SUB, MUL, DIV};

int maxResult, minResult;
bool maxFound = false, minFound = false;

void f(vector<int> v, int op[], vector<int> op_v){
    //printf("f call: %d\n", op_v.size());
    //printf("OP: %d %d %d %d\n", op[0], op[1], op[2], op[3]);
    /*
    printf("Op list: ");
    for(auto it = op_v.begin(); it != op_v.end(); it++)
        printf("%d ", *it);
    printf("\n");
    */

    for(int i = 0; i < 4; i++){
        if(op[i] > 0){
            op[i]--;
            op_v.push_back(i);
            f(v, op, op_v);
            op_v.pop_back();
            op[i]++;
        }
    }

    if(op_v.size() + 1 == v.size()){
        int result = v[0];
        // printf("OP_V size: %d\n", op_v.size());
        for(int i = 1; i <= op_v.size(); i++){
            switch(op_v[i - 1]){
                case ADD:
                    result += v[i];
                        break;
                case SUB:
                    result -= v[i];
                    break;
                case MUL:
                    result *= v[i];
                    break;
                case DIV:
                    result /= v[i];
                    break;
            }
        }
        // printf("%d\n", result);
        if(!maxFound){
            maxResult = result;
            maxFound = true;
        }
        else{
            if(result > maxResult)
                maxResult = result;
        }
        if(!minFound){
            minResult = result;
            minFound = true;
        }
        else{
            if(result < minResult)
                minResult = result;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    vector<int> v;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    int op[4];
    vector<int> op_v;
    for(int i = 0; i < 4; i++){
        int tmp;
        scanf("%d", &tmp);
        op[i] = tmp;
    }

    f(v, op, op_v);

    printf("%d\n%d", maxResult, minResult);
}