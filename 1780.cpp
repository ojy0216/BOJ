#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> v;
int count[3] = {0, }; // -1, 0, 1

void f(int x_min, int x_max, int y_min, int y_max){
    if(x_min == x_max){
        count[v[y_min][x_min] + 1]++;
        return;
    }

    int tmp_count[3] = {0, }; // -1, 0, 1
    for(int y = y_min; y <= y_max; y++){
        for(int x = x_min; x <= x_max; x++){
            tmp_count[v[y][x] + 1]++;
        }
    }
    int total = (y_max - y_min + 1) * (x_max - x_min + 1);
    if(tmp_count[0] == total)
        count[0]++;
    else if(tmp_count[1] == total)
        count[1]++;
    else if(tmp_count[2] == total)
        count[2]++;
    else{
        int i = 1;
        while(i < (x_max - x_min) / 3)
            i *= 3;
        f(x_min, x_min + i - 1, y_min, y_min + i - 1); // upper left 
        f(x_min + i, x_min + 2 * i - 1, y_min, y_min + i - 1); // upper mid
        f(x_min + 2 * i, x_max, y_min, y_min + i - 1); // upper right
        f(x_min, x_min + i - 1, y_min + i, y_min + 2 * i - 1); // mid left
        f(x_min + i, x_min + 2 * i - 1, y_min + i, y_min + 2 * i - 1); // mid mid
        f(x_min + 2 * i, x_max, y_min + i, y_min + 2 * i - 1); // mid right
        f(x_min, x_min + i - 1, y_min + 2 * i, y_max); // lower left
        f(x_min + i, x_min + 2 * i - 1, y_min + 2 * i, y_max); // lower mid
        f(x_min + 2 * i, x_max, y_min + 2 * i, y_max); // lower ight
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        vector<int> tmp(n);
        for(auto& j : tmp)
            scanf("%d", &j);
        v.push_back(tmp);
    }
    f(0, n - 1, 0, n - 1);

    for(auto i : count)
        printf("%d\n", i);
}