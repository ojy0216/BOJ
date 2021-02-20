#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        map<string, int> m;
        for(int j = 0; j < n; j++){
            string kind, name;
            cin >> name >> kind;

            if(m.find(kind) == m.end())
                m.insert(make_pair(kind, 1));
            else
                m[kind]++;
        }

        int result = 1;
        for(auto i : m)
            result *= (i.second + 1);
        cout << result - 1 << endl;
    }
}