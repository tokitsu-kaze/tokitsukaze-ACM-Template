struct SA
{
	int s[MAX],n,SZ;
	int c[MAX],rk[MAX],tp[MAX];
	void init(char *ss) //s[1..n]
	{
		SZ=0;
		n=strlen(ss+1);
		for(int i=1;i<=n;i++)
		{
			s[i]=ss[i];
			SZ=max(SZ,s[i]);
		}
	}
	void get_sa(int *sa,int *height)
	{
		int m,i,j,k,now;
		m=SZ;
		for(i=1;i<=m;i++) c[i]=0;
		for(i=1;i<=n;i++) c[rk[i]=s[i]]++;
		for(i=2;i<=m;i++) c[i]+=c[i-1]; 
		for(i=n;i;i--) sa[c[rk[i]]--]=i; 
		for(k=1;k<=n;k<<=1)
		{
			now=0;
			for(i=n-k+1;i<=n;i++) tp[++now]=i;
			for(i=1;i<=n;i++)
			{
				if(sa[i]>k) tp[++now]=sa[i]-k;
			}
			for(i=1;i<=m;i++) c[i]=0;
			for(i=1;i<=n;i++) c[rk[i]]++;
			for(i=2;i<=m;i++) c[i]+=c[i-1];
			for(i=n;i;i--)
			{
				sa[c[rk[tp[i]]]--]=tp[i];
				tp[i]=0;
			}
			swap(rk,tp);
			rk[sa[1]]=1;
			now=1;
			for(i=2;i<=n;i++)
			{
				if(!(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+k]==tp[sa[i-1]+k])) now++;
				rk[sa[i]]=now;
			}
			if(now==n) break;
			m=now;
		}
		height[1]=0;
		k=0;
		for(i=1;i<=n;i++)  
		{
			if(rk[i]==1) continue;
			if(k) k--;
			j=sa[rk[i]-1];
			while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k]) k++;
			height[rk[i]]=k;
		}
	}
}da;

