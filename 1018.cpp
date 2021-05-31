#include<iostream>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, int>> strct (101);
vector<vector<int> > cnt (101, vector<int>(101, -1));
vector<bool> go (101, false);
vector<vector<int> > apples (101, vector<int>(101, 0));
int N, Q, s1, s2, apple;

void dfs(int a) {
    go[a] = true;
    for(int i = 1; i <= N;i++) {
        if((!go[i]) && (apples[a][i] != 0)) {
            go[i] = true;
            if(strct[a].first.first == 0)
                strct[a].first.first = i;
            else
                strct[a].first.second = i;
            strct[i].second = apples[a][i];
            dfs(i);
        }
    }
}
int max_apples(int cur, int q) {
    if(cnt[cur][q] != -1) return cnt[cur][q];
    if(cur == 0 || q == 0){
        cnt[cur][q] = 0;
        return cnt[cur][q] ;
    }
    for(int i = 0; i <= q - 1; i++) {
        int l, r;
        l = max_apples(strct[cur].first.first, i);
        r = max_apples(strct[cur].first.second,q - i - 1);
        if(cnt[cur][q] < l+r)cnt[cur][q] = l + r;
    }
    cnt[cur][q] += strct[cur].second;
    return cnt[cur][q];
}
int main() {
    cin >> N >> Q;
    for(int i = 1; i < N; i++)
    {
        cin >> s1 >> s2 >> apple;
        apples[s1][s2] = apple;
        apples[s2][s1] = apple;
    }
    dfs(1);
    cout << max_apples(1, Q+1) << '\n';
    return 0;
}
