#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    while(true){
        string s;
        getline(cin, s);

        if(s == ".")
            break;
        
        vector<char> v;

        for(auto i : s){
            if(i == '(')
                v.push_back('(');
            else if(i == '[')
                v.push_back('[');
            else if(i == ')'){
                if(v.empty() || v.back() != '('){
                    v.push_back('.');
                    break;
                }
                else
                    v.pop_back();
            }
            else if(i == ']'){
                if(v.empty() || v.back() != '['){
                    v.push_back('.');
                    break;
                }
                else
                    v.pop_back();
            }
        }

        if(v.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}