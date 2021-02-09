#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> v(n, 0);
    for(auto& i : v)
        scanf("%d", &i);

    vector<int> length_l = {1};
    vector<int> length_r(n, 0);
    length_r.back() = 1;

    for(int i = 1; i < n; i++){
        int max_l = 0;
        for(int j = 0; j < i; j++){
            if(v[j] < v[i] && length_l[j] > max_l)
                max_l = length_l[j];
        }
        if(max_l == 0)
            length_l.push_back(1);
        else
            length_l.push_back(max_l + 1);
    }

    for(int i = n - 2; i >= 0; i--){
        int max_r = 0;
        for(int j = n - 1; i < j; j--){
            if(v[i] > v[j] && length_r[j] > max_r)
                max_r = length_r[j];
        }
        if(max_r == 0)
            length_r[i] = 1;
        else
            length_r[i] = max_r + 1;
    }    

    /* 
    for(auto i : length_l)
        printf("%d ", i);
    printf("\n");
    for(auto i : length_r)
        printf("%d ", i);
    printf("\n");
    */
    

    int result = 0;
    for(int i = 0; i < n; i++){
        if(length_l[i] + length_r[i] - 1 > result)
            result = length_l[i] + length_r[i] - 1;
    }

    printf("%d", result);
}