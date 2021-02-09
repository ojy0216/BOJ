#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;

    int i = 1, n = 0;
    int a , b = 1;
    while(true){
        if(x <= n){
            i--;
            if(i % 2 == 0){
                a = i - (n - x);
                b = 1 + (n - x);
            }
            else{
                a = 1 + (n - x);
                b = i - (n - x);
            }
            break;
        }
        n += i;
        i++;
    }
    std::cout << a << "/" << b;
}