#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int x = 666;
    int count = 0;
    while(true){
        string s = to_string(x);
        if(s.find("666") != -1)
            count++;
        if(count == n)
            break;
        x++;
    }
    printf("%d", x);
}