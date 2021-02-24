#include <cstdio>
#include <vector>
using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>> v1, vector<vector<long long>> v2){
    auto n1 = v1.size();
    auto m1 = v1[0].size();
    auto m2 = v2[0].size();
    vector<vector<long long>> result(n1, vector<long long> (m2, 0));
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m2; j++){
            for(int k = 0; k < m1; k++)
                result[i][j] = (result[i][j] + v1[i][k] * v2[k][j]) % 1000000007;
        }
    }
    return result;
}

vector<vector<long long>> mat_mul(vector<vector<long long>> v){
    return mat_mul(v, v);
}

vector<vector<long long>> mat_pow(unsigned long long b){
    vector<vector<long long>> x(2, vector<long long> (2, 1));
    x[1][1] = 0;
    auto y = x;
    bool isIdentity = b % 2;
    auto n = b / 2;

    if(n == 0){
        for(auto& i : y){
            for(auto& j : i)
                j %= 1000000007;
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
    unsigned long long n;
    scanf("%llu", &n);

    vector<vector<long long>> v(2, vector<long long> (1, 0));
    v[0][0] = 1;
    v[1][0] = 0;

    auto f = mat_pow(n - 1);
    auto result = mat_mul(f, v);
    printf("%lld", result[0][0]);
}