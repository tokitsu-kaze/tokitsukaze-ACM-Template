const int DIGIT=9;
const int DEPTH=1000000000;
const int MAXN=100;
typedef ll bignum_t[MAXN+1];
ll read(bignum_t a,istream&is=cin)
{
	char buf[MAXN*DIGIT+1],ch;
	ll i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if(!(is>>buf))return 0;
	for(a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
	ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for(a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for(i=1;i<=a[0];i++)
	for(a[i]=0,j=0;j<DIGIT;j++)
	a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for(;!a[a[0]]&&a[0]>1;a[0]--);
	return 1;
}
void write(const bignum_t a,ostream&os=cout)
{
	ll i,j ;
	for(os<<a[i=a[0]],i--;i;i--)
	os<<setw(DIGIT)<<setfill('0')<<a[i];
}
ll comp(const bignum_t a,const bignum_t b)
{
	ll i ;
	if(a[0]!=b[0]) return a[0]-b[0];
	for(i=a[0];i;i--)
	if(a[i]!=b[i])
	return a[i]-b[i];
	return 0 ;
}
ll comp(const bignum_t a,const ll b)
{
	ll c[12]={1};
	for(c[1]=b;c[c[0]]>=DEPTH;c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);
	return comp(a,c);
}
ll comp(const bignum_t a,const ll c,const ll d,const bignum_t b)
{
	ll i,t=0,O=-DEPTH*2;
	if(b[0]-a[0]<d&&c)
	return 1 ;
	for(i=b[0];i>d;i--)
	{
		t=t*DEPTH+a[i-d]*c-b[i];
		if(t>0)return 1;
		if(t<O)return 0;
	}
	for(i=d;i;i--)
	{
		t=t*DEPTH-b[i];
		if(t>0)return 1;
		if(t<O)return 0;
	}
	return t>0 ;
}
void add(bignum_t a,const bignum_t b)
{
	ll i ;
	for(i=1;i<=b[0];i++)
	if((a[i]+=b[i])>=DEPTH)
	a[i]-=DEPTH,a[i+1]++;
	if(b[0]>=a[0])
	a[0]=b[0];
	else
	for(;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
	a[0]+=(a[a[0]+1]>0);
}
void add(bignum_t a,const ll b)
{
	ll i=1;
	for(a[1]+=b;a[i]>=DEPTH&&i<a[0];a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);
	for(;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
}
void sub(bignum_t a,const bignum_t b)
{
	ll i;
	for(i=1;i<=b[0];i++)
	if((a[i]-=b[i])<0)
	a[i+1]--,a[i]+=DEPTH;
	for(;a[i]<0;a[i]+=DEPTH,i++,a[i]--);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void sub(bignum_t a,const ll b)
{
	ll i=1;
	for(a[1]-=b;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void sub(bignum_t a,const bignum_t b,const ll c,const ll d)
{
	ll i,O=b[0]+d;
	for(i=1+d;i<=O;i++)
	if((a[i]-=b[i-d]*c)<0)
	a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH ;
	for(;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void mul(bignum_t c,const bignum_t a,const bignum_t b)
{
	ll i,j;
	memset((void*)c,0,sizeof(bignum_t));
	for(c[0]=a[0]+b[0]-1,i=1;i<=a[0];i++)
	for(j=1;j<=b[0];j++)
	if((c[i+j-1]+=a[i]*b[j])>=DEPTH)
	c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
	for(c[0]+=(c[c[0]+1]>0);!c[c[0]]&&c[0]>1;c[0]--);
}
void mul(bignum_t a,const ll b)
{
	ll i;
	for(a[1]*=b,i=2;i<=a[0];i++)
	{
		a[i]*=b ;
		if(a[i-1]>=DEPTH)
		a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH;
	}
	for(;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void mul(bignum_t b,const bignum_t a,const ll c,const ll d)
{
	ll i;
	memset((void*)b,0,sizeof(bignum_t));
	for(b[0]=a[0]+d,i=d+1;i<=b[0];i++)
	if((b[i]+=a[i-d]*c)>=DEPTH)
	b[i+1]+=b[i]/DEPTH,b[i]%=DEPTH ;
	for(;b[b[0]+1];b[0]++,b[b[0]+1]=b[b[0]]/DEPTH,b[b[0]]%=DEPTH);
	for(;!b[b[0]]&&b[0]>1;b[0]--);
}
void div(bignum_t c,bignum_t a,const bignum_t b)
{
	ll h,l,m,i;
	memset((void*)c,0,sizeof(bignum_t));
	c[0]=(b[0]<a[0]+1)?(a[0]-b[0]+2):1 ;
	for(i=c[0];i;sub(a,b,c[i]=m,i-1),i--)
	for(h=DEPTH-1,l=0,m=(h+l+1)>>1;h>l;m=(h+l+1)>>1)
	if(comp(b,m,i-1,a))h=m-1;
	else l=m;
	for(;!c[c[0]]&&c[0]>1;c[0]--);
	c[0]=c[0]>1?c[0]:1;
}
void div(bignum_t a,const ll b,ll&c)
{
	ll i;
	for(c=0,i=a[0];i;c=c*DEPTH+a[i],a[i]=c/b,c%=b,i--);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void sqrt(bignum_t b,bignum_t a)
{
	ll h,l,m,i;
	memset((void*)b,0,sizeof(bignum_t));
	for(i=b[0]=(a[0]+1)>>1;i;sub(a,b,m,i-1),b[i]+=m,i--)
	for(h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1;h>l;b[i]=m=(h+l+1)>>1)
	if(comp(b,m,i-1,a))h=m-1;
	else l=m;
	for(;!b[b[0]]&&b[0]>1;b[0]--);
	for(i=1;i<=b[0];b[i++]>>=1);
}
ll length(const bignum_t a)
{
	ll t,ret;
	for(ret=(a[0]-1)*DIGIT,t=a[a[0]];t;t/=10,ret++);
	return ret>0?ret:1;
}
ll digit(const bignum_t a,const ll b)
{
	ll i,ret;
	for(ret=a[(b-1)/DIGIT+1],i=(b-1)%DIGIT;i;ret/=10,i--);
	return ret%10;
}
ll zeronum(const bignum_t a)
{
	ll ret,t;
	for(ret=0;!a[ret+1];ret++);
	for(t=a[ret+1],ret*=DIGIT;!(t%10);t/=10,ret++);
	return ret;
}
void comp(ll*a,const ll l,const ll h,const ll d)
{
	ll i,j,t;
	for(i=l;i<=h;i++)
	for(t=i,j=2;t>1;j++)
	while(!(t%j))
	a[j]+=d,t/=j;
}
void convert(ll*a,const ll h,bignum_t b)
{
	ll i,j,t=1;
	memset(b,0,sizeof(bignum_t));
	for(b[0]=b[1]=1,i=2;i<=h;i++)
	if(a[i])
	for(j=a[i];j;t*=i,j--)
	if(t*i>DEPTH)
	mul(b,t),t=1;
	mul(b,t);
}
#define SGN(x) ((x)>0?1:((x)<0?-1:0))
#define ABS(x) ((x)>0?(x):-(x))
ll read(bignum_t a,ll&sgn,istream&is=cin)
{
	char str[MAXN*DIGIT+2],ch,*buf;
	ll i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if(!(is>>str))return 0;
	buf=str,sgn=1;
	if(*buf=='-')sgn=-1,buf++;
	for(a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
	ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch ;
	for(a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for(i=1;i<=a[0];i++)
	for(a[i]=0,j=0;j<DIGIT;j++)
	a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for(;!a[a[0]]&&a[0]>1;a[0]--);
	if(a[0]==1&&!a[1])sgn=0;
	return 1;
}
struct bigint
{
	bignum_t num;
	ll sgn;
	bigint(ll v){*this = v;}
	inline bigint()
	{
		memset(num,0,sizeof(bignum_t));
		num[0]=1;
		sgn=0;
	}
	inline ll operator!()
	{
		return num[0]==1&&!num[1];
	}
	inline bigint&operator=(const bigint&a)
	{
		memcpy(num,a.num,sizeof(bignum_t));
		sgn=a.sgn;
		return*this;
	}
	inline bigint&operator=(const ll a)
	{
		memset(num,0,sizeof(bignum_t));
		num[0]=1;
		sgn=SGN (a);
		add(num,sgn*a);
		return*this;
	}
	inline bigint&operator+=(const bigint&a)
	{
		if(sgn==a.sgn)add(num,a.num);
		else if(sgn&&a.sgn)
		{
			ll ret=comp(num,a.num);
			if(ret>0)sub(num,a.num);
			else if(ret<0)
			{
				bignum_t t;
				memcpy(t,num,sizeof(bignum_t));
				memcpy(num,a.num,sizeof(bignum_t));
				sub (num,t);
				sgn=a.sgn;
			}
			else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;
		}
		else if(!sgn) memcpy(num,a.num,sizeof(bignum_t)),sgn=a.sgn;
		return*this;
	}
	inline bigint&operator+=(const ll a)
	{
		if(sgn*a>0)add(num,ABS(a));
		else if(sgn&&a)
		{
			ll  ret=comp(num,ABS(a));
			if(ret>0)sub(num,ABS(a));
			else if(ret<0)
			{
				bignum_t t;
				memcpy(t,num,sizeof(bignum_t));
				memset(num,0,sizeof(bignum_t));
				num[0]=1;
				add(num,ABS (a));
				sgn=-sgn;
				sub(num,t);
			}
			else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0 ;
		}
		else if(!sgn) sgn=SGN(a),add(num,ABS(a));
		return*this;
	}
	inline bigint operator+(const bigint&a)
	{
		bigint ret;
		memcpy(ret.num,num,sizeof(bignum_t));
		ret.sgn=sgn;
		ret+=a;
		return ret;
	}
	inline bigint operator+(const ll a)
	{
		bigint ret;
		memcpy(ret.num,num,sizeof (bignum_t));
		ret.sgn=sgn;
		ret+=a;
		return ret;
	}
	inline bigint&operator-=(const bigint&a)
	{
		if(sgn*a.sgn<0)add(num,a.num);
		else if(sgn&&a.sgn)
		{
			ll ret=comp(num,a.num);
			if(ret>0)sub(num,a.num);
			else if(ret<0)
			{
				bignum_t t;
				memcpy(t,num,sizeof(bignum_t));
				memcpy(num,a.num,sizeof(bignum_t));
				sub(num,t);
				sgn=-sgn;
			}
			else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;
		}
		else if(!sgn)add(num,a.num),sgn=-a.sgn ;
		return*this ;
	}
	inline bigint&operator-=(const ll a)
	{
		if(sgn*a<0)add(num,ABS(a));
		else if(sgn&&a)
		{
			ll ret=comp(num,ABS(a));
			if(ret>0)sub(num,ABS(a));
			else if(ret<0)
			{
				bignum_t t;
				memcpy(t,num,sizeof(bignum_t));
				memset(num,0,sizeof(bignum_t));
				num[0]=1;
				add(num,ABS(a));
				sub(num,t);
				sgn=-sgn;
			}
			else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;
		}
		else if(!sgn)sgn=-SGN(a),add(num,ABS(a));
		return*this ;
	}
	inline bigint operator-(const bigint&a)
	{
		bigint ret;
		memcpy(ret.num,num,sizeof(bignum_t));
		ret.sgn=sgn;
		ret-=a;
		return ret;
	}
	inline bigint operator-(const ll a)
	{
		bigint ret;
		memcpy(ret.num,num,sizeof(bignum_t));
		ret.sgn=sgn;
		ret-=a;
		return ret;
	}
	inline bigint&operator*=(const bigint&a)
	{
		bignum_t t;
		mul(t,num,a.num);
		memcpy(num,t,sizeof(bignum_t));
		sgn*=a.sgn;
		return*this;
	}
	inline bigint&operator*=(const ll a)
	{
		mul(num,ABS(a));
		sgn*=SGN(a);
		return*this;
	}
	inline bigint operator*(const bigint&a)
	{
		bigint ret;
		mul(ret.num,num,a.num);
		ret.sgn=sgn*a.sgn ;
		return ret;
	}
	inline bigint operator*(const ll a)
	{
		bigint ret;
		memcpy(ret.num,num,sizeof(bignum_t));
		mul(ret.num,ABS(a));
		ret.sgn=sgn*SGN(a);
		return ret;
	}
	inline bigint&operator/=(const bigint&a)
	{
		bignum_t t;
		div(t,num,a.num);
		memcpy (num,t,sizeof(bignum_t));
		sgn=(num[0]==1&&!num[1])?0:sgn*a.sgn ;
		return*this;
	}
	inline bigint&operator/=(const ll a)
	{
		ll t;
		div(num,ABS(a),t);
		sgn=(num[0]==1&&!num [1])?0:sgn*SGN(a);
		return*this;
	}
	inline bigint operator/(const bigint&a)
	{
		bigint ret;
		bignum_t t;
		memcpy(t,num,sizeof(bignum_t));
		div(ret.num,t,a.num);
		ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*a.sgn ;
		return ret;
	}
	inline bigint operator/(const ll a)
	{
		bigint ret;
		ll t;
		memcpy(ret.num,num,sizeof(bignum_t));
		div(ret.num,ABS(a),t);
		ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*SGN(a);
		return ret;
	}
	inline bigint&operator%=(const bigint&a)
	{
		bignum_t t;
		div(t,num,a.num);
		if(num[0]==1&&!num[1])sgn=0;
		return*this;
	}
	inline ll operator%=(const ll a)
	{
		ll t;
		div(num,ABS(a),t);
		memset(num,0,sizeof(bignum_t));
		num[0]=1;
		add(num,t);
		return t;
	}
	inline bigint operator%(const bigint&a)
	{
		bigint ret;
		bignum_t t;
		memcpy(ret.num,num,sizeof(bignum_t));
		div(t,ret.num,a.num);
		ret.sgn=(ret.num[0]==1&&!ret.num [1])?0:sgn;
		return ret;
	}
	inline ll operator%(const ll a)
	{
		bigint ret;
		ll t;
		memcpy(ret.num,num,sizeof(bignum_t));
		div(ret.num,ABS(a),t);
		memset(ret.num,0,sizeof(bignum_t));
		ret.num[0]=1;
		add(ret.num,t);
		return t;
	}
	inline ll operator>(const bigint&a)
	{
		return sgn>0?(a.sgn>0?comp(num,a.num)>0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<0:0):a.sgn<0);
	}
	inline ll operator>(const ll a)
	{
		return sgn>0?(a>0?comp(num,a)>0:1):(sgn<0?(a<0?comp(num,-a)<0:0):a<0);
	}
	inline ll operator>=(const bigint&a)
	{
		return sgn>0?(a.sgn>0?comp(num,a.num)>=0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<=0:0):a.sgn<=0);
	}
	inline ll operator>=(const ll a)
	{
		return sgn>0?(a>0?comp(num,a)>=0:1):(sgn<0?(a<0?comp(num,-a)<=0:0):a<=0);
	}
	inline ll operator<(const bigint&a)
	{
		return sgn<0?(a.sgn<0?comp(num,a.num)>0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<0:0):a.sgn>0);
	}
	inline ll operator<(const ll a)
	{
		return sgn<0?(a<0?comp(num,-a)>0:1):(sgn>0?(a>0?comp(num,a)<0:0):a>0);
	}
	inline ll operator<=(const bigint&a)
	{
		return sgn<0?(a.sgn<0?comp(num,a.num)>=0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<=0:0):a.sgn>=0);
	}
	inline ll operator<=(const ll a)
	{
		return sgn<0?(a<0?comp(num,-a)>=0:1):(sgn>0?(a>0?comp(num,a)<=0:0):a>=0);
	}
	inline ll operator==(const bigint&a)
	{
		return(sgn==a.sgn)?!comp(num,a.num):0;
	}
	inline ll operator==(const ll a)
	{
		return(sgn*a>=0)?!comp(num,ABS(a)):0;
	}
	inline ll operator!=(const bigint&a)
	{
		return(sgn==a.sgn)?comp(num,a.num):1 ;
	}
	inline ll operator!=(const ll a)
	{
		return(sgn*a>=0)?comp(num,ABS(a)):1 ;
	}
	inline ll operator[](const ll a)
	{
		return digit(num,a);
	}
	friend inline istream&operator>>(istream&is,bigint&a)
	{
		read(a.num,a.sgn,is);
		return is;
	}
	friend inline ostream&operator<<(ostream&os,const bigint&a)
	{
		if(a.sgn<0) os<<'-';
		write(a.num,os);
		return os;
	}
	friend inline bigint sqrt(const bigint&a)
	{
		bigint ret;
		bignum_t t;
		memcpy(t,a.num,sizeof(bignum_t));
		sqrt(ret.num,t);
		ret.sgn=ret.num[0]!=1||ret.num[1];
		return ret;
	}
	friend inline bigint sqrt(const bigint&a,bigint&b)
	{
		bigint ret;
		memcpy(b.num,a.num,sizeof(bignum_t));
		sqrt(ret.num,b.num);
		ret.sgn=ret.num[0]!=1||ret.num[1];
		b.sgn=b.num[0]!=1||ret.num[1];
		return ret;
	}
	inline ll length()
	{
		return :: length(num);
	}
	inline ll zeronum()
	{
		return :: zeronum(num);
	}
};
bigint gcd(bigint a,bigint b)
{
	return b==0?a:gcd(b,a%b);
}
bigint lcm(bigint a,bigint b)
{
	return a/gcd(a,b)*b;
}
