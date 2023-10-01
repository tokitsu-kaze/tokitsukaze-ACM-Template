struct Gauss
{
	const double eps=1e-7;
	double mp[][];
	int gauss(int n,int m)
	{
		int i,j,k,pos,r;
		double tmp;
		r=0;
		for(k=1;k<=m;k++)
		{
			pos=r+1;
			if(pos>n) return -1; // no solution
			for(i=pos+1;i<=n;i++)
			{
				if(fabs(mp[i][k])>fabs(mp[pos][k])) pos=i;
			}
			if(fabs(mp[pos][k])<eps) continue;
			r++;
			swap(mp[pos],mp[r]);
			tmp=mp[r][k];
			for(j=k;j<=m+1;j++) mp[r][j]/=tmp;
			for(i=r+1;i<=n;i++)
			{
				tmp=mp[i][k];
				for(j=k;j<=m+1;j++)
				{
					mp[i][j]-=mp[r][j]*tmp;
				}
			}
		}
		return r;
	}
	int work(int n,int m,double *res)
	{
		int i,j,cnt;
		cnt=gauss(n,m);
		if(cnt==-1) return -1;
		for(i=cnt+1;i<=n;i++)
		{
			if(fabs(mp[i][m+1])>eps)
			{
				// no solution
				return -1;
			}
		}
		if(cnt<m)
		{
			// multi solution
			return 1;
		}
		res[m]=mp[m][m+1];
		for(i=m-1;i>=1;i--)
		{
			res[i]=mp[i][m+1];
			for(j=i+1;j<=m;j++)
			{
				res[i]-=mp[i][j]*res[j];
			}
		}
		return 0;
	}
}gs;
/*
(mp[1][1]*x1) + (mp[1][2]*x2) + ... + (mp[1][m]*xm) = mp[1][m+1]
(mp[2][1]*x1) + (mp[1][2]*x2) + ... + (mp[2][m]*xm) = mp[2][m+1]
...
(mp[n][1]*x1) + (mp[n][2]*x2) + ... + (mp[n][m]*xm) = mp[n][m+1]

x x x x | x
0 x x x | x
0 0 x x | x
0 0 0 x | x

O(n*m^2) m<=n

gs.work(n,m,res); mp[1..n][1..m+1], res[1..m]

-1: no solution
0 : one solution
1 : multi solution
*/
