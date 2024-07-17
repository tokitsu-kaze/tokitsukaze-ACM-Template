var comb=Array(1002){IntArray(1002)}
fun init(n:Int,m:Int)
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
