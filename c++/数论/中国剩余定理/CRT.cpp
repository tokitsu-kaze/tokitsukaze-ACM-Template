ll qmul(ll a,ll b,ll p)
{
	ll res=0;
	while(b>0)
	{
		if(b&1) res=(res+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,tmp;
	g=exgcd(b,a%b,x,y);
	tmp=x;
	x=y;
	y=tmp-a/b*y;
	return g;
}
ll inv_exgcd(ll a,ll p)
{
	ll g,x,y;
	g=exgcd(a,p,x,y);
	return g==1?(x%p+p)%p:-1;
}
ll CRT(int n,ll *a,ll *m)
{
	int i;
	ll p,mi,res,invmi;
	p=1;
	res=0;
	for(i=1;i<=n;i++) a[i]=(a[i]%m[i]+m[i])%m[i];
	for(i=1;i<=n;i++) p*=m[i];
	for(i=1;i<=n;i++)
	{
		mi=p/m[i];
		invmi=inv_exgcd(mi,m[i]);
		res=(res+qmul(a[i]*mi,invmi,p))%p;
    }
    return res;
}
/*
x = a_i (mod m_i)  a:1..n, m:1..n
m_i must coprime

CRT return: x = res + k*p, k is interge
*/

