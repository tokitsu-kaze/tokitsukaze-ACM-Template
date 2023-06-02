ll C[1010][1010];
void init(int n)
{
	int i,j;
	C[0][0]=1;
	for(i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(j=1;j<=n;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	} 
}
