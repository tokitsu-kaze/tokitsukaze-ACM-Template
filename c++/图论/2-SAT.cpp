struct Tow_SAT
{
	static const int N=MAX;
	int n;
	vector<int> mp[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=2*n;i++) mp[i].clear();
	}
	void add_edge(int a,int b){mp[a].push_back(b);}
	bool work(int *res)
	{
		int i;
		scc.work(2*n,mp);
		for(i=1;i<=n;i++)
		{
			if(scc.col[i]==scc.col[i+n]) return 0; // no solution
			if(scc.col[i]<scc.col[i+n]) res[i]=1;
			else res[i]=0;
		}
		return 1;
	}
}sat;
/*
MAX > 2*n
sat.init(n);
sat.work(int *res);

sat.add_edge(a,b); -> if a is true, b must true
special:
a must false -> if a is true, a must false
a must true  -> if a is false, a must true
*/
