namespace exLucas
{
	ll pow2(ll a,ll b,ll p)
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
	ll inv(ll a,ll p)
	{
		ll g,x,y,res;
		g=exgcd(a,p,x,y);
		res=(g==1?(x+p)%p:-1);
		assert(res!=-1);
		return res;
	}
	map<ll,pair<VL,VL> > mp;
	map<PLL,VL > fac;
	void init(VL mod_list)
	{
		ll i,j,p;
		mp.clear();
		fac.clear();
		for(auto mod_i:mod_list)
		{
			p=mod_i;
			VL a,b;
			for(i=2;i*i<=p;i++)
			{
				if(p%i) continue;
				b.pb(1LL);
				while(p%i==0) b[sz(b)-1]*=i,p/=i;
				a.pb(i);
			}
			if(p>1) a.pb(p),b.pb(p);
			mp[mod_i]=MP(a,b);
			for(i=0;i<sz(a);i++)
			{
				if(fac.count(MP(a[i],b[i]))) continue;
				VL fac_tmp=VL(b[i]+1);
				fac_tmp[0]=1;
				for(j=1;j<=b[i];j++)
				{
					if(j%a[i]) fac_tmp[j]=fac_tmp[j-1]*j%b[i];
					else fac_tmp[j]=fac_tmp[j-1];
				}
				fac[MP(a[i],b[i])]=fac_tmp;
			}
		}
	}
	ll cal_fac(ll n,ll x,ll p)
	{
		if(!n) return 1LL;
		ll res=1;
		assert(fac.count(MP(x,p)));
		res=res*fac[MP(x,p)][p-1]%p;
		res=pow2(res,n/p,p);
		res=res*fac[MP(x,p)][n%p]%p;
		return res*cal_fac(n/x,x,p)%p;
	}
	ll multilucas(ll n,ll m,ll x,ll p)
	{
		if(m>n) return 0;
		ll i,cnt;
		cnt=0;
		for(i=n;i;i/=x) cnt+=i/x;
		for(i=m;i;i/=x) cnt-=i/x;
		for(i=n-m;i;i/=x) cnt-=i/x;
		return pow2(x,cnt,p)*             \
			   cal_fac(n,x,p)%p*          \
			   inv(cal_fac(m,x,p),p)%p*   \
			   inv(cal_fac(n-m,x,p),p)%p;
	}
	ll C(ll n,ll m,ll p)
	{
		if(m>n||m<0||n<0) return 0;
		ll i,res;
		VL a,b,resa;
		assert(mp.count(p));
		a=mp[p].fi;
		b=mp[p].se;
		for(i=0;i<sz(a);i++) resa.pb(multilucas(n,m,a[i],b[i]));
		res=exCRT::excrt(resa,b);
		assert(res!=-1);
		return res;
	}
};//exLucas::init(VL{}); 
