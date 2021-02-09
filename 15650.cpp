#include <iostream>
#include <vector>
using namespace std;

void f(vector<int> prev, vector<int> main, int level){
    if(level == 1 && !prev.empty()){
        for(auto mit = main.begin(); mit != main.end(); mit++){
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
        for(auto mit = main.begin(); mit != main.end(); ){
            int tmp = *mit;
            mit = main.erase(mit);
            prev.push_back(tmp);    
            f(prev, main, level - 1);
            prev.pop_back();
            // main.insert(mit, tmp);
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