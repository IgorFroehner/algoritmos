#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
     vi ft;
public:
    FenwickTree() {}
    // initialization: n + 1 zeroes, ignore index 0
    FenwickTree(int n) { ft.assign(n + 1, 0); }

    int rsq(int b) {                                     // returns RSQ(1, b)
        int sum = 0; 
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum; 
        }

    int rsq(int a, int b) {                              // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
    }

    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int k, int v) {                    // note: n = ft.size() - 1
        for (; k < (int)ft.size(); k += LSOne(k))
            ft[k] += v; 
    }
};

int main() {

    FenwickTree ft(10);
    int n = 10;
    int vet[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=1; i<=n; i++){
        ft.adjust(i, vet[i]);
    }
    cout << ft.rsq(4) << endl;
    cout << ft.rsq(4) << endl;

} 