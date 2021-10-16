//O(r-l+1)
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
