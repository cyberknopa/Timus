#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool srt_by_population(pair<int, int> c1, pair<int, int> c2){
	if (c1.second == c2.second) return c1.first < c2.first;
	return c1.second < c2.second;
}

int main(){
	
	vector<pair<int, int>> data;
	vector<int> res;
	vector<pair<int, int>>::iterator lower, upper;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int count;
		cin >> count;
		pair<int, int> city = make_pair(i+1, count);
		data.push_back(city); 
	}
	sort(data.begin(), data.end(), srt_by_population);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++){
		int l, r, x;
		cin >> l >> r >> x;
		lower = lower_bound(data.begin(), data.end(), make_pair(l, x), srt_by_population);
		upper = upper_bound(data.begin(), data.end(), make_pair(r, x), srt_by_population);
		if (lower != upper) res.push_back(1);
		else res.push_back(0);
	}
	for (int i = 0; i < num; i++) 
		cout << res[i];
	return 0;	
}
