#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
    private: vi st, v;
    int n;
    int left (int p) {return p << 1;}
    int right(int p) {return (p << 1)+1;}

    void build(int p, int l, int r){
        if (l==r) st[p] = v[l];
        else{
            int mid = (l+r)/2;

            build(left(p), l, mid);
            build(right(p), mid + 1, r);

            st[p] = st[left(p)]+st[right(p)];
        }
    }

    int rsq(int p, int l, int r, int i, int j){
        if (i>r || j<l) return 0;
        if (l>=i && r<=j) return st[p];
        int mid = (l+r)/2;
        return rsq(left(p), l, mid, i, j) + rsq(right(p), 1+mid , r, i, j);
    }

    void update(int p, int l, int r, int i, int x){
        if(l==r) st[p] = x;
        else{
            int mid = (l+r)/2;
            if(i<=mid) update(left(p), l, mid, i, x);
            else update(right(p), mid+1, r, i, x);
            st[p] = st[left(p)] + st[right(p)];
        }
    }

    public:
    SegmentTree(const vi &_v){
        v = _v;
        n = (int)v.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    void update(int i, int x) { update(1, 0, n-1, i, x); }
    int rsq(int i, int j) { return rsq(1, 0, n-1, i, j); }
};

int main(){
    int vet[10] = {0,0,0,0,0,0,0,0,0,0};
    vi v(vet, vet+10);

    SegmentTree st(v);
    cout << st.rsq(0,5) <<  endl;
    st.update(0,100);
    cout << st.rsq(0,5) << endl;

    return 0;
}