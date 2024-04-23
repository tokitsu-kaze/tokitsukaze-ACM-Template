namespace FST
{
	const int p=;
	void fwt(vector<int> &a,int n,int v)
	{  
		for(int d=1;d<n;d<<=1)
		{
			for(int m=d<<1,i=0;i<n;i+=m)
			{
				for(int j=0;j<d;j++)
				{  
					int x=a[i+j],y=a[i+j+d];
					if(v==1) a[i+j+d]=(x+y)%p;//or
					else a[i+j+d]=(y-x+p)%p;//or
				}
			}
		}
	}
	vector<int> mul(vector<int> a,vector<int> b)
	{
		int i,j,k,n,len,s,cnt;
		n=max(a.size(),b.size());
		for(s=0;(1<<s)<n;s++);
		len=(1<<s);
		s++;
		a.resize(len,0);
		b.resize(len,0);
		vector<int> ta[s],tb[s],tmp[s],res;
		for(i=0;i<s;i++)
		{
			ta[i].resize(len,0);
			tb[i].resize(len,0);
			tmp[i].resize(len,0);
		}
		for(i=0;i<len;i++)
		{
			cnt=__builtin_popcount(i);
			ta[cnt][i]=a[i];
			tb[cnt][i]=b[i];
		}
		for(i=0;i<s;i++)
		{
			fwt(ta[i],len,1);
			fwt(tb[i],len,1);
		}
		for(i=0;i<s;i++)
		{
			for(j=0;j<=i;j++)
			{
				for(k=0;k<len;k++)
				{
					tmp[i][k]=(1ll*ta[j][k]*tb[i-j][k]+tmp[i][k])%p;
				}
			}
			fwt(tmp[i],len,-1);
		}
		res.resize(len,0);
		for(i=0;i<len;i++) res[i]=tmp[__builtin_popcount(i)][i];
		return res;
	}
}
/*
ck=ai*bj (i&j=0, i|j=k)
FST::mul(a,b);
*/
