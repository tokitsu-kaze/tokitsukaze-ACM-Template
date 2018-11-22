//a^x¡Ôb (mod c)
ll exBSGS(ll a,ll b,ll c)
{
	ll i,g,d,num,now,sq,t,x,y;
	if(c==1) return b?-1:(a!=1);
	if(b==1) return a?0:-1;
	if(a%c==0) return b?-1:1;
	num=0;
	d=1;
	while((g=__gcd(a,c))>1)
	{
		if(b%g) return -1;
		num++;
		b/=g;
		c/=g;
		d=(d*a/g)%c;
		if(d==b) return num;
	}
	mp.clear();
	sq=ceil(sqrt(c));
	t=1;
	for(i=0;i<sq;i++)
	{
		if(!mp.count(t)) mp[t]=i;
		else mp[t]=min(mp[t],i);
		t=t*a%c;
	}
	for(i=0;i<sq;i++)
	{
		exgcd(d,c,x,y);
		x=(x*b%c+c)%c;
		if(mp.count(x)) return i*sq+mp[x]+num;
		d=d*t%c;
	}
	return -1;
}
