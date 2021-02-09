#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    const string target[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    int count = 0;
    for(int i = 0; i < 8; i++){
        int idx = 0;
        while(true){
            idx = s.find(target[i], idx);
            if(idx != -1){
                s.replace(idx, target[i].length(), ".");
                count++;
            }
            else
                break;
        }
    }
    for(auto it = s.begin(); it != s.end(); it++){
        if(*it != '.')
            count++;
    }
    
    cout << count;
}