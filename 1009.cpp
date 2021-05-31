#include <iostream>
using namespace std;

int recursion_counter (int n, int k){
    if (n == 0) return 0;
    else if (n == 1) return k-1;
    else if (n == 2) return (k-1)*k;
    else return (k-1)*recursion_counter(n-1,k)+(k-1)*recursion_counter(n-2,k);
}
int main()
{
    int N, K;
    cin >> N >> K;
    cout << recursion_counter(N, K);
    return 0;
}
