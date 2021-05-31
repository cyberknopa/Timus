#include <iostream>
using namespace std;

int main(){
    float a0, an1, sum, c, res;
    sum = 0;
    int N;
    cin >> N;
    cin >> a0;
    cin >> an1;
    for (int i = 1; i < N+1; i++) {
        cin >> c;
        sum = sum + (N + 1 - i)*c;
    }
    res = (an1 + N * a0 - sum*2) / (N + 1);
    printf("%.2f", res);
    return 0;
}
