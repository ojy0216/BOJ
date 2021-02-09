#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point{
    int x, y;
public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    int getX(){return x;}
    int getY(){return y;}
};

bool compare(Point* a, Point* b){
    if(a->getX() == b->getX())
        return a->getY() < b->getY();
    else
        return a->getX() < b->getX();
}

int main(){
    int n;
    scanf("%d", &n);

    vector<Point*> v;
    for(int i = 0; i < n; i++){
        int tmpX, tmpY;
        scanf("%d %d", &tmpX, &tmpY);
        v.push_back(new Point(tmpX, tmpY));
    }

    sort(v.begin(), v.end(), compare);

    for(auto it = v.begin(); it != v.end(); it++){
        printf("%d %d\n", (*it)->getX(), (*it)->getY());
        delete *it;
    }
}