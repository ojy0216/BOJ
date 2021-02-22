#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        string s;
        cin >> s;

        int n;
        cin >> n;
        deque<int> dq;

        string num;
        cin >> num;

        string tmp;
        for(auto c : num){
            if(isdigit(c))
                tmp.push_back(c);
            else if(!tmp.empty()){
                dq.push_back(stoi(tmp));
                tmp.clear();
            }
        }

        bool valid = true;
        bool forward = true;
        for(auto op : s){
            if(op == 'R')
                forward = forward ? false : true;
            else if(op == 'D'){
                if(dq.empty()){
                    cout << "error\n";
                    valid = false;
                    break;
                }
                else if(forward)
                    dq.pop_front();
                else if(!forward)
                    dq.pop_back();
            }
        }
        if(!forward)
            reverse(dq.begin(), dq.end());

        if(!valid)
            continue;

        cout << "[";
        while(!dq.empty()){
            cout << dq.front();
            dq.pop_front();
            if(!dq.empty())
                cout << ",";
        }
        cout << "]\n";
    }
}