#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int	M, lastn;
	int vvod[25000];
	cin >> M;
	for(int i=0; i<= 25001 ;i++) {
        cin >> vvod[i];
        if(vvod[i]==-1) break;
        else  lastn = i;
    }
	for(int *it = vvod; it + M != vvod + lastn + 2; it++)
		cout << *max_element(it,it+M) << '\n';
	return 0;
}
