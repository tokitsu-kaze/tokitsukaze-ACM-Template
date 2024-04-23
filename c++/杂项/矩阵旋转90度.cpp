int n,m,a[MAX][MAX],tmp[MAX][MAX];
void rotate90()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			tmp[i][j]=a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[j][i]=tmp[n-i+1][j];
		}
	}
	swap(n,m);
}
