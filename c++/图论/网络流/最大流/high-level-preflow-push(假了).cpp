struct High_Level_Preflow_Push
{
	static const int N=2020;
	struct node{int to,rev,cap;};
	vector<node> mp[N];
	type h;
	int cnt[N],s,t,work;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type cap)
	{
		mp[x].pb({y,mp[y].size(),cap});
		mp[y].pb({x,mp[x].size()-1,0});
	}
	void update_height(int x,type newh)
	{
	    work++;
	    if(h[x]!=inf) cnt[h[x]]--;
	    h[x]=newh;
	    if(newh==inf) return;
	    cnt[newh]++;
	    ht=newh;
	    gap[newh].pb(x);
	    if(rest[x]) lst[newh].pb(x);
	}
	void relabel()
	{
		int i,x;
	    work=0;
	    for(i=0;i<=ht;i++)
	    {
	    	h[i]=inf;
	    	cnt[i]=0;
	    	lst[i].clear();
	    	gap[i].clear();
		}
	    h[t]=0;
	    queue<int> q;
	    q.push(t);
	    while(!q.empty())
		{
	        x=q.front();
	        q.pop();
	        for(auto &e:mp[x])
	        {
	            if(h[e.to]==inf&&mp[e.to][e.rev].cap)
				{
	                q.push(e.to);
	                update_height(e.to,h[x]+1);
	            }
	        }
	        ht=h[x];
	    }
	}
	void push(int x,node &e)
	{
	    if(rest[e.to]==0) lst[h[e.to]].pb(e.to);
	    type tmp=min(rest[x],e.cap);
	    e.cap-=tmp;
	    mp[e.to][e.rev].cap+=tmp;
	    rest[x]-=tmp;
	    rest[e.to]+=tmp;
	}
	void push_flow(int u)
	{
	    type newh=inf;
	
	    for (Edge &e : mp[u])
	        if (e.cap)
	            if (h[u] == h[e.to] + 1) {
	                Push(u, e);
	
	                if (rest[u] <= 0)
	                    return;
	            } else
	                nh = min(nh, h[e.to] + 1);
	
	    //一边往外流一边以防万一要更新，收集最小值
	    if (cnt[h[u]] > 1)
	        Update_height(u, nh);        //没断层，直接更新
	    else
	        for (int i = h[u]; i < N; i++) {    //断层了，高度高的全往S流
	            for (int j : gap[i])
	                Update_height(j, INF);
	
	            gap[i].clear();
	        }
	}
	int HLPP() {
	    memset(rest, 0, sizeof(rest));
	    rest[S] = 2147483647;
	    Relabel();
	
	    for (Edge &e : mp[S])        //从源点往外推
	        Push(S, e);
	
	    for (; ~ht; --ht)
	        while (!lst[ht].empty()) {      //枚举高度，从高到底依次往外推
	            int u = lst[ht].back();
	            lst[ht].pop_back();
	            Push_Flow(u);
	
	            if (work > 20000)
	                Relabel();        //如果改变得过多了那么就重新标记
	        }
	
	    return rest[T];
	}
}hlpp;
