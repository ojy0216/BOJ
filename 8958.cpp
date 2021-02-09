#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(1);
    string in;
    int score, myScore;

    for(int i = 0; i < n; i++){
        getline(cin, in);
        score = 1;
        myScore = 0;
        for(int j = 0; j < in.length(); j++){
            if(in[j] == 'O'){
                myScore += score;
                score++;
            }
            else
                score = 1;
        }
        cout << myScore << endl;
    }
}