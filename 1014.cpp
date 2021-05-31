#include <iostream>
#include <array>
using namespace std;

int main() {
    int num;
    array<int, 9> mycount = {0, 0, 0, 0 , 0, 0, 0 , 0 ,0 };
    cin >> num;

    if (num == 0) {
        cout << 10;
        return 0;
    }

    if (num == 1)
        cout << 1;

    for (int i = 8; i > 0; i--) {
        while (num % (i+1) == 0) {
            num/= i+1;
            mycount[i]++;
        }
    }
    if (num == 1) {
        for (int i = 1; i <= 8; i++) {
            while (mycount[i] != 0) {
                mycount[i]--;
                cout << i+1;
            }
        }
    }
    else
        cout << -1;
    return 0;
}
