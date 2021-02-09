#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string n1, n2;
    vector<int> v;

    cin >> n1 >> n2;

    if(n1.length() < n2.length())
        n1.insert(0, n2.length() - n1.length(), '0');
    else
        n2.insert(0, n1.length() - n2.length(), '0');

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    bool carry = false;
    for(int i = 0; i < n1.length(); i++){
        int tmp = (n1[i] - '0') + (n2[i] - '0') +carry;
        if(tmp > 9)
            carry = true;
        else
            carry = false;
        v.push_back(tmp % 10);
    }
    if(carry)
        v.push_back(1);

    reverse(v.begin(), v.end());

    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it;
}