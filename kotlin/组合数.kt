var comb=Array(1002){IntArray(1002)}
fun init_comb(n:Int,m:Int)
{
	comb[0][0]=1;
	for(i in 1..n)
	{
		comb[i][0]=1;
		for(j in 1..m)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
			if(comb[i][j]>=mod) comb[i][j]-=mod;
		}
	}
}
fun C(n:Int,m:Int):Int
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}

/*---------------------------------------------*/

fun qpow(aa:Long,bb:Int,p:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1) res=res*a%p
		a=a*a%p
		b=b shr 1
	}
	return res
}
fun inv(x:Long):Long
{
	return qpow(x,mod-2,mod)
}
var fac=LongArray(1)
var invfac=LongArray(1)
fun init_comb(n:Int)
{
	fac=LongArray(n+1)
	invfac=LongArray(n+1)
	fac[0]=1
	for(i in 1..n) fac[i]=fac[i-1]*i%mod
	invfac[n]=inv(fac[n])
	for(i in n-1 downTo 0) invfac[i]=invfac[i+1]*(i+1)%mod
}
fun C(n:Int,m:Int):Long
{
	if(m>n||m<0||n<0) return 0L
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod
}

