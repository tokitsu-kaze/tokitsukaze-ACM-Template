struct Palindrome_Tree
{
	int len[MAX],next[MAX][26],fail[MAX],last,s[MAX],tot,n;
	int cnt[MAX],deep[MAX];
	int newnode(int l)
	{
		mem(next[tot],0);
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
	void add(int t)//attention the type of t is int
	{
		int id,now;
		s[++n]=t;
		now=get_fail(last);
		if(!next[now][t])
		{
			id=newnode(len[now]+2);
			fail[id]=next[get_fail(fail[now])][t];
			deep[id]=deep[fail[id]]+1;
			next[now][t]=id;
		}
		last=next[now][t];
		cnt[last]++;
	}
	void count()
	{
		for(int i=tot-1;~i;i--) cnt[fail[i]]+=cnt[i];
	}
}pam; //pam.init(); 
