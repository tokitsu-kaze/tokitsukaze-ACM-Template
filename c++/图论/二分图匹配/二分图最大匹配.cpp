/*
最小点覆盖的点数=最大匹配数
最小路径覆盖的边数=顶点数n-最大匹配数
最大独立集=最小路径覆盖=顶点数n-最大匹配数
*/
struct Bipartite_Matching
{
	static const int N=;
	static const int M=;
	int n,m;
	vector<int> mp[N];
	int flag[N],s[N],link[M],used[M];
	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int a,int b){mp[a].push_back(b);}
	bool dfs(int x,int timetag)
	{
		int i,to;
		flag[x]=1;
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(used[to]==timetag) continue;
			used[to]=timetag;
			if(link[to]==-1||dfs(link[to],timetag))
			{
				link[to]=x;
				s[x]=to;
				return 1;
			}
		}
		return 0;
	}
	int max_match()
	{
		int i,res;
		memset(link,-1,sizeof link);
		memset(s,-1,sizeof s);
		memset(used,0,sizeof used);
		res=0;
		for(i=1;i<=n;i++)
		{
			if(mp[i].size()==0) continue;
			if(dfs(i,i)) res++;
		}
		return res;
	}
	int min_cover(vector<int> &x,vector<int> &y)
	{
		int i,res;
		res=max_match();
		memset(flag,0,sizeof flag);
		memset(used,0,sizeof used);
		x.clear();
		y.clear();
		for(i=1;i<=n;i++)
		{
			if(s[i]==-1) dfs(i);
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) x.push_back(i);
		}
		for(i=1;i<=m;i++)
		{
			if(used[i]) y.push_back(i);
		}
		return res;
	}
}bpm;
/*
O(n*m)
bpm.init(n,m);
bpm.add_edge(a,b); a:left,1-n   b:right,1-m
*/
