#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

constexpr int maxLength = 1000;

int arr[maxLength + 1][maxLength + 1] = {0, };

int main(){
    //string s1("ACAYKP"), s2("CAPCAK");
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int s1Length = s1.length(), s2Length = s2.length();

    for(int i = 1; i < s2Length + 1; i++){
        for(int j = 1; j < s1Length + 1; j++){
            if(s1[j - 1] == s2[i - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }

    /* 
    for(int i = 0; i < s2Length + 1; i++){
        for(int j = 0; j < s1Length + 1; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    */
    

    int posX = s1Length, posY = s2Length;
    int length = 0;
    // string result;
    while(true){
        if(arr[posY][posX] == 0)
            break;

        if(arr[posY][posX] == arr[posY - 1][posX])
            posY--;
        else if(arr[posY][posX] == arr[posY][posX - 1])
            posX--;
        else{
            length++;
            // result.insert(result.begin(), s1[posX - 1]);
            posX--;
            posY--;
        }
    }
    // cout << result << endl;
    printf("%d", length);
}