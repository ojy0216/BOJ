#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;

    int count = 0;
    for(int i = 0; i < n; i++){
        bool flag = true;
        string s;
        cin >> s;

        map<char, int> m;
        for(int j = 0; j < s.length(); j++)
            m[s[j]]++;
        
        for(auto it = m.begin(); it != m.end(); it++){
            string tmp;
            for(int k = 0; k < it->second; k++)
                tmp += it->first;
            
            if(s.find(tmp, 0) == -1){
                flag = false;
                break;
            }
        }

        if(flag)
            count++;
    }

    cout << count;
}