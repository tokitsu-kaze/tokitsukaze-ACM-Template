struct Palindrome_Tree
{
	static const int N=MAX;
	static const int LOGN=log2(N)+3;
	static const int K=26;// char size: [0,25]
	int len[N],nex[N][K],fail[N],last,pos[N],s[N],tot,n;
	int cnt[N],deep[N];
	int newnode(int l)
	{
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0; 
		deep[tot]=cnt[tot]=0;
		len[tot]=l;
		return tot++;
	}
	void init()
	{
		tot=n=last=0;
		newnode(0);
		newnode(-1);
		s[0]=-1;
		fail[0]=1;
	}
	int get_fail(int x)
	{
		while(s[n-len[x]-1]!=s[n]) x=fail[x];
		return x;
	}
	void add(int t,int p)
	{
		int id,now;
		s[++n]=t;
		now=get_fail(last);
		if(!nex[now][t])
		{
			id=newnode(len[now]+2);
			fail[id]=nex[get_fail(fail[now])][t];
			deep[id]=deep[fail[id]]+1;
			nex[now][t]=id;
		}
		last=nex[now][t];
		cnt[last]++;
		pos[p]=last;
	}
	void topsort()
	{
		for(int i=tot-1;i;i--) cnt[fail[i]]+=cnt[i];
	}
	int st[N][LOGN];
	void init_ST()
	{
		int i,j;
		for(i=2;i<tot;i++)
		{
			st[i][0]=fail[i];
			for(j=1;j<LOGN;j++)
			{
				st[i][j]=st[st[i][j-1]][j-1];
			}
		}
	}
	int get_substr(int l,int r)//init_ST
	{
		int now,tmp,i;
		now=pos[r];
		for(i=LOGN-1;~i;i--)
		{
			if(len[st[now][i]]>=r-l+1) now=st[now][i];
		}
		//maybe need judge if len[now]==r-l+1
		return now;
	}
	void build_tree(VI mp[])// root is 0
	{
		for(int i=0;i<=tot+1;i++) mp[i].clear();
		for(int i=1;i<tot;i++) mp[fail[i]].pb(i);
	}
	
}pam;
/*
pam.init();
pam.add(t,id); t is int
*/
