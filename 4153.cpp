#include <iostream>
using namespace std;

int main(){
    while(true){
        int x, y, z;
        cin >> x >> y >> z;

        if(x + y + z == 0)
            break;

        if(x > y && x > z){
            if(y * y + z * z == x * x)
                cout << "right\n";
            else
                cout << "wrong\n"; 
        }
        else if(y > x && y > z){
            if(x * x + z * z == y * y)
                cout << "right\n";
            else
                cout << "wrong\n";
        }
        else{
            if(x * x + y * y == z * z)
                cout << "right\n";
            else
                cout << "wrong\n";
        }
    }
}