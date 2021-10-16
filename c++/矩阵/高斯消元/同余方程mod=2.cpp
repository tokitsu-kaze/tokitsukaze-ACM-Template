//同余方程 mod=2时 异或加速  O(n*n*m)
int mat[22][MAX];
int Gauss(int n,int m)//n是未知数个数 m是方程个数 
{  
	int i,j;  
	for(i=1,j=1;i<=n&&j<=m;j++)
	{  
		int k=i;  
		while(k<=n&&!mat[k][j]) k++;
		if(mat[k][j])
		{  
			for(int r=1;r<=m+1;r++) swap(mat[i][r],mat[k][r]);  
			for(int r=1;r<=n;r++)
			{
				if(r!=i&&mat[r][j])
				{
					for(k=1;k<=m+1;k++)
					{
						mat[r][k]^=mat[i][k];
					}
				}
			}
			i++;
		}
	} 
	//第m+1列是等号右边 
	for(j=i;j<=n;j++)
	{
		if(mat[j][m+1]) return -1;//无解 
	}
	return m-i+1;//返回解的个数 
}