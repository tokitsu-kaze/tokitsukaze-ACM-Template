//O(r-l+1)
const int N=2e7+10;
ll p[N],tot;
bool vis[N],prime[N];
void init(ll l,ll r)
{
	ll i,j,sq=sqrt(r+0.5);
	tot=0;
	for(i=0;i<=sq;i++) vis[i]=1;
	for(i=l;i<=r;i++) prime[i-l]=1;
	if(l==0) prime[0]=prime[1]=0;
	if(l==1) prime[0]=0;
	for(i=2;i<=sq;i++)
	{
		if(!vis[i]) continue;
		for(j=i+i;j<=sq;j+=i) vis[j]=0;
		for(j=max(2LL,(l+i-1)/i)*i;j<=r;j+=i) prime[j-l]=0;
	}
	for(i=l;i<=r;i++)
	{
		if(prime[i-l]) p[tot++]=i;
	}
}
