#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> v;
int color[2] = {0, 0}; // white, blue
enum {white, blue};

void f(int x_min, int x_max, int y_min, int y_max){
    if(x_min == x_max){
        color[v[y_min][x_min]]++;
        return;
    }
    int sum = 0;
    for(int y = y_min; y <= y_max; y++){
        for(int x = x_min; x <= x_max; x++){
            sum += v[y][x];
        }
    }
    if(sum == 0)
        color[white]++;
    else if(sum == (y_max - y_min + 1) * (x_max - x_min + 1))
        color[blue]++;
    else{
        f(x_min, (x_max + x_min) / 2, y_min, (y_max + y_min) / 2); // upper left
        f((x_max + x_min) / 2 + 1, x_max, y_min, (y_max + y_min) / 2); // upper right
        f(x_min, (x_max + x_min) / 2, (y_max + y_min) / 2 + 1, y_max); // lower left
        f((x_max + x_min) / 2 + 1, x_max, (y_max + y_min) / 2 + 1, y_max); // lower right 
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        vector<int> v_tmp(n);
        for(auto& i : v_tmp)
            scanf("%d", &i);
        v.push_back(v_tmp);
    }

    f(0, n - 1, 0, n - 1);
    printf("%d\n%d", color[0], color[1]);
}