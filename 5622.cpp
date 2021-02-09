#include <iostream>
using namespace std;

int f(char c){
    if(c <= 'C')
        return 2;
    else if(c <= 'F')
        return 3;
    else if(c <= 'I')
        return 4;
    else if(c <= 'L')
        return 5;
    else if(c <= 'O')
        return 6;
    else if(c <= 'S')
        return 7;
    else if(c <= 'V')
        return 8;
    else return 9;
}

int main(){
    string s;
    cin >> s;

    int time = 0;
    for(int i = 0; i < s.length(); i++)
        time += (1 + f(s[i]));

    cout << time;
}