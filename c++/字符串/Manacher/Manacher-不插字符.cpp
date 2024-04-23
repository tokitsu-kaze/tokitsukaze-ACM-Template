struct Manacher
{
	int p[MAX];
	int work(char *s,int n) //s[1..n]
	{
		int r,mid,i,res=0;
		//odd
		r=mid=0;
		for(i=0;i<=n;i++) p[i]=0;
		for(i=1;i<=n;i++)
		{
			//palindrome substring s[i,i]
			if(r>i) p[i]=min(p[2*mid-i],r-i);
			while(i+p[i]+1<=n&&s[i+p[i]+1]==s[i-p[i]-1])
			{
				//palindrome substring s[i-p[i]-1,i+p[i]+1]
				p[i]++;
			}
			if(i+p[i]>r)
			{
				r=i+p[i];
				mid=i;
			}
			res=max(res,p[i]*2+1);
		}
		//even
		r=mid=0;
		for(i=0;i<=n;i++) p[i]=0;
		for(i=2;i<=n;i++)
		{
			if(r>i) p[i]=min(p[2*mid-i],r-i+1);
			while(i+p[i]<=n&&s[i+p[i]]==s[i-p[i]-1])
			{
				//palindrome substring s[i-p[i]-1,i+p[i]]
				p[i]++;
			}
			if(i+p[i]-1>r)
			{
				r=i+p[i]-1;
				mid=i;
			}
			res=max(res,p[i]*2);
		}
		return res;
	}
}la;
/*
la.work(s,n); // s[1..n]
*/
