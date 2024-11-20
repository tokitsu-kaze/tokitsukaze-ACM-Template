struct Suffix_Automaton
{
	static const int N=MAX<<1;
	static const int K=26;// char size: [0,25]
	int tot,lst,nex[N][K],fa[N],len[N],cnt[N],mxlen,root;
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
		mxlen=0;
		root=lst=newnode();
	}
	void add(int x)
	{
		int p,q,np,nq;
		if(nex[lst][x])
		{
			p=lst;
			q=nex[lst][x];
			if(len[q]==len[p]+1) lst=q;
			else
			{
				nq=lst=newnode();
				memcpy(nex[nq],nex[q],sizeof(nex[q]));
				len[nq]=len[p]+1;
				mxlen=max(mxlen,len[nq]);
				fa[nq]=fa[q];
				fa[q]=nq;
				while(p&&nex[p][x]==q)
				{
					nex[p][x]=nq;
					p=fa[p];
				}
			}
		}
		else
		{
			p=lst;
			np=lst=newnode();
			len[np]=len[p]+1;
			mxlen=max(mxlen,len[np]);
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
					mxlen=max(mxlen,len[nq]);
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
	}
	void insert(char *s,int n)
	{
		int i;
		lst=root;
		for(i=1;i<=n;i++) add(s[i]-'a');
	}
	int sum[N],tp[N];
	void topsort()
	{
		int i;
		for(i=1;i<=mxlen;i++) sum[i]=0;
		for(i=1;i<=tot;i++) sum[len[i]]++;
		for(i=1;i<=mxlen;i++) sum[i]+=sum[i-1];
		for(i=1;i<=tot;i++) tp[sum[len[i]]--]=i;
		for(i=tot;i;i--) cnt[fa[tp[i]]]+=cnt[tp[i]];
	}
}sam;
/*
sam.init();
sam.add(int x);
*/
