
//мой
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> gr[50001];
int dynamic[50001][20], f_c[50001], s_c[50001], depth[50001], p[50001];
int coun;
int logg;

void DFS(int v, int d){
	depth[v] = d;
	f_c[v] = coun++;
	dynamic[v][0] = p[v];
	for (int i = 1; i <= logg; i++)
		dynamic[v][i] = dynamic[dynamic[v][i-1]][i-1];
	for (int i = 0; i < gr[v].size(); i++){
		int next = gr[v][i].first;
		if (next != p[v]){
			p[next] = v;
			DFS(next, d+gr[v][i].second);
		}
	}
	s_c[v] = coun++;
}

int find_lca(int a, int b){
	if (f_c[a] <= f_c[b] && s_c[a] >= s_c[b])
		return a;
	else
		if (f_c[b] <= f_c[a] && s_c[b] >= s_c[a])
			return b;
	for (int i = logg; i >= 0; i--){
		if (!(f_c[dynamic[a][i]] <= f_c[b] && s_c[dynamic[a][i]] >= s_c[b]))
			a = dynamic[a][i];
	}
	return dynamic[a][0];
}

int main(){
	int n, m;
	cin >> n;
	logg = 1;
	for (;;){
		if ((1<<logg) > n) break;
		logg++;
	}
	for (int i = 0; i < n-1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		gr[u].push_back(make_pair(v, w));
		gr[v].push_back(make_pair(u, w));
	}
	p[0] = 0;
	DFS(0, 0);
	cin >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		cout << depth[u] + depth[v] - 2*depth[find_lca(u, v)] << endl;
	}
	return 0;
}
