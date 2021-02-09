#include <iostream> 
using namespace std;

int main(){
    char c;
    cin >> c;

    if(isalnum(c) || isalpha(c))
        cout << (int)c;
}