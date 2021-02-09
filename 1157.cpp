#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int arr[26] = {0, };
    for(int i = 0; i < s.length(); i++)
        arr[tolower(s[i]) - 'a']++;

    int max = arr[0], maxIdx = 0;
    for(int i = 1; i < 26; i++){
        if(arr[i] > max){
            max = arr[i];
            maxIdx = i;
        }
    }

    int maxCount = 0;
    for(int i = 0; i < 26; i++){
        if(arr[i] == max)
            maxCount++;
    }

    if(maxCount != 1)
        cout << "?";
    else
        cout << (char)(maxIdx + 'A'); 
}