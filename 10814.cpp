#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _info{
    int num, age;
    string name; 
} Info;

bool compare(Info a, Info b){
    if(a.age == b.age)
        return a.num < b.num;
    else
        return a.age < b.age;
}

int main(){
    int n;
    cin >> n;

    vector<Info> v;
    for(int i = 0; i < n; i++){
        int age;
        string name;
        cin >> age >> name;
        Info tmp;
        tmp.num = i;
        tmp.age = age;
        tmp.name = name;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), compare);

    for(auto it = v.begin(); it != v.end(); it++)
        cout << (*it).age << " " << (*it).name << '\n';
}