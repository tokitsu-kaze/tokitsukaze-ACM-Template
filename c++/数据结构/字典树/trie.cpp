struct Trie
{
	#define type int
	static const int K=26;
	int nex[MAX][K],cnt[MAX];
	int root,tot;
	int getid(char c){return c-'a';}
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init()
	{
		tot=0;
		memset(nex[0],0,sizeof nex[0]);
		cnt[0]=0;
		root=newnode();
	}
	void insert(char *s,int n) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
		}
		cnt[now]++;
	}
	#undef type
}tr;
/*
tr.init();
tr.insert(s,len); s[0..len-1]
*/
