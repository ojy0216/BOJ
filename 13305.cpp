#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<long long> distance(n - 1);
    for(auto& i : distance)
        cin >> i;

    vector<long long> price(n);
    for(auto& i : price)
        cin >> i;

    auto nowPrice = price[0];
    long long result = 0;

    for(int i = 0; i < n - 1; i++){
        if(price[i] < nowPrice)
            nowPrice = price[i];
        result += nowPrice * distance[i];
    }

    cout << result;
}