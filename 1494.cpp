#include <iostream>
#include <stack>
using namespace std;

int main () {
    stack <int> arr;
    int N;
    cin >> N;
    int a;
    int max = 0;
    int check = 0;
    for (int i = 0; i < N; i ++) {
        cin >> a;
        if (a > max) {
            for (int k = max + 1; k < a; k ++) arr.push(k);
            max = a;
        }
        else{
            if (a == arr.top()) arr.pop();
            else check++;
        }
    }
    if (check<=0) cout << "Not a proof" << endl;
    else cout << "Cheater" << endl;
    return 0;
}
