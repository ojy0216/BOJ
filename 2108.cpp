#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int sum = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    /*
    printf("[Print Sorted]\n");
    for(auto it = v.begin(); it != v.end(); it++)
        printf("%d ", *it);
    printf("\n");
    */

    int avg = round((float)sum / n);
    int min = v[0];
    int max = v[n - 1];
    int range = max - min;
    int median = v[n / 2];

    int *p = new int [range + 1];
    memset(p, 0, sizeof(int) * (range + 1));

    for(auto it = v.begin(); it != v.end(); it++)
        p[(*it) - min]++;

    /*
    printf("[Print times]\n");
    for(int i = 0; i <= range; i++)
        printf("%d ", p[i]);
    printf("\n");
    */
    
    int maxCount = -1;
    bool modeFound = false;
    int mode;
    for(int i = 0; i <= range; i++){
        if(p[i] > maxCount){
            maxCount = p[i];
            mode = i + min;
            modeFound = true;
        }
        else if(p[i] == maxCount && modeFound){
            mode = i + min;
            modeFound = false;
        }
    }

    // printf("max: %d, min: %d, range: %d, avg: %d, median: %d, mode: %d\n", max, min, range, avg, median, mode);
    printf("%d\n%d\n%d\n%d", avg, median, mode, range);

    delete [] p;
}
