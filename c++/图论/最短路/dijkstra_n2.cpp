struct Dijkstra
{
    #define type int
    const type inf=INF;
    struct node{int id;type v;};
    static const int N=MAX;
    vector<node> mp[N];
    type dis[N];
    int n,vis[N];
    void init(int _n)
    {
        n=_n;
        for(int i=0;i<=n;i++) mp[i].clear();
    }
    void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
    void work(int s)
    {
        int i,j,x,to;
        type mn,w;
        for(i=0;i<=n;i++)
        {
            dis[i]=inf;
            vis[i]=0;
        }
        dis[s]=0;
        for(i=1;i<=n;i++)
        {
            x=0;
            mn=inf;
            for(j=1;j<=n;j++)
            {
                if(!vis[j]&&dis[j]<mn)
                {
                    x=j;
                    mn=dis[j];
                }
            }
            if(mn==inf) return;
            vis[x]=1;
            for(auto &it:mp[x])
            {
                to=it.id;
                w=it.v;
                dis[to]=min(dis[to],dis[x]+w);
            }
        }
    }
    #undef type
}dij;

