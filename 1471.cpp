#include <iostream>
#include <vector>

using namespace std;
#define MAX 500001
vector<pair<int,int> > g[MAX];
int d[MAX], f[MAX], dist[MAX];
int up[MAX][20];
int l, u, v, i, n, w, lca, timer, res, m;
void dfs (int v, int p = 0, int len = 0)
{
    int i, to;
    d[v] = timer++;
    up[v][0] = p; dist[v] = len;

    for(i = 1; i <= l; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    for(i = 0; i < g[v].size(); i++)
    {
        to = g[v][i].first;
        if (to != p) dfs (to, v, len + g[v][i].second);
    }
    f[v] = timer++;
}

int Parent(int a, int b)
{
    return (d[a] <= d[b]) && (f[a] >= f[b]);
}

int LCA (int a, int b)
{
    if (Parent(a, b)) return a;
    if (Parent(b, a)) return b;
    for (int i = l; i >= 0; i--)
        if (!Parent(up[a][i], b)) a = up[a][i];
    return up[a][0];
}

int main(){
    scanf("%d",&n);
    l = 1;
    while ((1 << l) <= n)  l++;
    for(i = 0; i < n - 1; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    dfs(0);
    scanf("%d",&m);
    for(i = 0; i < m; i++)
    {
        scanf("%d %d",&u,&v);
        lca = LCA(u, v);
        res = dist[u] - dist[lca] + dist[v] - dist[lca];
        printf("%d\n",res);
    }
    return 0;
}
