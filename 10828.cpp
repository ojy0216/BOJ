#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    stack<int> s;

    for(int i = 0; i < n; i++){
        string op;
        cin >> op;

        if(op == "push"){
            int operand;
            cin >> operand;
            s.push(operand);
        }
        else if(op == "pop"){
            if(s.empty())
                cout << "-1\n";
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if(op == "size")
            cout << s.size() << endl;
        else if(op == "empty")
            cout << s.empty() << endl;
        else{
            if(s.empty())
                cout << "-1\n";
            else
                cout << s.top() << endl;
        }
    }
}