namespace NTT
{
	const int g=3;
	const int p=998244353;
	int wn[35];
	int pow2(int a,int b)
	{
		int res=1;
		while(b>0)
		{
			if(b&1) res=1ll*res*a%p;
			a=1ll*a*a%p;
			b>>=1;
		}
		return res;
	}
	void getwn()
	{
		assert(p==mod);
		for(int i=0;i<25;i++) wn[i]=pow2(g,(p-1)/(1LL<<i));
	}
	void ntt(VI &a,int len,int f)
	{
		int i,j=0,t,k,w,id;
		for(i=1;i<len-1;i++)
		{
			for(t=len;j^=t>>=1,~j&t;);
			if(i<j) swap(a[i],a[j]);
		}
		for(i=1,id=1;i<len;i<<=1,id++)
		{
			t=i<<1;
			for(j=0;j<len;j+=t)
			{
				for(k=0,w=1;k<i;k++,w=1ll*w*wn[id]%p)
				{
					int x=a[j+k],y=1ll*w*a[j+k+i]%p;
					a[j+k]=x+y;
					if(a[j+k]>=p) a[j+k]-=p;
					a[j+k+i]=x-y;
					if(a[j+k+i]<0) a[j+k+i]+=p;
				}
			}
		}
		if(f)
		{
			for(i=1,j=len-1;i<j;i++,j--) swap(a[i],a[j]);
			int inv=pow2(len,p-2);
			for(i=0;i<len;i++) a[i]=1ll*a[i]*inv%p;
		}
	}
	void qpow(VI &a,int b)//limt: sz(a)*b is small
	{
		int len,i,l1;
		l1=sz(a);
		for(len=1;len<=(l1+1)*b-1;len<<=1);
		a.resize(len+1);
		for(i=l1;i<=len;i++) a[i]=0;
		ntt(a,len,0);
		for(i=0;i<len;i++) a[i]=pow2(a[i],b);
		ntt(a,len,1);
		a.resize((l1+1)*b-1);
	}
	void mul(VI &res,VI a,VI b)
	{
		int len,i,l1,l2;
		l1=sz(a);
		l2=sz(b);
		for(len=1;len<=l1+l2;len<<=1);
		a.resize(len+1);
		b.resize(len+1);
		for(i=l1+1;i<=len;i++) a[i]=0;
		for(i=l2+1;i<=len;i++) b[i]=0;
		ntt(a,len,0);ntt(b,len,0);
		res.resize(len);
		for(i=0;i<len;i++) res[i]=1ll*a[i]*b[i]%p;
		ntt(res,len,1);
		res.resize(l1+l2-1);
	}
	VI merge_generating_functions(vector<VI > &dp)
	{
		int i,j;
		priority_queue<PII > q;
		for(i=0;i<sz(dp);i++) q.push(MP(-sz(dp[i]),i));
		while(sz(q)>1)
		{
			i=q.top().se;
			q.pop();
			j=q.top().se;
			q.pop();
			mul(dp[i],dp[i],dp[j]);
			q.push(MP(-sz(dp[i]),i));
		}
		return dp[q.top().se];
	}
};//NTT::getwn();
