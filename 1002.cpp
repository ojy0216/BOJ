#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dx = x1 - x2;
        int dy = y1 - y2;

        if(r1 > r2)
            swap(r1, r2);

        int add = (r1 + r2) * (r1 + r2);
        int sub = (r2 - r1) * (r2 - r1);
        int turret_distance = dx * dx + dy * dy;

        if(turret_distance < add && turret_distance > sub)
            cout << "2\n";
        else if(turret_distance == add || (turret_distance == sub && turret_distance != 0))
            cout << "1\n";
        else if(turret_distance < sub || turret_distance > add)
            cout << "0\n";
        else if(turret_distance == 0){
            if(r1 == r2)
                cout << "-1\n";
            else
                cout << "0\n";
        }
    }
}