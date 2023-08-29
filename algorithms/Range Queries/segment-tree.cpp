#include <bits/stdc++.h>
#define ll long long
#define inf (int)1e9
using namespace std;

//Segment Tree functions:
#define left p<<1 , l , (l+r)>>1
#define right p<<1|1 , ((l+r)>>1)+1 , r

vector<int> seg(400100) , a(100100) , lazy(400100);

int build(int p , int l , int r){
    if(l==r) return seg[p] = a[l];
    return seg[p] = (build(left) + build(right)); //to change
}

void push(int p){
    if(!lazy[p]) return;
    seg[p<<1] += lazy[p]; seg[p<<1|1] += lazy[p];
    lazy[p<<1] += lazy[p]; lazy[p<<1|1] +=lazy[p];
    lazy[p] = 0;
}

int update(int i , int j , int inc , int p , int l , int r){
    if(j<l || r<i) return seg[p];
    if(i<=l && r<=j) return lazy[p] += inc, seg[p] += inc; //to change
    push(p);
    return seg[p] = (update(i , j , inc , left) + update(i , j , inc , right)); //to change
}

int query (int i , int j , int p , int l , int r){
    if(j<l  ||  r<i) return inf; // to change
    if(i<=l && r<=j) return seg[p];
    push(p);
    return (query(i , j , left) + query(i , j , right)); //to change
}

//binary search inside segment tree
int query(int k , int p , int l , int r){
    // check not found case
    if(seg[p] < k) return -1;

    // return the answer
    if(l==r) return l;

    // check the condition and go left or right
    if(seg[p<<1] >= k){
        return query(k , left);
    }
    return query(k-seg[p<<1] , right);
}

//searching for the first element greater than <a> in a given range
int query(int i , int j , int k , int p , int l , int r){
    // check out of the range
    if(j<l  ||  r<i) return -1;

    // check inside the range
    if(i<=l && r<=j){
        // check not found case
        if(seg[p] <= k) return -1;

        // return the answer
        if(l==r) return l;

        // check the condition and go left or right
        if(seg[p<<1] > k){
            return query(i , j , k , left);
        }
        return query(i , j , k , right);
    }

    // go left and right to get the ans
    int ans = query(i , j , k , left);
    if(ans!=-1) return ans;
    return query(i , j , k , right);
}


//Finding subsegments with the maximal sum:

// out of range case in query is node(0)
struct node {
    int sum , prefix , suffix , ans;

    node(){}

    node(int val){
        this->sum = val;
        this->prefix = this->suffix = this->ans = max(0, val);
    }
};

node merge(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    res.prefix = max(l.prefix , l.sum + r.prefix);
    res.suffix = max(r.suffix , r.sum + l.suffix);
    res.ans = max({l.ans , r.ans , l.suffix+r.prefix});
    return res;
}


//Merge Sort Segment Tree:

//find the smallest number greater or equal to a specified number
vector<vector<int>> seg(400100);
vector<int> a(100100);

vector<int> build(int p , int l , int r){
    if(l==r) return seg[p] = vector<int> (1 , a[l]);
    auto first = build(left);
    auto second = build(right);
    merge(first.begin() , first.end() , second.begin() , second.end() , back_inserter(seg[p]));
    return seg[p];
}

int query (int i , int j , int val , int p , int l , int r){
    if(j<l  ||  r<i) return inf; //to change
    if(i<=l && r<=j){
        auto pos = lower_bound(seg[p].begin() , seg[p].end() , val);
        if(pos!=seg[p].end()) return *pos;
        return inf;
    }
    return min(query(i , j , val , left) , query(i , j , val , right));
}

//to make point update query use multiset
vector<multiset<int>> seg(400100);

void update(int i , int val , int p , int l , int r){
    seg[p].erase(seg[p].find(a[i]));
    seg[p].insert(val);
    if(l!=r) {
        if(i <= (l+r)>>1)
            update(i , val , left);
        else 
            update(i , val , right);
    }
    else a[i] = val;
}


//2D Segment Tree:
#define leftX px<<1 , lx , (lx+rx)>>1
#define rightX px<<1|1 , ((lx+rx)>>1)+1 , rx
#define leftY py<<1 , ly , (ly+ry)>>1
#define rightY py<<1|1 , ((ly+ry)>>1)+1 , ry

struct SegmentTree2D{
    int n , m;
    vector<vector<int>> seg;
    vector<vector<int>> &a;
    
    SegmentTree2D(int n , int m , vector<vector<int>> &a) : a(a){
        this->n = n;
        this->m = m;
        seg.assign(n*4+10 , vector<int> (m*4+10));
        build(1 , 0 , n-1);
    }

    void build(int px , int lx , int rx){
        if(lx!=rx){
            build(leftX);
            build(rightX);
        }
        buildY(px , lx , rx , 1 , 0 , m-1);
    }

    void buildY(int px , int lx , int rx , int py , int ly , int ry){
        if(ly==ry){
            if(lx==rx) seg[px][py] = a[lx][ly];
            else seg[px][py] = (seg[px<<1][py] + seg[px<<1|1][py]); //to change
        }
        else{
            buildY(px , lx , rx , leftY);
            buildY(px , lx , rx , rightY);
            seg[px][py] = (seg[px][py<<1] + seg[px][py<<1|1]); //to change
        }
    }

    void update(int x , int y , int val , int px , int lx , int rx){
        if(lx!=rx){
            if(x <= (lx+rx)>>1)
                update(x , y , val , leftX);
            else
                update(x , y , val , rightX);
        }
        updateY(x , y , val , px , lx , rx , 1 , 0 , m-1);
    }

    void updateY(int x , int y , int val , int px , int lx , int rx , int py , int ly , int ry){
        if(ly==ry){
            if(lx==rx) seg[px][py] = val; //to change
            else seg[px][py] = (seg[px<<1][py] + seg[px<<1|1][py]); //to change
        }
        else{
            if(y <= (ly+ry)>>1)
                updateY(x , y , val , px , lx , rx , leftY);
            else
                updateY(x , y , val , px , lx , rx , rightY);
            seg[px][py] = (seg[px][py<<1] + seg[px][py<<1|1]); //to change
        }
    }

    //        from x    to x    from y    to y
    int query(int x1 , int x2 , int y1 , int y2 , int px , int lx , int rx){
        if(x2<lx || rx<x1 || x1 > x2) return 0; //to change
        if(x1<=lx && rx<=x2) return queryY(y1 , y2 , px , 1 , 0 , m-1);
        return (query(x1 , x2 , y1 , y2 , leftX) + 
                    query(x1 , x2 , y1 , y2 , rightX)); //to change      
    }

    int queryY(int y1 , int y2 , int px , int py , int ly , int ry){
        if(y2<ly || ry<y1 || y1 > y2) return 0; //to change
        if(y1<=ly && ry<=y2) return seg[px][py];
        return (queryY(y1 , y2 , px , leftY) + queryY(y1 , y2 , px , rightY)); //to change
    }
};


//Persistent Segment Tree:
#define left l , (l+r)>>1
#define right ((l+r)>>1)+1 , r

struct PersistentSegTree{
    struct Vertex {
        Vertex *l, *r;
        int sum;

        Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
        Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
            if (l) sum += l->sum;
            if (r) sum += r->sum;
        }
        //to change marge
    };

    int n;
    vector<int> &a;
    vector<Vertex*> roots;

    PersistentSegTree(int n  , vector<int> &a) : a(a) {
        this->n = n;
        roots.push_back(build(0 , n-1));
    }

    Vertex* build(int l , int r){
        if(l==r) return new Vertex(a[l]);
        return new Vertex(build(left) , build(right));
    }

    //point update
    void update(int i , int val , int rootIndex){
        roots.push_back(
            update(i , val , roots[rootIndex] , 0 , n-1)
        );
    }

    Vertex* update(int i , int val , Vertex* p , int l , int r){
        if(l==r) return new Vertex(val); //to change
        if(i <= (l+r)>>1)
            return new Vertex(update(i , val , p->l , left) , p->r);
        else
            return new Vertex(p->l , update(i , val , p->r , right));
    } 

    //use this function
    int query(int i , int j , int rootIndex){
        return query(i , j , roots[rootIndex] , 0 , n-1);
    }

    int query (int i , int j , Vertex* p , int l , int r){
        if(j<l  ||  r<i) return 0; // to change
        if(i<=l && r<=j) return p->sum;
        return (query(i , j , p->l , left) + query(i , j , p->r , right)); //to change
    }
};

//Finding the kth smallest number in a range
//the index of range should be the same with index or roots
int find(int i , int j , int k){
        return find(k , roots[i] , roots[j+1] , 0 , n-1);
}

int find(int k , Vertex *p1 , Vertex *p2 , int l , int r){
    // check not found case
    if(p2->sum-p1->sum < k) return inf;
    
    // return the answer
    if(l==r) return l;

    // check the condition and go left or right
    int count = p2->l->sum-p1->l->sum;
    if(k <= count)
        find(k , p1->l , p2->l , left);
    else
        find(k - count , p1->r , p2->r , right);
}


//Dynamic segment tree with lazy:
#define left l , (l+r)>>1
#define right ((l+r)>>1)+1 , r

struct DynamicSegTree{
    struct Vertex {
        int value , lazy , l , r;
        Vertex *lChild, *rChild;    

        Vertex(int value , int l , int r) : 
            lChild(nullptr), rChild(nullptr), 
            value(value), lazy(0) , l(l) , r(r){}

        void extend() {
            if(lChild==nullptr){
                lChild = new Vertex(0 , left);
                rChild = new Vertex(0 , right);
            }
        }
    };
    Vertex *root;
    int n;

    DynamicSegTree(int n) : n(n){
        root = new Vertex(0 , 0 , n);
    }

    void push(Vertex *p){
        if(!(p->lazy)) return;
        //product in size of segment if you want all element to inc
        p->lChild->value+=p->lazy; p->rChild->value+=p->lazy;
        p->lChild->lazy+=p->lazy;  p->rChild->lazy+=p->lazy;
        p->lazy = 0;
    }

    void update(int i , int j , int val){
        update(i , j , val , root);
    }

    int update(int i , int j , int val , Vertex *p){
        if(j<p->l || p->r<i) return p->value;
        if(i<=p->l && p->r<=j){
            p->lazy+=val; //to change
            p->value+=val; //to change
            return p->value;
        }
        p->extend(); push(p);
        return p->value = (update(i , j , val , p->lChild) +
                             update(i , j , val , p->rChild)); //to change
    }

    int query(int i , int j){
        return query(i , j , root);
    }

    int query(int i , int j , Vertex *p){
        if(j<p->l || p->r<i) return 0; //to change
        if(i<=p->l && p->r<=j) return p->value;
        p->extend(); push(p);
        return (query(i , j , p->lChild) + query(i , j , p->rChild)); //to change
    }
};

//Compress number in vector:
void compress(vector<int> &vec) {
    vector<int> val(vec.begin(), vec.end());
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for(auto &x:vec) x = lower_bound(val.begin(), val.end(), x) - val.begin();
}