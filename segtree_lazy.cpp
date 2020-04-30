#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
  int n;
  vi t, lazy, v;
  int right(int p) { return (p << 1)+2; }
  int left(int p) { return (p << 1)+1; }

  void push(int p, int l, int r){
    if (lazy[p] != 0) { 
      t[p] += (r-l+1)*lazy[p]; 
      if (l != r) {
        lazy[left(p)] += lazy[p]; 
        lazy[right(p)] += lazy[p]; 
      }
      lazy[p] = 0; 
    }
  }

  void update(int p, int l, int r, int i, int j, int x) { 
    push(p, l, r);
    if (l>r || l>j || r<i) return ; 
    if (l>=i && r<=j) {
      lazy[p] += x;
      push(p, l, r);
      return; 
    }
    int mid = (l+r)/2; 
    update(left(p), l, mid, i, j, x); 
    update(right(p), mid+1, r, i, j, x);
    t[p] = t[left(p)] + t[right(p)]; 
  }

  int rsq(int p, int l, int r, int i, int j) { 
    push(p, l, r);
    if (l>r || l>j || r<i) return 0;
    if (l>=i && r<=j) return t[p]; 

    int mid = (l + r)/2; 
    return rsq(left(p), l, mid, i, j) + rsq(right(p), mid+1, r, i, j); 
  }

  void build(int l, int r, int p) { 
    if (l > r) return ; 
    if (l == r) { 
      t[p] = v[l]; 
      return; 
    }
    int mid = (l + r)/2; 
    build(l, mid, left(p)); 
    build(mid+1, r, right(p)); 
    t[p] = t[left(p)] + t[right(p)]; 
  }

public:
  SegmentTree(const vi &_v){
    v = _v;
    n = (int)v.size();
    t.assign(n*4, 0);
    lazy.assign(n*4, 0);
    build(0, n-1, 0);
  }
  void update(int i, int j, int x) { update(0, 0, n-1, i, j, x); } 
  int rsq(int i, int j) { return rsq(0, 0, n-1, i, j); } 
};