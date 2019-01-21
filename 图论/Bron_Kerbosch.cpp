struct Bron_Kerbosch
{
	static const int N=;
	bitset<N> MASK,ZERO,mp[N];
	int n,cnt_clique;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].reset();
		ZERO.reset();
		MASK=ZERO;
		MASK.flip();
	}
	void add_edge(int a,int b) //0~n-1 , undir
	{
		if(a==b) return;
		mp[a][b]=mp[b][a]=1;
	}
	void dfs(bitset<N> now,bitset<N> some,bitset<N> none)
	{
		if(some.none()&&none.none())//one maximal clique
		{
			cnt_clique++;
			return;
		}
		bitset<N> r=some;
		bool fi=1;
		for(int i=0;i<n;i++)
		{
			if(!r[i]) continue;
			if(fi)
			{
				fi=0;
				r&=mp[i]^MASK;
			}
			now[i]=1;
			dfs(now,some&mp[i],none&mp[i]);
			now[i]=0;
			some[i]=0;
			none[i]=1;
		}
	}
	int count_maximal_clique()
	{
		cnt_clique=0;
		bitset<N> now;
		dfs(now,MASK,ZERO);
		return cnt_clique;
	}
}bk;
/*
undirected graph
bk.init(n);
bk.add_edge(a,b); a,b: 0~n-1
*/
