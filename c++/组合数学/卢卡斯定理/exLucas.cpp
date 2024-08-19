namespace exLucas
{
	ll qpow(ll a,ll b,ll p)
	{
		ll res=1;
		while(b>0)
		{
			if(b&1) res=res*a%p;
			a=a*a%p;
			b>>=1;
		}
		return res;
	}
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
	ll inv(ll a,ll p)
	{
		ll g,x,y,res;
		g=exgcd(a,p,x,y);
		res=(g==1?(x+p)%p:-1);
		assert(res!=-1);
		return res;
	}
	ll CRT(vector<ll> a,vector<ll> m)
	{
		int i,n;
		ll p,mi,res,invmi;
		n=a.size();
		p=1;
		res=0;
		for(i=0;i<n;i++) a[i]=(a[i]%m[i]+m[i])%m[i];
		for(i=0;i<n;i++) p*=m[i];
		for(i=0;i<n;i++)
		{
			mi=p/m[i];
			invmi=inv(mi,m[i]);
			res=(res+qmul(a[i]*mi,invmi,p))%p;
	    }
	    return res;
	}
	map<ll,pair<vector<ll>,vector<ll>>> mp;
	map<pair<ll,ll>,vector<ll>> fac;
	void init(vector<ll> mod_list)
	{
		ll i,j,p;
		mp.clear();
		fac.clear();
		for(auto &mod_i:mod_list)
		{
			p=mod_i;
			vector<ll> a,b;
			for(i=2;i*i<=p;i++)
			{
				if(p%i) continue;
				b.push_back(1LL);
				while(p%i==0) b[b.size()-1]*=i,p/=i;
				a.push_back(i);
			}
			if(p>1) a.push_back(p),b.push_back(p);
			mp[mod_i]={a,b};
			for(i=0;i<a.size();i++)
			{
				if(fac.count({a[i],b[i]})) continue;
				vector<ll> fac_tmp(b[i]+1);
				fac_tmp[0]=1;
				for(j=1;j<=b[i];j++)
				{
					if(j%a[i]) fac_tmp[j]=fac_tmp[j-1]*j%b[i];
					else fac_tmp[j]=fac_tmp[j-1];
				}
				fac[{a[i],b[i]}]=fac_tmp;
			}
		}
	}
	ll cal_fac(ll n,ll x,ll p)
	{
		if(!n) return 1LL;
		ll res=1;
		assert(fac.count({x,p}));
		res=res*fac[{x,p}][p-1]%p;
		res=qpow(res,n/p,p);
		res=res*fac[{x,p}][n%p]%p;
		return res*cal_fac(n/x,x,p)%p;
	}
	ll comb(ll n,ll m,ll x,ll p)
	{
		if(m>n) return 0;
		ll i,cnt;
		cnt=0;
		for(i=n;i;i/=x) cnt+=i/x;
		for(i=m;i;i/=x) cnt-=i/x;
		for(i=n-m;i;i/=x) cnt-=i/x;
		return qpow(x,cnt,p)*             \
			   cal_fac(n,x,p)%p*          \
			   inv(cal_fac(m,x,p),p)%p*   \
			   inv(cal_fac(n-m,x,p),p)%p;
	}
	ll C(ll n,ll m,ll p)
	{
		if(m>n||m<0||n<0) return 0;
		ll i,res;
		vector<ll> a,b,resa;
		assert(mp.count(p));
		a=mp[p].first;
		b=mp[p].second;
		for(i=0;i<a.size();i++) resa.push_back(comb(n,m,a[i],b[i]));
		res=CRT(resa,b);
		assert(res!=-1);
		return res;
	}
};
/*
mod=p1^k1 * p2^k2 * ...
init: O(sqrt(mod)+sum{p^k})
C(n,m,mod): O(log)

exLucas::init({mod}); //init mod list
exLucas::C(n,m,mod);
*/
