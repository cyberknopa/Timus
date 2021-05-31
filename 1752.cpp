#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int Pos[20001];
int paths[20001];
pair<int,int> dep[20001];
vector<int> parents[20001];
vector<int> children[20001];
pair<int,int> deep_chld[20001];
int ances[20001];
int cn = 0;

void dfs(int u){
	deep_chld[u].first = 0;
	deep_chld[u].second = 0;
	int n = parents[u][0];
	for(int i = 0; n && i < parents[n].size(); i++){
        n = parents[n][i];
        parents[u].push_back(n);
    }
	if(parents[u][0]) 
		children[u].erase(find(children[u].begin(),children[u].end(), parents[u][0]));
    for(int i = 0; i < children[u].size(); i++){
        int c = children[u][i];
		dep[c].first = dep[u].first + 1;
        parents[c].push_back(u);
        dfs(c);
        if(dep[c].second > dep[deep_chld[u].second].second){
            if(dep[c].second > dep[deep_chld[u].first].second){
                deep_chld[u].second = deep_chld[u].first;
                deep_chld[u].first = c;
            }
            else 
				deep_chld[u].second = c;
        }
    }
    dep[u].second = max(dep[u].first, max(dep[deep_chld[u].second].second, dep[deep_chld[u].first].second));
}

void dfs_2(int u){
    if(parents[u][0] && deep_chld[parents[u][0]].first == u){
        Pos[u] = Pos[parents[u][0]] + 1;
        paths[Pos[u]] = u;
    }else{
        Pos[u] = cn;
        paths[Pos[u]] = u;
        cn += dep[u].second - dep[u].first + 1;
    }
    if (parents[u][0]) {   
        int ni;
		if (deep_chld[parents[u][0]].first == u) 
			ni = deep_chld[parents[u][0]].second;
        else 
			ni = deep_chld[parents[u][0]].first;
		if (ances[parents[u][0]] != 0 && (dep[ni].second - dep[ni].first < dep[ances[parents[u][0]]].second + dep[u].first - 2*dep[ances[parents[u][0]]].first) || ni == 0)
			ances[u] = ances[parents[u][0]];
        else 
			ances[u] = ni;
    }
    for (int i = 0; i < children[u].size(); i++) dfs_2(children[u][i]);
}


int answer(int u, int d){
	if (d > dep[u].second - dep[u].first){
		if (d < dep[u].first){
			for (int i = 0; ; i++){
				if (d == 0) 
					break;
				if (d % 2 == 1) 
					u = parents[u][i];
				d /= 2;
			}
			return u;
		}else{
			if (ances[u] == 0)
				return 0;
			else{
				if (ances[u] != 0 && d <= dep[u].first - dep[ances[u]].first + dep[ances[u]].second - dep[ances[u]].first + 2)
					return paths[d - dep[u].first + dep[ances[u]].first - 2 + Pos[ances[u]]];
				else
					return 0;
			}
		}
	}else
		return paths[Pos[u] + d];
}


int main(){
	
	int N, m, u, v;
	cin >> N >> m;
	for (int i = 1; i < N; i++){
		cin >> u >> v;
		children[u].push_back(v);
		children[v].push_back(u);
	}
	
	parents[1].push_back(0);
	ances[1] = 0;
	Pos[1] = cn;
	dep[1].first = 1;
	
	dfs(1);
	dfs_2(1);

	
	int distance;
	vector<int> a;
	
	for (int i = 0; i < m; i++){
		cin >> u >> distance;
		a.push_back(answer(u, distance));
	}
	
	for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
	return 0;
}
