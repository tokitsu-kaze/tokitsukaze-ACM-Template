int stl2[MAX][MAX];
void init_Stirling2(int n)
{
	int i,j;
	stl2[0][0]=1;
	stl2[1][0]=0;
	stl2[1][1]=1;
	for(i=2;i<=n;i++)
	{
		stl2[i][0]=0;
		for(j=1;j<=i;j++)
		{
			stl2[i][j]=(stl2[i-1][j-1]+1LL*j*stl2[i-1][j])%mod;
		}
	}
}
ll S(int n,int k)
{
	if(k>n) return 0;
	return stl2[n][k];
}
