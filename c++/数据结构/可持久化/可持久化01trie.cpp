struct Persistent_01Trie
{
	#define type int
	static const int LOG=30;
	static const int K=LOG+2;
	int root[MAX],tot,nex[MAX*K][2],cnt[MAX*K];
	void init()
	{
		root[0]=0;
		nex[0][0]=nex[0][1]=cnt[0]=tot=0;
	}
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot;
	}
	void update(type x,int &rt,int pre)
	{
		int id,t,i;
		if(!rt) rt=newnode();
		id=rt;
		for(i=LOG;~i;i--)
		{
			cnt[id]=cnt[pre]+1;
			t=(x>>i)&1;
			nex[id][t^1]=nex[pre][t^1];
			nex[id][t]=newnode();
			id=nex[id][t];
			pre=nex[pre][t];
		}
		cnt[id]=cnt[pre]+1;
	}
	type query_max(type x,int rt,int pre)
	{
		int id,i;
		type res,t;
		id=rt;
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(cnt[nex[id][t^1]]-cnt[nex[pre][t^1]]>0) t^=1;
			res|=(t<<i);
			id=nex[id][t];
			pre=nex[pre][t];
		}
		return res^x;
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void create_ver(int now_ver,int pre_ver,type x)
	{
		root[now_ver]=0;
		update(x,root[now_ver],root[pre_ver]);
	}
	type ask_max(int pre_ver,int now_ver,type x)
	{
		assert(pre_ver>0);
		return query_max(x,root[now_ver],root[pre_ver-1]);
	}
	#undef type
}tr;
/*
tr.init();
tr.create_ver(now_ver,pre_ver,v);
tr.copy_ver(now_ver,pre_ver);
tr.ask_max(l,r,v);
*/
