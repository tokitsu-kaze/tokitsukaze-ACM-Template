struct Z_Algorithm
{
	char s[MAX];
	int n,z[MAX],ex[MAX];
	void get_z_func(char *_s,int _n) // s[0..n-1]
	{
		int i,j,l,r;
		n=_n;
		memcpy(s,_s,n);
		z[0]=l=r=0;
		for(i=1;i<n;i++)
		{
			if(i+z[i-l]-1<r) z[i]=z[i-l];
			else
			{
				j=max(0,r-i+1);
				while(i+j<n&&s[i+j]==s[j]) j++;
				z[i]=j;
				if(i+z[i]-1>r)
				{
					l=i;
					r=i+z[i]-1;
				}
			}
		}
		z[0]=n;
	}
	void get_ex(char *t,int m) // t[0..m-1]
	{
		int i,j,l,r;
		j=l=0;
		while(j<n&&j<m&&t[j]==s[j]) j++;
		ex[0]=j;
		r=l+ex[0]-1;
		for(i=1;i<m;i++)
		{
			if(i+z[i-l]-1<r) ex[i]=z[i-l];
			else
			{
				j=max(0,r-i+1);
				while(i+j<m&&t[i+j]==s[j]) j++;
				ex[i]=j;
				if(i+ex[i]-1>r)
				{
					l=i;
					r=i+ex[i]-1;
				}
			}
		}
	}
}z;
/*
z[i]:  lcp(s,s[i..n-1]) i=0..n-1
ex[i]: lcp(s,t[i..m-1]) i=0..m-1

z.get_z_func(s,n) s[0..n-1]
z.get_ex(t,m) t[0..m-1]
*/
