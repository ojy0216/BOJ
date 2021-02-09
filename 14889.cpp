#include <iostream>
#include <vector>
using namespace std;

int n;
int minDiff;
bool minFound = false;

void f(int **s, vector<int> t1, vector<int> t2){
    if(t2.size() == n / 2){
        /*
        for(auto it = t1.begin(); it != t1.end(); it++)
            printf("%d ", *it - 1);
        printf("\t");

        for(auto it = t2.begin(); it != t2.end(); it++)
            printf("%d ", *it - 1);
        printf("\n");
        */

        int t1Ability = 0, t2Ability = 0;
        for(int i = 0; i < t1.size() - 1; i++){
            for(int j =  i + 1; j < t1.size(); j++){
                t1Ability += s[t1[i] - 1][t1[j] - 1];
                t1Ability += s[t1[j] - 1][t1[i] - 1];
                t2Ability += s[t2[i] - 1][t2[j] - 1];
                t2Ability += s[t2[j] - 1][t2[i] - 1];
            }
        }
        int abilityDiff = abs(t1Ability - t2Ability);
        if(!minFound){
            minDiff = abilityDiff;
            minFound = true;
        }
        else{
            if(abilityDiff < minDiff)
                minDiff = abilityDiff;
        }
        return;
    }
    else{
        for(auto it = t1.begin(); it != t1.end(); it++){
            int tmp = *it;
            if(!t2.empty() && tmp < t2.back())
                continue;
            it = t1.erase(it);
            t2.push_back(tmp);
            f(s, t1, t2);
            t2.pop_back();
            t1.insert(it, tmp);
        }
    }
}

int main(){
    scanf("%d", &n);

    int **s = new int* [n];
    for(int i = 0; i < n; i++)
        s[i] = new int [n];
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%d", &s[i][j]);
    }        

    vector<int> t1, t2 = { 1 };
    for(int i = 1; i < n; i++)
        t1.push_back(i + 1);

    f(s, t1, t2);

    printf("%d", minDiff);

    for(int i = 0; i < n; i++)
        delete [] s[i];
    delete [] s;
}