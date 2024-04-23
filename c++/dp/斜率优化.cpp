struct convex_hull_trick
{
	#define type ll
	#define k_increase 0  // 0 or 1
	struct func_node{type y,k,x;}f[MAX];
	int q[MAX],l,r;
	void init(){l=r=0;}
	void add(int pos,type y,type k,type x)
	{
		/*
		(y-y[r])/(x-x[r])>(y[r]-y[r-1])/(x[r]-x[r-1])
		(y-y[r])*(x[r]-x[r-1])>(x-x[r])*(y[r]-y[r-1])
		*/
		while(r-l>1 && (y-f[q[r-1]].y)*(f[q[r-1]].x-f[q[r-2]].x)
					 <=(x-f[q[r-1]].x)*(f[q[r-1]].y-f[q[r-2]].y)) r--;
		q[r++]=pos;
		f[pos]={y,k,x};
	}
	int get_mn_pos(type k)
	{
		/*
		k1=(y[ll]-y[ll-1])/(x[ll]-x[ll-1])
		k2=(y[ll+1]-y[ll])/(x[ll+1]-x[ll])
		k1 <= k < k2
		*/
		if(k_increase)
		{
			/*
			k_1 < k_2 < ... <k_n
			k1<=k -> (y[ll]-y[ll-1])<=k*(x[ll]-x[ll-1])
			*/
			while(r-l>1 && (f[q[l+1]].y-f[q[l]].y)
					   <=k*(f[q[l+1]].x-f[q[l]].x)) l++;
			return q[l];
		}
		else
		{
			// k<k2 -> k*(x[ll+1]-x[ll])<(y[ll+1]-y[ll])
			int ll,rr,mid;
			ll=l;
			rr=r-1;
			while(ll<rr)
			{
				mid=(ll+rr)>>1;
				if(k*(f[q[mid+1]].x-f[q[mid]].x)
				    <(f[q[mid+1]].y-f[q[mid]].y)) rr=mid;
				else ll=mid+1;
			}
			return q[ll];
		}
	}
	#undef type
	#undef k_increase
}convex;
/*
convex.init();
convex.add(pos,y,k,x);
convex.get_mn_pos(k);
*/
