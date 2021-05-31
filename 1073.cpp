#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maximum = 2000000000;

int main()
{
    int N, i, j;
    cin >> N;
    vector<int> result( N+1, maximum);
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;
    for(i = 1; i <= N; i++ ) {
        for (j = 1; j * j <= i; j++)
            result[i] = min(result[i], 1 + result[i - j * j]);
    }
    cout << result[N];
    return 0;
}
