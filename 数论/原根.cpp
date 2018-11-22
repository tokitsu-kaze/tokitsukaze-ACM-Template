/*
原根性质 
1.一个数m如果有原根，则其原根个数为phi[phi[m]]。若m为素数，则其原根个数为phi[phi[m]]=phi[m-1]。
2.有原根的数只有2,4,p^n,2*p^n (p为质数,n为正整数)
3.一个数的最小原根的大小是O(n^0.25)的
4.如果g为n的原根，则g^d为n的原根的充要条件是gcd(d,phi[n])=1

指标法则
1. I(a*b)≡I(a)+I(b) (mod p-1)
2. I(a^k)≡k*I(a) (mod p-1)

*/


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
ll pow2(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int tp[MAX];
int find_root(int x)//求素数原根
{
	if(x==2) return 1;
    int f,phi=x-1;
    tp[0]=0;
    for(int i=0;phi&&i<tot;i++)
	{
        if(phi%p[i]==0)
		{
            tp[++tp[0]]=p[i];
            while(phi%p[i]==0) phi/=p[i];
        }
    }
    if(phi!=1) tp[++tp[0]]=phi;
    phi=x-1;
    for(int g=2;g<=x-1;g++)
	{
        f=1;
        for(int i=1;i<=tp[0];i++)
		{
            if(pow2(g,phi/tp[i],x)==1)
			{
                f=0;
                break;
            }
        }
        if(f) return g;
    }
    return 0;
}
int I[MAX];
void get_I(int p)//求指标表 
{
	int g,now;
	g=find_root(p);
	now=1;
	for(int i=1;i<p;i++)
	{
		now=now*g%p;
		I[now]=i;
	}
}
