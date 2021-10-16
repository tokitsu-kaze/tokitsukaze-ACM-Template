struct Manacher
{
	int p[MAX<<1];
	char s[MAX<<1];
	int work(char *a)
	{
		int len,i,mid,r,res=0;
		len=strlen(a+1);
		for(i=1;i<=len;i++)
		{
			p[i]=0;
			s[2*i-1]='%';
			s[2*i]=a[i];
		}
		s[len=len*2+1]='%';
		mid=r=0;
		for(i=1;i<=len;i++)
		{
			if(i<r) p[i]=min(p[2*mid-i],r-i);
			else p[i]=1;
			while(i-p[i]>=1&&i+p[i]<=len&&s[i-p[i]]==s[i+p[i]]) p[i]++;
			if(i+p[i]>r)
			{
				r=i+p[i];
				mid=i;
			}
			res=max(res,p[i]-1);
		}
		return res;
	}
}la;