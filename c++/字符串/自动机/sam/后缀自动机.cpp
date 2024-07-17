struct Suffix_Automaton
{
	static const int N=MAX<<1;
	static const int K=26;// char size: [0,25]
	int tot,lst,nex[N][K],fa[N],len[N],cnt[N],maxlen,root;
	int newnode()
	{
		tot++;
		fa[tot]=len[tot]=cnt[tot]=0;
		memset(nex[tot],0,sizeof nex[tot]);
		return tot;
	}
	void init()
	{
		fa[0]=len[0]=cnt[0]=0;
		memset(nex[0],0,sizeof nex[0]);
		tot=0;
		maxlen=0;
		root=lst=newnode();
	}
	void add(int x)
	{
		int p,q,np,nq;
		p=lst;
		np=lst=newnode();
		len[np]=len[p]+1;
		maxlen=max(maxlen,len[np]);
		cnt[lst]=1;
		while(p&&!nex[p][x])
		{
			nex[p][x]=np;
			p=fa[p];
		}
		if(p==0) fa[np]=root;
		else
		{
			q=nex[p][x];
			if(len[q]==len[p]+1) fa[np]=q;
			else
			{
				nq=newnode();
				memcpy(nex[nq],nex[q],sizeof(nex[q]));
				len[nq]=len[p]+1;
				maxlen=max(maxlen,len[nq]);
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				while(p&&nex[p][x]==q)
				{
					nex[p][x]=nq;
					p=fa[p];
				}
			}
		}
	}
	int sum[N],tp[N];
	void topsort()
	{
		int i;
		for(i=1;i<=maxlen;i++) sum[i]=0;
		for(i=1;i<=tot;i++) sum[len[i]]++;
		for(i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
		for(i=1;i<=tot;i++) tp[sum[len[i]]--]=i;
		for(i=tot;i;i--) cnt[fa[tp[i]]]+=cnt[tp[i]];
	}
	void build_tree(VI mp[])
	{
		for(int i=1;i<=tot;i++) mp[i].clear();
		for(int i=1;i<=tot;i++) mp[fa[i]].pb(i);
	}
	int pos[N],id[N];
	void init_pos(char *s,int n)//s[1..n]
	{
		int now=1;
		for(int i=1;i<=tot;i++) id[i]=-1;
		for(int i=1;i<=n;i++)
		{
			now=nex[now][s[i]-'a'];
			pos[i]=now;
			id[now]=i;
		}
	}
	int st[N][21];
	void init_ST()
	{
		int i,j,x;
		for(i=1;i<=tot;i++)
		{
			x=tp[i];
			st[x][0]=fa[x];
			for(j=1;j<20;j++)
			{
				st[x][j]=st[st[x][j-1]][j-1];
			}
		}
	}
	int get_substr(int l,int r)//init_pos  init_ST
	{
		int now,tmp,i;
		now=pos[r];
		for(i=19;~i;i--)
		{
			tmp=st[now][i];
			if(tmp&&len[tmp]>=r-l+1) now=tmp;
		}
		return now;
	}
}sam;
/*
sam.init();
sam.add(int x);
sam.topsort();

*/
