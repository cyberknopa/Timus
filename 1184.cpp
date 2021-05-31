#include <iostream>
#include <cmath>
using namespace std;

double max_of(double* a, int N1, int K1, double lef, double righ){
    righ = righ/K1;
    double siz;
    while (righ- lef> 0.000001){
        siz = (righ+lef)/2;
        int count = 0;
        for (int i = 0; i < N1; i++)
            count += (int)(a[i]/siz);
        if (count >= K1)
            lef = siz;
        else righ = siz;
    }
    return righ;
}
int main(){
    int N, K;
    double  sum = 0;
    cin >> N;
    cin >> K;
    double *cab = new double[N];
    for (int i = 0; i<N; i++){
        cin >> cab[i];
        sum += cab[i];
    }
    double res = max_of(cab, N, K, 0, sum);
    printf("%.2lf\n", floor(res*100)/100);
    return 0;
}
