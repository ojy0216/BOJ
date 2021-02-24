#include <cstdio>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> a;
    vector<vector<int>> b;

    int n1, m1;
    scanf("%d %d", &n1, &m1);
    for(int i = 0; i < n1; i++){
        vector<int> tmp(m1);
        for(auto& j : tmp)
            scanf("%d", &j);
        a.push_back(tmp);
    }

    int n2, m2;
    scanf("%d %d", &n2, &m2);
    for(int i = 0; i < n2; i++){
        vector<int> tmp(m2);
        for(auto& j : tmp)
            scanf("%d", &j);
        b.push_back(tmp);
    }

    vector<vector<int>> result(n1, vector<int> (m2, 0));
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m2; j++){
            int sum = 0;
            for(int k = 0; k < m1; k++)
                sum += a[i][k] * b[k][j];
            result[i][j] = sum;
        }
    }

    for(auto i : result){
        for(auto j : i)
            printf("%d ", j);
        printf("\n");
    }
}