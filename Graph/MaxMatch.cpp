vector<int> v[maxn];
int cy[maxn];
bool vis[maxn];
bool check(int rt) {
    int sz = v[rt].size();
    for (int i = 0; i < sz; ++i) {
        int vv = v[rt][i];
        if (vis[vv]) continue;
        vis[vv] = true;
        if (cy[vv] == -1 || check(cy[vv])) {
            cy[vv] = rt;
            return true;
        }
    }
    return false;
}
int dfs(int n) {
    int ret = 0;
    memset(cy, -1, sizeof(cy));
    for (int i = 0; i < n; ++i) {
        memset(vis, 0, sizeof(vis));
        ret += check(i);
    }
    return n - ret;
}