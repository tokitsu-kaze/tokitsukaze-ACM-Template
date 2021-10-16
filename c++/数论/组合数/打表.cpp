ll C[1010][1010];
void init(int n)
{
	int i,j;
	for(i=(C[0][0]=1);i<=n;i++)
	{
		for(j=(C[i][0]=1);j<=n;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	} 
}