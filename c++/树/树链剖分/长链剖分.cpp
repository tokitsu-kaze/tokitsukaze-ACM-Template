struct Long_Chain_Decomposition
{
	#define type int
	vector<int> *mp;
	int son[MAX],top[MAX];
	type dep[MAX],v[MAX];
	void dfs1(int x,int pre)
	{
		son[x]=-1;
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dfs1(to,x);
			if(son[x]==-1||dep[to]>dep[son[x]]) son[x]=to;
		}
		if(son[x]!=-1) dep[x]=dep[son[x]]+1;
		else dep[x]=1;
	}
	void dfs2(int x,int tp,int pre)
	{
		top[x]=tp;
		if(son[x]==-1) return;
		dfs2(son[x],tp,x);
		for(auto &to:mp[x])
		{
			if(to==pre||to==son[x]) continue;
			dfs2(to,to,x);
		}
	}
	void work(int rt,vector<node> *_mp)
	{
		mp=_mp;
		dfs1(rt,0);
		dfs2(rt,rt,0);
	}
	#undef type
}lcd;
/*
lcd.work(rt,mp);
*/
