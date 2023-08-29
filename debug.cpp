#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim> typename enable_if<sizeof dud<c>(0) x 1,debug&>::type operator<<(c i){
sim>struct rge{c b,e;};sim>rge<c>range(c i,c j){return rge<c>{i,j};}
sim>auto dud(c*x)->decltype(cerr<<*x,0);sim>char dud(...);
struct debug {
eni(!=) cerr<<boolalpha<<i;ris;}eni(==)ris<<range(begin(i),end(i));}
sim, class b dor(pair<b,c>d){ris<<"("<<d.first<<", "<<d.second<<")";}sim dor(rge<c> d)
{*this<<"[";for(auto it=d.b;it!=d.e;++it)*this<<", "+2*(it==d.b)<<*it; ris<<"]";}
};
vector<char*> tokenizer(const char* a){
  char *t = new char[99]; strcpy(t, a);t=strtok(t,", ");vector<char*> v({t});
  while(t=strtok(NULL,", ")) v.push_back(t);return reverse(v.begin(), v.end()),v;
}
void _dbg(vector<char*> &a){cerr<<endl;}

template <typename Head, typename... Tail>void _dbg(vector<char*> a, Head H, Tail... T){
  debug()<<"["<<a.back()<<": "<<H<<"] ";a.pop_back(); _dbg(a, T...);
}
#define harg(...) #__VA_ARGS__
#define dbg(...) ((void)_dbg(tokenizer(#__VA_ARGS__), __VA_ARGS__))