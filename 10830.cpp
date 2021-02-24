#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> mat_mul(vector<vector<int>> v1, vector<vector<int>> v2){
    int n = v1.size();
    vector<vector<int>> result(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++)
                result[i][j] = (result[i][j] + v1[i][k] * v2[k][j]) % 1000;
        }
    }
    return result;
}

vector<vector<int>> mat_mul(vector<vector<int>> v){
    return mat_mul(v, v);
}

vector<vector<int>> mat_pow(vector<vector<int>> v, long long b){
    auto x = v;
    auto y = v;
    bool isIdentity = b % 2;
    auto n = b / 2;

    if(n == 0){
        for(auto& i : y){
            for(auto& j : i)
                j %= 1000;
        }
    }

    while(n > 0){
        x = mat_mul(x);
        if(n % 2){
            if(!isIdentity){
                y = x;
                isIdentity = true;
            }
            else
                y = mat_mul(x, y);
        }
        n /= 2;
    }
    return y;
}

int main(){
    int n;
    long long b;
    scanf("%d %lld", &n, &b);

    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        vector<int> tmp(n);
        for(auto &j : tmp)
            scanf("%d", &j);
        v.push_back(tmp);
    }

    auto result = mat_pow(v, b);
    for(auto i : result){
        for(auto j : i)
            printf("%d ", j);
        printf("\n");
    }
}