struct FAST_MOD  // Montgomery modular multiplication
{
	#define mod_byte 64  // 32 or 64
	
#if mod_byte==32
	#define itype int32_t
	#define utype uint32_t
	#define utype2 uint64_t
#else
	#define itype int64_t
	#define utype uint64_t
	#define utype2 __uint128_t
#endif

	static utype mod,r,r2;
	utype x;
	static utype init(utype x){return reduce(utype2(x)*r2);}
	static utype get_mod(){return mod;}
	static void set_mod(utype m)
	{
		mod=r=m;
		assert((mod&1)&&m>2);
		for(int i=0;i<5;i++) r*=2-r*m;
		r2=-utype2(m)%m;
	}
	static utype reduce(utype2 x)
	{
		utype y=utype(x>>mod_byte)-utype((utype2(utype(x)*r)*mod)>>mod_byte);
		return itype(y)<0?y+mod:y;
	}
	FAST_MOD():x(0){}
	FAST_MOD(utype n):x(init(n)){}
	FAST_MOD operator+(const FAST_MOD &a)const {return FAST_MOD(*this)+=a;}
	FAST_MOD operator-(const FAST_MOD &a)const {return FAST_MOD(*this)-=a;}
	FAST_MOD operator*(const FAST_MOD &a)const {return FAST_MOD(*this)*=a;}
	FAST_MOD& operator+=(const FAST_MOD &a)
	{
		x+=a.x-mod;
		if(itype(x)<0) x+=mod;
		return *this;
	}
	FAST_MOD& operator-=(const FAST_MOD &a)
	{
		x=x>=a.x?x-a.x:mod-a.x+x;
		return *this;
	}
	FAST_MOD& operator*=(const FAST_MOD &a)
	{
		x=reduce(utype2(x)*a.x);
		return *this;
	}
	FAST_MOD& operator++()
	{
		x++;
		if(x==mod) x=0;
		return *this;
	}
	FAST_MOD& operator++(int)
	{
		x++;
		if(x==mod) x=0;
		return *this;
	}
	FAST_MOD& operator--()
	{
		if(x==0) x=get_mod();
		x--;
		return *this;
	}
	FAST_MOD& operator--(int)
	{
		if(x==0) x=get_mod();
		x--;
		return *this;
	}
//	friend bool operator<(const FAST_MOD& a,const FAST_MOD& b){return reduce(a.x)<reduce(b.x);}
//	friend bool operator>(const FAST_MOD& a,const FAST_MOD& b){return reduce(a.x)>reduce(b.x);}
	friend bool operator==(const FAST_MOD& a,const FAST_MOD& b){return a.x==b.x;}
	friend bool operator!=(const FAST_MOD& a,const FAST_MOD& b){return a.x!=b.x;}
	friend ostream &operator<<(ostream &os, const FAST_MOD &a){return os<<reduce(a.x);}
	utype get_val()const {return reduce(x);}
};
utype FAST_MOD::mod,FAST_MOD::r,FAST_MOD::r2;
#undef itype
#undef utype
#undef utype2
typedef FAST_MOD mint;
/*
mint::set_mod(p);
*/
