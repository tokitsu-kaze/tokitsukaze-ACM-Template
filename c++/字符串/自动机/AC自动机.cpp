struct AC_Automaton
{
	static const int K=26;//may need change
	int nex[MAX][K],fail[MAX],cnt[MAX],last[MAX];
	int root,tot;
	inline int getid(char c){return c-'a';}//may need change
	int newnode()
	{
		mem(nex[tot],0);
		fail[tot]=0;
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
		}
		cnt[now]++;
	}
	void work()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<K;i++)
		{
			if(nex[root][i]) q.push(nex[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			//suffix link
			if(cnt[fail[now]]) last[now]=fail[now];
			else last[now]=last[fail[now]];
			/*
			may need add something here:
			cnt[now]+=cnt[fail[now]];
			*/
			for(i=0;i<K;i++)
			{
				if(nex[now][i])
				{
					fail[nex[now][i]]=nex[fail[now]][i];
					q.push(nex[now][i]);
				}
				else nex[now][i]=nex[fail[now]][i];
			}
		}
	}
	int query(char *s)
	{
		int len,now,i,res;
		len=strlen(s);
		now=root;
		res=0;
		for(i=0;i<len;i++)
		{
			int t=getid(s[i]);
			now=nex[now][t];
			int tmp=now;
			while(tmp&&cnt[tmp]!=-1)
			{
				res+=cnt[tmp];
				cnt[tmp]=-1;
				tmp=last[tmp];
			}
		}
		return res;
	}
	//build fail tree 
	vector<int> mp[MAX];
	void build_tree()
	{
		for(int i=0;i<=tot;i++) mp[i].clear();
		for(int i=1;i<tot;i++) mp[fail[i]].pb(i);
	}
}ac;
