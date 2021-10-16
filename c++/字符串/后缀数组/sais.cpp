struct SA
{
	char S[MAX]; int n,m;
	int s[MAX<<1],t[MAX<<1],H[MAX],sa[MAX],r[MAX],p[MAX],c[MAX],w[MAX];
	inline int trans(int n,const char* S){
		int m=*max_element(S+1,S+1+n);
		for(int i=1;i<=n;++i) r[S[i]]=1;
		for(int i=1;i<=m;++i) r[i]+=r[i-1];
		for(int i=1;i<=n;++i) s[i]=r[S[i]];
		return r[m];
	}
	#define ps(x) sa[w[s[x]]--]=x
	#define pl(x) sa[w[s[x]]++]=x
	inline void radix(int* v,int* s,int* t,int n,int m,int n1){
		memset(sa,0,n+1<<2); memset(c,0,m+1<<2);
		for(int i=1;i<=n;++i) ++c[s[i]];
		for(int i=1;i<=m;++i) w[i]=c[i]+=c[i-1];
		for(int i=n1;i;--i) ps(v[i]);
		for(int i=1;i<=m;++i) w[i]=c[i-1]+1;
		for(int i=1;i<=n;++i) if(sa[i]>1 && t[sa[i]-1]) pl(sa[i]-1);
		for(int i=1;i<=m;++i) w[i]=c[i];
		for(int i=n;i;--i) if(sa[i]>1 && !t[sa[i]-1]) ps(sa[i]-1);
	}
	inline void SAIS(int n,int m,int* s,int* t,int* p){
		int n1=0,ch=r[1]=0,*s1=s+n; t[n]=0;
		for(int i=n-1;i;--i) t[i]=s[i]==s[i+1]?t[i+1]:s[i]>s[i+1];
		for(int i=2;i<=n;++i) r[i]=t[i-1]&&!t[i]?(p[++n1]=i,n1):0;
		radix(p,s,t,n,m,n1);
		for(int i=1,x,y;i<=n;++i) if(x=r[sa[i]]){
			if(ch<=1 || p[x+1]-p[x]!=p[y+1]-p[y]) ++ch;
			else for(int j=p[x],k=p[y];j<=p[x+1];++j,++k)
				if((s[j]<<1|t[j])^(s[k]<<1|t[k])){ ++ch; break; }
			s1[y=x]=ch;
		}
		if(ch<n1) SAIS(n1,ch,s1,t+n,p+n1);
		else for(int i=1;i<=n1;++i) sa[s1[i]]=i;
		for(int i=1;i<=n1;++i) s1[i]=p[sa[i]];
		radix(s1,s,t,n,m,n1);
	}
	inline void get_sa(int n,const char* S,int *ssa,int *h){
		int m=trans(++n,S);	SAIS(n,m,s,t,p);
		for(int i=1;i<n;++i) r[sa[i]=sa[i+1]]=i;
		for(int i=1,j,k=0;i<n;++i) if(r[i]>1){
			for(j=sa[r[i]-1];S[i+k]==S[j+k];++k);
			if(H[r[i]]=k) --k;
		}
		for(int i=1;i<=n;i++)
		{
			ssa[i]=sa[i];
			h[i]=H[i];
		}
	}
}sais;
