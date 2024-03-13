namespace NTT
{
	const int g=3;
	const int p=998244353;
	int wn[35];
	int qpow(int a,int b)
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
		for(int i=0;i<25;i++) wn[i]=qpow(g,(p-1)/(1LL<<i));
	}
	void ntt(vector<int> &a,int len,int f)
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
			int inv=qpow(len,p-2);
			for(i=0;i<len;i++) a[i]=1ll*a[i]*inv%p;
		}
	}
	vector<int> qpow(vector<int> a,int b)//limt: sz(a)*b is small
	{
		int len,i,l1;
		l1=a.size();
		for(len=1;len<(l1+1)*b-1;len<<=1);
		a.resize(len,0);
		ntt(a,len,0);
		vector<int> res(len);
		for(i=0;i<len;i++) res[i]=pow2(a[i],b);
		ntt(res,len,1);
		res.resize((l1+1)*b-1);
		return res;
	}
	vector<int> mul(vector<int> a,vector<int> b)
	{
		int len,i,l1,l2;
		l1=a.size();
		l2=b.size();
		for(len=1;len<l1+l2;len<<=1);
		a.resize(len,0);
		b.resize(len,0);
		ntt(a,len,0);ntt(b,len,0);
		vector<int> res(len);
		for(i=0;i<len;i++) res[i]=1ll*a[i]*b[i]%p;
		ntt(res,len,1);
		res.resize(l1+l2-1);
		return res;
	}
	
	//get kth 
	vector<int> merge_generating_functions(vector<vector<int>> &dp,int k)
	{
		int i,j;
		priority_queue<pair<int,int>> q;
		for(i=0;i<dp.size();i++) q.push({-dp[i].size(),i});
		while(q.size()>1)
		{
			i=q.top().second;
			q.pop();
			j=q.top().second;
			q.pop();
			dp[i]=mul(dp[i],dp[j]);
			if(dp[i].size()>k) dp[i].resize(k+1);
			q.push({-dp[i].size(),i});
		}
		return dp[q.top().second];
	}
};//NTT::getwn();
