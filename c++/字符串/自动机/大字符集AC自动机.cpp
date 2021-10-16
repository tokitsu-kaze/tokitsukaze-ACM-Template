struct AC_Automaton
{
	map<int,int> nex[MAX];
	VI toplist;
	int fail[MAX],last[MAX],cnt[MAX];
	int root,tot;
	int newnode()
	{
		tot++;
		nex[tot].clear();
		return tot;
	}
	void init()
	{
		toplist.clear();
		tot=0;
		root=newnode();
	}
	void insert(VI &s)
	{
		int len,now,i;
		len=sz(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=s[i];
			if(!nex[now].count(t)) nex[now][t]=newnode();
			now=nex[now][t];
		}
		cnt[now]=1;
	}
	void work()
	{
		int i,now;
		queue<int>q;
		for(auto it:nex[root])
		{
			fail[it.se]=root;
			q.push(it.se);
		}
		fail[root]=1;
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			toplist.pb(now);
			//suffix link
		/*	if(cnt[fail[now]]) last[now]=fail[now];
			else last[now]=last[fail[now]];*/
			cnt[now]+=cnt[fail[now]];
			for(auto it:nex[now])
			{
				int fail_now=fail[now];
				while(fail_now>1&&!nex[fail_now].count(it.fi)) fail_now=fail[fail_now];
				if(nex[fail_now].count(it.fi)) fail[it.se]=nex[fail_now][it.fi];
				else fail[it.se]=root;
				q.push(it.se);
			}
		}
	}
	int query(VI& s,int x)
	{
		int len,now,i,res;
		len=sz(s);
		now=root;
		res=0;
		for(i=0;i<len;i++)
		{
			int t=s[i];
			while(now>1&&!nex[now].count(t)) now=fail[now];
			if(nex[now].count(t)) now=nex[now][t];
			else now=root;
			//do something
		}
		return res;
	}
	void toptrans()
	{
		for(int i=sz(toplist)-1;~i;i--)/*do something*/;
	}
}ac;
