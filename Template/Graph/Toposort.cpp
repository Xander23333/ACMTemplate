struct TopoSort{
    int c[10000];
    int G[100][100];
    int topo[10000], t ,n;
    void init(){
        memset(c,0,sizeof (c));
        memset(G,0,sizeof (G));
        memset(topo,0,sizeof (topo));
    }
    bool dfs(int u){
        c[u] = -1;
        for(int v = 0; v < n; ++v){
            if (G[u][v]){
                if (c[v] < 0) return false;
                else if (!c[v] && !dfs(v)) return false;
            }
        }
        c[u] = 1;
        topo[--t] = u;
        return true;
    }
    bool go(int x){
        t = n = x;
        for(int u = 0; u < n; u ++) if (!c[u])
            if (!dfs(u)) return false;
        return true;
    }
}toposort;