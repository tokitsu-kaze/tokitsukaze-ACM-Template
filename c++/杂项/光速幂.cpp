struct light_speed_pow
{
	#define type int
	int n,sq;
	type res[MAX][2],val;
	void init(int _n,type _val)
	{
		n=_n;
		val=_val;
		sq=sqrt(n)+1;
		res[0][0]=res[0][1]=1;
		for(int i=1;i<=sq;i++) res[i][0]=1ll*res[i-1][0]*val%mod;
		for(int i=1;i<=sq;i++) res[i][1]=1ll*res[i-1][1]*res[sq][0]%mod;
	}
	type qpow(int exp)
	{
		if(exp<=sq) return res[exp][0];
		return 1ll*res[exp/sq][1]*res[exp-exp/sq*sq][0]%mod;
	}
	#undef type
}lsp;
/*
val^exp
O(sqrt exp)-O(1)
*/ 
