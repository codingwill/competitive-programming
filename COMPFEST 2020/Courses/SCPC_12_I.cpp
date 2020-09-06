#include <iostream>
using namespace std;
typedef long long ll;
typedef long double ld;

const int C = (int)5e4 + 5;

namespace segtree {
  struct Line {
    ld m, b;
    ld operator()(ld x) { return a * x + b * y; }
  } a[C * 4];
  
  void insert(int l, int r, Line seg, int o=0) {
    if(l + 1 == r) {
      if(seg(l) > a[o](l)) a[o] = seg;
      return;
    }
    int mid= (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
    if(a[o].m > seg.m) swap(a[o], seg);
    if(a[o](mid) < seg(mid)) {
      swap(a[o], seg);
      insert(l, mid, seg, lson);
    }
    else insert(mid, r, seg, rson);
  }
  ld query(int l, int r, int x, int o=0) {
    if(l + 1 == r) return a[o](x);
    int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
    if(x < mid) return max(a[o](x), query(l, mid, x, lson));
    else return max(a[o](x), query(mid, r, x, rson));
  }
}

void init() {
}
void solve() {
  int q; cin >> q;
  while(q--) {
    string s; cin >> s;
    if(s[0] == 'P') {
      ld b, m; cin >> b >> m;
      segtree::insert(1, C, {a, b - a});
    }
    else {
      int x; cin >> x;
      cout << (int)(segtree::query(1, C, x) / 100) << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  init();
  solve();
}
/*
2 3
2 2
1 4
4 5
3 6
1 7


1 4 {(1, 7)}
1 3 {(1, 7)}
1 2 {(1, 7), (3, 6)}
1 1 {(6, 4)}
2 2


      Ci
       
1  7 = 0
3  6 = 1
4  5 = 3
6  4 = 3
5  4 = 4
13 2 = 

      Ci
       4  3  2  1
1  7 = 29 22 15  8
3  6 = 27 21 15  9
4  5 = 24 19 14  9
6  4 = 22 18 14 10
5  4 = 21 17 13  9
13 2 = 21 19 17 15

1 7 = 0  0  0  0
3 6 = 2  1  0  -1  
4 5 = 3  2  1  0
6 4 = 2  1  0  -1
5 4 = 1  1  1  1

1 7 = 0  0  0   0
3 6 = 2  1  0  -1
4 5 = 5  3  1  -1
6 4 = 7  4  1  -2
5 4 = 8  5  2  -1
*/