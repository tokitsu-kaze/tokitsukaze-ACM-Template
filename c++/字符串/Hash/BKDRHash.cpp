struct BKDRHash
{
	static const ull seed=1313131;//31,131,1313,13131,131313
	static const int p=2000007;
	ull Hash[MAX],tmp[MAX];
	ull val[MAX];
	int last[p+10],nex[MAX],cnt;
	void init()//clear hash table 
	{
		mem(last,0);
		cnt=0;
	}
	bool insert(ull x)
	{
		int u=x%p;
		for(int i=last[u];i;i=nex[i])
		{
			if(val[i]==x) return 1;
		}
		nex[++cnt]=last[u];
		last[u]=cnt;
		val[cnt]=x;
		return 0;
	}
	void work(char *s,int n)
	{
		tmp[0]=1;
		Hash[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=tmp[i-1]*seed;
			Hash[i]=Hash[i-1]*seed+s[i];
		}
	}
	ull get(int l,int r)
	{
		return Hash[r]-Hash[l-1]*tmp[r-l+1];
	}
}bkdr; //bkdr.init();
