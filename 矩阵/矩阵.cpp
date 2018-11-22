/*
矩阵快速幂
高斯消元 
*/
const ll mod=1e9+7;
struct Matrix
{
	ll c[222][222],n;
	Matrix(){}
	Matrix(ll a,ll v=0)
	{
		int i,j;
		n=a;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=v;
			}
		}
	}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(!c[i][k]) continue;
				for(j=0;j<n;j++)
				{
					res.c[i][j]+=c[i][k]*b.c[k][j];
					if(res.c[i][j]>=mod) res.c[i][j]%=mod;
				}
			}
		}
		return res;
	}
};
Matrix matpow2(Matrix a,ll b)
{
	Matrix res(a.n);
	for(int i=0;i<a.n;i++)
	{
		res.c[i][i]=1;
	}
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
//高斯消元 O(n*n*m)
//1.同余方程 mod=2时 异或加速 
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
			for(int r=1;r<=m+1;r++)
            {
				swap(mat[i][r],mat[k][r]);  
			}
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
//2.同余方程
//3.浮点型 
