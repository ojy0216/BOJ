#include <iostream>
#include <vector>
using namespace std;

void f(vector<int> prev, vector<int> main, int level){
    if(level == 1 && !prev.empty()){
        for(auto mit = main.begin(); mit != main.end(); mit++){
            if(prev.back() > *mit)
                continue;
            for(auto pit = prev.begin(); pit != prev.end(); pit++)
                cout << *pit << " ";
            cout << *mit << '\n';
        }
    }
    else if(level == 1 && prev.empty()){
        for(auto mit = main.begin(); mit != main.end(); mit++)
            cout << *mit << '\n';
    }
    else{
        for(auto mit = main.begin(); mit != main.end(); mit++){
            int tmp = *mit;
            if(!prev.empty() && prev.back() > tmp)
                continue;
            prev.push_back(tmp);    
            f(prev, main, level - 1);
            prev.pop_back();
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v, p;
    for(int i = 0; i < n; i++)
        v.push_back(i + 1);

    f(p, v, m);
}