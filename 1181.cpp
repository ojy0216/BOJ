#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main(){
    int n;
    cin >> n;

    vector<string> v;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), compare);

    string prev = "";
    for(auto it = v.begin(); it != v.end(); it++){
        if(*it != prev)
            cout << *it << '\n';
        prev = *it;
    }
}