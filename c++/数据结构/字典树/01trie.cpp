struct Trie
{
	#define type int
	static const int LOG=30;
	static const int K=LOG+2;
	int root,tot,nex[MAX*K][2],cnt[MAX*K];
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init()
	{
		nex[0][0]=nex[0][1]=cnt[0]=tot=0;
		root=newnode();
	}
	void insert(type x)
	{
		int id,t,i;
		id=root;
		for(i=LOG;~i;i--)
		{
			cnt[id]++;
			t=(x>>i)&1;
			if(!nex[id][t]) nex[id][t]=newnode();
			id=nex[id][t];
		}
		cnt[id]++;
	}
	type ask_max(type x)
	{
		int id,i;
		type res,t;
		id=root;
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(nex[id][t^1]&&cnt[nex[id][t^1]]) t^=1;
			res|=(t<<i);
			id=nex[id][t];
		}
		return res^x;
	}
	type ask_min(type x)
	{
		int id,i;
		type res,t;
		id=root;
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(!nex[id][t]||!cnt[nex[id][t]]) t^=1;
			res|=(t<<i);
			id=nex[id][t];
		}
		return res^x;
	}
	#undef type
}tr;
