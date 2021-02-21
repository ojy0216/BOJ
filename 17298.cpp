#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for(auto& i : v)
        scanf("%d", &i);

    vector<int> NGE(n, -1);

    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && v[s.top()] < v[i]){
            NGE[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for(auto i : NGE)
        printf("%d ", i);
}