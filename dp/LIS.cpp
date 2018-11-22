//最长上升子序列(>)nlogn 返回长度 
//最长下降子序列(<) 把原数组取负数 
int a[MAX],b[MAX],n;
int LIS()
{
	int i;
	mem(b,0x3f);
	for(i=0;i<n;i++)
	{
		*lower_bound(b,b+n,a[i])=a[i];//最长不下降子序列(>=)改为upper_bound 
	}
	return lower_bound(b,b+n,INF)-b;
}
