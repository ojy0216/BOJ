#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string w[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };

    string b[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    };

    string *p = new string [n];
    for(int i = 0; i < n; i++)
        cin >> p[i];

    // for(int i = 0; i < n; i++)
    //       cout << p[i] << '\n';

    int min_count = 64;
    for(int x = 0; x <= m - 8; x++){
        for(int y = 0; y <= n - 8; y++){
            int black_count = 0, white_count = 0;
            for(int dx = 0; dx < 8; dx++){
                for(int dy = 0; dy < 8; dy++){
                    if(p[y + dy][x + dx] != b[dy][dx])
                        black_count++;
                    if(p[y + dy][x + dx] != w[dy][dx])
                        white_count++;
                }
            }
            if(min(white_count, black_count) < min_count)
                min_count = min(white_count, black_count);
        }
    }

    cout << min_count;

    delete [] p;
}