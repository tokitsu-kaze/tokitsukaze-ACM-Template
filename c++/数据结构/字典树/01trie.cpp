struct Trie
{
	#define type int
	static const int mx=30;
	int root,tot,nex[MAX*mx][2];
	type cnt[MAX*mx];
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		memset(nex[0],0,sizeof nex[0]);
		cnt[0]=0;
		tot=1;
		root=newnode();
	}
	void upd(type x,type v)
	{
		int id,t,i;
		id=root;
		for(i=mx;~i;i--)
		{
			t=(x>>i)&1;
			if(!nex[id][t]) nex[id][t]=newnode();
			id=nex[id][t];
			cnt[id]+=v;
		}
	}
	type count(int x)
	{
		int id,t,i;
		id=root;
		for(i=mx;~i;i--)
		{
			t=(x>>i)&1;
			if(!nex[id][t]) return 0;
			id=nex[id][t];
		}
		return cnt[id];
	}
	type ask_max(type x)
	{
		int id,t,i;
		type res;
		id=root;
		res=0;
		for(i=mx;~i;i--)
		{
			t=(x>>i)&1;
			if(nex[id][t^1]&&cnt[nex[id][t^1]]) t^=1;
			res|=(t<<i);
			id=nex[id][t];
		}
		return res;
	}
	type ask_min(type x)
	{
		int id,t,i;
		type res;
		id=root;
		res=0;
		for(i=mx;~i;i--)
		{
			t=(x>>i)&1;
			if(!nex[id][t]||!cnt[nex[id][t]]) t^=1;
			res|=(t<<i);
			id=nex[id][t];
		}
		return res;
	}
	#undef type
}tr;
