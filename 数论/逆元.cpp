/*
1.费马小定理 
条件:mod为素数 
*/
ll inv(ll x,ll p){return pow2(x,p-2);}

/*
2.扩展欧几里得
条件:gcd(a,mod)==1
如果gcd(a,mod)!=1 返回-1 
*/
ll inv(ll a,ll p)
{
	ll g,x,y;
	g=exgcd(a,p,x,y);
	return g==1?(x+p)%p:-1;
}

/*
3.公式
a/b%mod=c
->a%(b*mod)/b=c 
*/

/*
4.逆元打表
p是模 
p要求是奇素数 
*/
ll inv[MAX];
void getinv(int n,ll p)
{
	ll i;
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
}
