#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    vector<int> n;
    vector<char> op;
    string tmp;
    for(auto i : s){
        if(isdigit(i))
            tmp.push_back(i);
        else{
            n.push_back(stoi(tmp));
            tmp.clear();
            op.push_back(i);
        }
    }
    n.push_back(stoi(tmp));

    vector<int> calc = { n[0] };
    for(auto i = 0; i < op.size(); i++){
        if(op[i] == '+')
            calc.back() += n[i + 1];
        else
            calc.push_back(n[i + 1]);
    }

    int result = calc[0];
    for(auto i = 1; i < calc.size(); i++){
        result -= calc[i];
    }
    cout << result;
}