//一维RMQ
//MAX=1e6时 第二维开22 内存(int型)占10w 
int v[MAX],maxx[MAX][22],minn[MAX][22];
void RMQ(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		maxx[i][0]=minn[i][0]=v[i];//下标rmq 初始化赋值成i 
		for(j=1;1<<(j-1)<=n;j++)
		{
			maxx[i][j]=0;
			minn[i][j]=INF;
		}
	}
	for(j=1;1<<(j-1)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			int t=1<<(j-1);
			maxx[i][j]=max(maxx[i][j-1],maxx[i+t][j-1]);
			minn[i][j]=min(minn[i][j-1],minn[i+t][j-1]);
		}
	}
}
int query(int l,int r)
{
	int j=(int)(log10(r-l+1)/log10(2))+1;
	int i=r-(1<<(j-1))+1;
	return max(maxx[l][j-1],maxx[i][j-1]);
//	return min(minn[l][j-1],minn[i][j-1]);
} 



//下标RMQ
int v[MAX],maxx[MAX][22],minn[MAX][22];
int pmax(int a,int b){return v[a]>v[b]?a:b;}
int pmin(int a,int b){return v[a]<v[b]?a:b;}
void RMQ(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		maxx[i][0]=minn[i][0]=i;
	}
	for(j=1;1<<(j-1)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			int t=1<<(j-1);
			maxx[i][j]=pmax(maxx[i][j-1],maxx[i+t][j-1]);
			minn[i][j]=pmin(minn[i][j-1],minn[i+t][j-1]);
		}
	}
}
int query(int l,int r)
{
	int j=(int)(log10(r-l+1)/log10(2))+1;
	int i=r-(1<<(j-1))+1;
	return pmax(maxx[l][j-1],maxx[i][j-1]);
//	return pmin(minn[l][j-1],minn[i][j-1]);
} 



//二维RMQ
int v[302][302];
int maxx[302][302][9][9],minn[302][302][9][9];
void RMQ(int n,int m)
{
	int i,j,ii,jj;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			maxx[i][j][0][0]=minn[i][j][0][0]=v[i][j];
		}
	}
	for(ii=0;(1<<ii)<=n;ii++)
	{
		for(jj=0;(1<<jj)<=m;jj++)
		{
			if(ii+jj)
			{
				for(i=1;i+(1<<ii)-1<=n;i++)
				{
					for(j=1;j+(1<<jj)-1<=m;j++)
					{
						if(ii)
						{
							minn[i][j][ii][jj]=min(minn[i][j][ii-1][jj],minn[i+(1<<(ii-1))][j][ii-1][jj]);
							maxx[i][j][ii][jj]=max(maxx[i][j][ii-1][jj],maxx[i+(1<<(ii-1))][j][ii-1][jj]);
						}
						else
						{
							minn[i][j][ii][jj]=min(minn[i][j][ii][jj-1],minn[i][j+(1<<(jj-1))][ii][jj-1]);
							maxx[i][j][ii][jj]=max(maxx[i][j][ii][jj-1],maxx[i][j+(1<<(jj-1))][ii][jj-1]);
						}
					}
				}
			}
		}
	}
}
int query(int x1,int y1,int x2,int y2)
{
	int k1=0;
	while((1<<(k1+1))<=x2-x1+1) k1++;
	int k2=0;
	while((1<<(k2+1))<=y2-y1+1) k2++;
	x2=x2-(1<<k1)+1;
	y2=y2-(1<<k2)+1;
	return max(max(maxx[x1][y1][k1][k2],maxx[x1][y2][k1][k2]),max(maxx[x2][y1][k1][k2],maxx[x2][y2][k1][k2]))
//	return min(min(minn[x1][y1][k1][k2],minn[x1][y2][k1][k2]),min(minn[x2][y1][k1][k2],minn[x2][y2][k1][k2]));
} 
