/*
prime[x]表示x的最小质因数(x>=2)
prime[x]==x(x>=2)，表示x是素数。
*/

//埃氏筛 
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	mem(prime,0);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		p[tot++]=i;
		for(j=i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
//线性筛 
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	mem(prime,0);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
        for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
//区间筛
ll p[MAX],tot;
bool flag[MAX],prime[MAX];
void init(ll l,ll r)
{
	ll i,j,sq=sqrt(r+0.5);
	tot=0;
	for(i=0;i<=sq;i++) flag[i]=1;
	for(i=l;i<=r;i++) prime[i-l]=1;
	if(l==0) prime[0]=prime[1]=0;
	if(l==1) prime[0]=0;
	for(i=2;i<=sq;i++)
	{
		if(!flag[i]) continue;
		for(j=i+i;j<=sq;j+=i) flag[j]=0;
		for(j=max(2LL,(l+i-1)/i)*i;j<=r;j+=i) prime[j-l]=0;
	}
	for(i=l;i<=r;i++)
	{
		if(prime[i-l]) p[tot++]=i;
	}
}

//分解质因数 
vector<int> res;
void work(int x)
{
	int t;
	res.clear();
	while(x>1)
	{
		t=prime[x];
		while(x%t==0&&x>1) x/=t;
		res.pb(t);
	}
}
