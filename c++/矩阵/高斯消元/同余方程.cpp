namespace Gauss
{
	int p;
	ll mp[905][905],sol[905];
	void set_mod(int _p)
	{
		p=_p;
		mem(mp,0);
        mem(sol,0);
	}
	ll pow2(ll a,ll b)
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
	ll inv(ll x){return pow2(x,p-2);}
	ll lcm(ll a,ll b){return a/__gcd(a,b)*b;}
	int gauss(int n,int m)
	{
		int r,c,id,i,j;
		ll tmp,ta,tb;
		r=c=0;
		while(r<n&&c<m)
		{
			id=r;
			for(i=r+1;i<n;i++)
			{
				if(abs(mp[i][c])>abs(mp[id][c])) id=i;
			}
			if(id!=r)
			{
				for(i=0;i<=m;i++) swap(mp[r][i],mp[id][i]);
			}
			if(abs(mp[r][c])!=0)
			{
				for(i=r+1;i<n;i++)
				{
					if(abs(mp[i][c])==0) continue;
					tmp=lcm(abs(mp[i][c]),abs(mp[r][c]));
					ta=tmp/abs(mp[i][c]);
					tb=tmp/abs(mp[r][c]);
					if(mp[i][c]*mp[r][c]<0) tb=-tb;
					for(j=c;j<=m;j++)
					{
						mp[i][j]=(mp[i][j]*ta-mp[r][j]*tb)%p;
						if(mp[i][j]<0) mp[i][j]+=p;
					}
				}
				r++;
			}
			c++;
		}
		for(i=r;i<n;i++)
		{
			if(mp[i][m]!=0) return -1;//no solution 
		}
	//	if(r<m) return m-r;//multi solution 
		for(i=m-1;~i;i--)
		{
			tmp=mp[i][m];
			for(j=i+1;j<m;j++)
			{
				if(mp[i][j]==0) continue;
				tmp=(tmp-mp[i][j]*sol[j])%p;
				if(tmp<0) tmp+=p;
			}
			sol[i]=tmp*inv(mp[i][i])%p;
		}
		return 0;
	}
}
using namespace Gauss;
//set_mod(); 
