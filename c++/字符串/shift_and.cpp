void shift_and(char *s,char *t)//s[1..n],t[1..m] (n<=m)
{
	static const int SZ=26;
	int n,m,i;
	bitset<MAX> b[SZ],d;
	for(i=0;i<SZ;i++) b[i].reset();
	d.reset();
	n=strlen(s+1);
	m=strlen(t+1);
	for(i=1;i<=n;i++)
	{
		b[s[i]-'a'].set(i-1);//change 
		//other matching character sets 
	}
	for(i=1;i<=m;i++)
	{
		d<<=1;
		d.set(0);
		d&=(b[t[i]-'a']);//change 
		if(d[n-1]==1)//successful match 
		{
			
		}
	}
}
