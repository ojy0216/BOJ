#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int>& a){
    long long int sum = 0;
    for(auto it = a.begin(); it != a.end(); it++)
        sum += (*it);
    
    return sum;
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};

    cout << sum(v);
}