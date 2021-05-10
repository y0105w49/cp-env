// {{{ y0105w49 template 21K10
// hi mom
// #include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#ifdef ARST
#define JO 1
#define OJ 0
#else
#define JO 0
#define OJ 1
#endif
#define STR(x) #x
#define GCCDIAG(s) _Pragma(STR(GCC diagnostic s)) static_assert(true)
#define Wsave GCCDIAG(push)
#define Wpop GCCDIAG(pop)
#define Wsupp(w) GCCDIAG(ignored "-W" w)
#define Wpush(w) Wsave; Wsupp(w)
#define typeof __typeof__
namespace gbd_ns {
	template<typename C>
	struct is_iterable {
		template<class T> static long check(...);
		template<class T> static char check(int,typename T::const_iterator = C().end());
		enum {
			value = sizeof(check<C>(0)) == sizeof(char),
			neg_value = sizeof(check<C>(0)) != sizeof(char)
		};
	};
	template<bool B,typename T=void> using eit=typename enable_if<B,T>::type;
	template<class T> struct _gbd3C;
	template<class T> ostream &_gbd3(ostream &os,const T &x) {
		return _gbd3C<T>::call(os,x);
	}
	template<> ostream &_gbd3(ostream &os,const string &x) {
		return os<<'"'<<x<<'"';
	}
	template<> ostream &_gbd3(ostream &os,char *const &x) {
		return os<<'"'<<x<<'"';
	}
	template<class T> ostream &_gbd35(ostream &os,const T &x) {
		return _gbd3(os,x);  // why??
	}
	template<class A,class B>
	ostream &_gbd4(ostream &os,const pair<A,B> &p) {
		_gbd3(os<<'(',p.first);
		_gbd3(os<<',',p.second);
		return os<<')';
	}
	template<class T,size_t N> struct _gbd4_tupleC {
		static void call(ostream &os,const T &t) {
			_gbd4_tupleC<T,N-1>::call(os,t);
			os<<','<<get<N-1>(t);
		}
	};
	template<class T> struct _gbd4_tupleC<T,1> {
		static void call(ostream &os,const T &t) {
			os<<get<0>(t);
		}
	};
	template<typename... Types>
	ostream &_gbd4(ostream &os,const tuple<Types...> &t) {
		os<<'(';
		_gbd4_tupleC<tuple<Types...>,sizeof...(Types)>::call(os,t);
		return os<<')';
	}
	template<>
	ostream &_gbd4(ostream &os,const tuple<> &t) { (void)t; return os<<"()"; }
	template<class T> ostream &_gbd4(ostream &os,const T &x) {
		return os<<x;
	}
	template<class T> struct _gbd3C {
		template<class U=T>
		static ostream &call(ostream &os,eit<is_iterable<U>::value,const T> &V) {
			os<<"{";
			bool ff=0;
			for(const auto &E:V) _gbd35<decltype(E)>(ff?os<<",":os,E), ff=1;
			return os<<"}";
		}
		template<class U=T>
		static ostream &call(ostream &os,eit<is_iterable<U>::neg_value,const T> &x) {
			return _gbd4(os,x);
		}
	};
	template<class T,typename... Args> ostream &_gbd2(ostream &os,bool,vector<string>::iterator nm,const T &x,Args&&... args);
	ostream &_gbd2(ostream &os,bool,vector<string>::iterator) { return os; }
	template<typename... Args>
	ostream &_gbd2(ostream &os,bool fi,vector<string>::iterator nm,const char *x,Args&&... args) {
		return _gbd2(os<<(fi?"":"  ")<<x,0,nm+1,args...);
	}
	template<class T,typename... Args>
	ostream &_gbd2(ostream &os,bool fi,vector<string>::iterator nm,const T &x,Args&&... args) {
		return _gbd2(_gbd3<T>(os<<(fi?"":"  ")<<*nm<<"=",x),0,nm+1,args...);
	}
	vector<string> split(string s) {
		vector<string> Z;
		string z="";
		s+=',';
		int dep=0;
		for(char c:s) {
			if(c==',' && !dep) Z.push_back(z),z="";
			else z+=c;
			if(c=='(') ++dep;
			if(c==')') --dep;
		}
		return Z;
	}
	template<typename... Args> ostream &_gbd1(ostream &os,const string &nm,Args&&... args) {
		return _gbd2(os,1,split(nm).begin(),args...);
	}
	template<typename... Args> string _gbd1(const string &nm,Args&&... args) {
		ostringstream oss;
		_gbd2(oss,1,split(nm).begin(),args...);
		return oss.str();
	}
}
bool DBG=1,EMACS=0;
#define dbg(...) (JO&&DBG?gbd_ns::_gbd1(cerr<<"\033[38;5;5m"<<__FILE__<<":"<<__LINE__<<(EMACS?":note: ":": "),#__VA_ARGS__,__VA_ARGS__)<<"\033[0m"<<endl:cerr)
#define fmt(...) gbd_ns::_gbd1(#__VA_ARGS__,__VA_ARGS__)
template<class Fun> struct _y_combinator_result {
	Fun _fun;
	template<class T> explicit _y_combinator_result(T &&fun) : _fun(forward<T>(fun)) {}
	template<typename... Args> decltype(auto) operator()(Args &&... args) {
		return _fun(ref(*this),forward<Args>(args)...);
	}
};
template<class Fun> [[nodiscard]] decltype(auto) fix(Fun &&fun) {
	return _y_combinator_result<decay_t<Fun>>(forward<Fun>(fun));
}
#define nop void()
#define sz(x) (int((x).size()))
#define all(v) begin(v),end(v)
#define sortu(v) (sort(all(v)), (v).resize(unique(all(v))-begin(v)))
#define forenum(i,...) for(int i:{-1}) for(__VA_ARGS__) if(++i,0) assert(0); else
#define forenumll(i,...) for(long long i:{-1}) for(__VA_ARGS__) if(++i,0) assert(0); else
#define forbs(k,i,bs) for(ptrdiff_t k=0,i=(bs)._Find_first();i<(ptrdiff_t)(bs).size();i=(bs)._Find_next(i),++k)
#define get(x,i) get<i>(x)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
template<class S,class T> using omap=__gnu_pbds::tree<S,T,less<S>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<class T> using oset=omap<T,__gnu_pbds::null_type>;
template<class T> using rope=__gnu_cxx::rope<T>;
const int e0=1, e1=10, e2=100, e3=1000;
const int e4=10*e3, e5=100*e3, e6=1000*e3;
const int e7=10*e6, e8=100*e6, e9=1000*e6;
const long long e12=1LL*e3*e9, e15=1LL*e6*e9, e18=1LL*e9*e9;
using ulll=__uint128_t;
using lll=__int128_t;
using ull=unsigned long long;
using ll=long long;
unsigned long long START_TIME;
inline unsigned long long now_μs() { return chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now().time_since_epoch()).count()-START_TIME; }
const char *fmt_time(unsigned long long μs=now_μs()) { static char dur[19]; sprintf(dur,"%llu.%02llus",μs/e6,(μs%e6)/e4); return dur; }
#define timed(cb) do { dbg("timed "#cb" ..."); unsigned long long start=now_μs(); cb; dbg("timed "#cb" took",fmt_time(now_μs()-start)); } while(0)
int gen; bool inp; int seed; vector<string> args;
mt19937 gen_input,gen_actual;
template<class T> T irand(const T &l,const T &r) { return uniform_int_distribution<T>(l,r)(gen_input); }
template<class T> T irand(const T &n) { return irand(T(1),n); }
template<class T> T rand(const T &l,const T &r) { return uniform_int_distribution<T>(l,r)(gen_actual); }
template<class T> T rand(const T &n) { return rand(T(1),n); }
[[deprecated]] int rand() { return rand(0,numeric_limits<int>::max()); }
#define random_shuffle(...) static_assert(false,"random_shuffle deprecated, use shuffle")
#define in(x,e) (inp?cin>>(x),nop:((x)=(e),nop))
#define inr(x,...) in(x,irand(__VA_ARGS__))
#define endl '\n'
void exit0() { dbg("finished (early) in",fmt_time()); exit(0); }
void _main();
int32_t main([[maybe_unused]]int argc,[[maybe_unused]]char *argv[]) {
	START_TIME=chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now().time_since_epoch()).count();
	ios_base::sync_with_stdio(0); cin.tie(0);
	gen=0; seed=int(OJ?START_TIME:START_TIME%e5);
	args={argv,argv+argc};
	if(sz(args)>1) {
		if(args[1][0]=='i') freopen((string(__FILE__).substr(0,string(__FILE__).find('.'))+"."+args[1].substr(1)+".in").c_str(),"r",stdin);
		else gen=stoi(args[1]);
	}
	if(sz(args)>2 && args[2][0]!='.') seed=stoi(args[2]);
	inp=!gen;
	gen_input.seed(seed*2+1); gen_actual.seed(seed*2+2);
	if(getenv("EMACS")) EMACS=1;
	dbg(seed,gen,args);
	_main();
	dbg("finished in",fmt_time());
}
using flt=double; //CARE
const flt ε=(flt)1e-8;
const flt τ=(flt)(2*acosl(-1));
const int inf=e9+99;
const ll linf=1LL*e9*e9+99;
// }}}
const int P=e9+7;//998'244'353;










void _main() { /* CURSOR START */
	
}



