namespace HASH
{
	#define type int
	int m;
	const int sd0=131;
	const int sd1=233;
	const int p0=402653189;
	const int p1=805306457;
	vector<type> tmp[2];
	void init(int _m)
	{
		int i,j;
		m=_m;
		tmp[0].resize(m+1);
		tmp[1].resize(m+1);
		tmp[0][0]=tmp[1][0]=1;
		for(i=1;i<=m;i++)
		{
			tmp[0][i]=1LL*tmp[0][i-1]*sd0%p0;
			tmp[1][i]=1LL*tmp[1][i-1]*sd1%p1;
		}
	}
	struct hash_table
	{
		vector<type> ha[2];
		void work(char *s,int n)
		{
			int i,j;
			assert(n<=m);
			ha[0].resize(n+1);
			ha[1].resize(n+1);
			ha[0][0]=ha[1][0]=0;
			for(i=1;i<=n;i++)
			{
				ha[0][i]=(1LL*ha[0][i-1]*sd0+s[i]-'a'+1)%p0;
				ha[1][i]=(1LL*ha[1][i-1]*sd1+s[i]-'a'+1)%p1;
			}
		}
		vector<type> get(int l,int r)
		{
			vector<type> res(2);
			res[0]=(ha[0][r]-1LL*ha[0][l-1]*tmp[0][r-l+1])%p0;
			if(res[0]<0) res[0]+=p0;
			res[1]=(ha[1][r]-1LL*ha[1][l-1]*tmp[1][r-l+1])%p1;
			if(res[1]<0) res[1]+=p1;
			return res;
		}
	};
	#undef type
}
HASH::hash_table ha;
/*
HASH::init(m);
ha.work(s,n);   // n<=m
*/
