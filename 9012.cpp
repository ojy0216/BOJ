#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        vector<char> v;
        string s;
        cin >> s;

        for(auto i : s){
            if(i == '(')
                v.push_back('0');
            else{
                if(v.empty()){
                    v.push_back('0');
                    break;
                }
                else
                    v.pop_back();
            }
        }
        if(v.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}