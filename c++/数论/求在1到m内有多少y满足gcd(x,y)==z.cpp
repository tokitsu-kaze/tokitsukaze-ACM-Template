struct GCD_Conclusion
{
	void work(int x)
	{
		int sq=sqrt(x+0.5);
		res.clear();
		for(int i=2;i<=sq;i++)
		{
			if(x%i==0) res.pb(i);
			while(x%i==0) x/=i;
		}
		if(x>1) res.pb(x);
	}
	void dfs(int p,ll now,int f)
	{
		if(now>m) return;
		if(p==sz(res))
		{
			if(f) cnt-=m/now;
			else cnt+=m/now;
			return;
		}
		dfs(p+1,now,f);
		dfs(p+1,now*res[p],f^1);
	}
	
	// cal count of y(in 1-m) for gcd(x,y)==z
	ll cal_y_in_m_for_gcdxy_equal_z(ll x,ll z,ll _m)
	{
		m=_m;
	}
	
}gcdc;
