#include <bits/stdc++.h>
 
using namespace std;
 
struct seg{
    int id, left, right;
};
 
bool compare(seg a, seg b){
	if (a.left == b.left)
		return a.right < b.right;
	else return a.left < b.left;
	
}
 
int n, cnt = 0;
 
seg arr[500];
vector <int> rights(502, -1e9);
vector<int> lefts(502, -1e9);
 
void solution(){
	
    rights[0] = 1e9; 
    for (int i = 0; i < n; i++){
		int l = 0, u = arr[i].right, r = cnt, mid;
        while( l <= r )
        {
            mid = (l + r)/2;
            if(rights[mid] > u) l = mid+1;
            else r = mid - 1;
        }
        rights[l] = u;
        lefts[i] = l;
        cnt = max(cnt, l);
    }
}
 
int main(){
    cin >> n;
 
    for (int i = 0; i < n; i++){
        arr[i].id = i;
        cin >> arr[i].left >> arr[i].right;
    }
	sort(arr, arr+n, compare);
 
    solution();
 
    cout << cnt << '\n';
    int last = -1e9;
    for(int i = n-1; i > -1; i--){
        if(lefts[i] == cnt && arr[i].right > last){
            cout << arr[i].id+1 << ' ';
            cnt--;
        }
    }
	return 0;
 
}
