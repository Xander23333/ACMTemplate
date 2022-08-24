
struct arr {
    int nd, nx, co;
} bot[2500000];
int k;
int head[1500000], SF[1500000], f[1500000], dist[1500000], vis[1500000],a[150000];
int n, m, cnt;
inline void add(int a, int b, int c) {
    bot[++cnt].nd = b;
    bot[cnt].nx = head[a];
    bot[cnt].co = c;
    head[a] = cnt;
}
inline void SPFA(int s) {
    deque<int> q;
    for (register int i = 1; i <= n; ++i) dist[i] = 0x3f3f3f3f, vis[i] = 0;
    dist[s] = 0;
    vis[s] = 1;
    q.push_back(s);
    while (!q.empty()) {
        int u = q.front();
        int v;
        q.pop_front();
        vis[u] = 0;
        for (register int i = head[u]; i; i = bot[i].nx) {
            if (dist[v = bot[i].nd] == dist[u] + bot[i].co) {
                if (vis[v])
                    f[v] += f[u], f[v] %= mod;
                else
                    f[v] = f[u];
                SF[v] += SF[u];
                SF[v] %= mod;
            }
            if (dist[v = bot[i].nd] > dist[u] + bot[i].co) {
                dist[v] = dist[u] + bot[i].co;
                f[v] = f[u];
                SF[v] = SF[u];
                if (!vis[v]) {
                    vis[v] = 1;
                    if (q.empty() || dist[v] > dist[q.front()])
                        q.push_back(v);
                    else
                        q.push_front(v);
                }
            }
        }
    }
}