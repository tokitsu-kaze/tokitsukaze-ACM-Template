typedef long long i64;
typedef unsigned long long u64;
typedef __uint128_t u128;
const int word_bits=sizeof(u64)*8;
struct FastMod
{
	static u64 mod,inv,r2;
	u64 x;
	FastMod():x(0){}
	FastMod(u64 n):x(init(n)){}
	static u64 modulus(){return mod;}
	static u64 init(u64 w){return reduce(u128(w)*r2);}
	static void set_mod(u64 m)
	{
		mod=m;
		assert(mod&1);
		inv=m;
		for(int i=0;i<5;i++) inv*=2-inv*m;
		r2=-u128(m)%m;
	}
	static u64 reduce(u128 x)
	{
		u64 y=u64(x>>word_bits)-u64((u128(u64(x)*inv)*mod)>>word_bits);
		return i64(y)<0?y+mod:y;
	}
	FastMod& operator+=(FastMod rhs)
	{
		x+=rhs.x-mod;
		if(i64(x)<0) x+=mod;
		return *this;
	}
	FastMod operator+(FastMod rhs)const {return FastMod(*this)+=rhs;}
	FastMod& operator*=(FastMod rhs)
	{
		x=reduce(u128(x)*rhs.x);
		return *this;
	}
	FastMod operator*(FastMod rhs)const {return FastMod(*this)*=rhs;}
	u64 get()const {return reduce(x);}
};
u64 FastMod::mod,FastMod::inv,FastMod::r2;
// FastMod::set_mod(p);
