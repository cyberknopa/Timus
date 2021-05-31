#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<short int>> dig_cnt(1000, vector<short int>(9000, 0));
	vector<vector<short int>> last_dig(1000, vector<short int>(9000, 0));
    int t, s1, s2, d, n, a, b, k, i, j;
    cin >> t;
    last_dig[0][0] = 1;
    for (i = 1; i < 1000; i++) {
        for (j = 1; j < 9000; j++) {
            dig_cnt [i][j] = 101;
            for (k = 1; k < 10; k++) {
                if (i - k >= 0 && j - k * k >= 0 && last_dig[i - k][j - k * k] != 0 && dig_cnt[i - k][j - k * k] + 1 < dig_cnt[i][j]){
                    last_dig [i][j] = k;
                    dig_cnt [i][j] = dig_cnt [i - k][j - k * k] + 1;
                }
            }
        }
    }


    while (t > 0) {
        t--;
        cin >> s1 >> s2;
        if (s1 > 900 || s2 > 8100 || dig_cnt [s1][s2] > 100) {
            cout << "No solution" << endl;
            continue;
        }
        n = dig_cnt [s1][s2];
        while (n > 0){
			n--;
            d = last_dig[s1][s2];
            cout << d;
            s1 -= d;
            s2 -= d * d;
        }
        cout << '\n';
    }
    return 0;
}
