#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define _GLIBCXX_DEBUG_PEDANTIC
#endif

#include "bits/stdc++.h"

#define F first
#define S second
#define pb push_back
#define all(a) a.begin(), a.end()
#define fr(i, a, b) for (auto i = (a); i < (b); i++)
#define sz(x) (int)x.size()
#define nl '\n'

#define int long long
using namespace std;

void SCONF() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
}

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;

const int INF = 1e9;
const ll INFLL = 1e18;
const int MAXN = 110000;
const int LOG = 21;
const string ANS[] = {"No", "Yes"};

//    vpi g[MAXN];
//    vi tin(MAXN), tout(MAXN);
//    vector<vpi> binup(MAXN, vpi(LOG, {1, INF}));
//    int timer = 0;


//    ╔══╗───╔╗╔╗╔══╗╔═══╗───╔══╗╔═══╗╔══╗╔╗╔╗───╔══╗─╔════╗╔╗╔╗╔╗
//    ╚╗╔╝───║║║║║╔═╝║╔══╝───║╔╗║║╔═╗║║╔═╝║║║║───║╔╗║─╚═╗╔═╝║║║║║║
//    ─║║────║║║║║╚═╗║╚══╗───║╚╝║║╚═╝║║║──║╚╝║───║╚╝╚╗──║║──║║║║║║
//    ─║║────║║║║╚═╗║║╔══╝───║╔╗║║╔╗╔╝║║──║╔╗║───║╔═╗║──║║──║║║║║║
//    ╔╝╚╗───║╚╝║╔═╝║║╚══╗───║║║║║║║║─║╚═╗║║║║───║╚═╝║──║║──║╚╝╚╝║
//    ╚══╝───╚══╝╚══╝╚═══╝───╚╝╚╝╚╝╚╝─╚══╝╚╝╚╝───╚═══╝──╚╝──╚═╝╚═╝


struct segment_tree{
    vi t;
    void _init_(int n1) {
        t.resize(4 * n1);
    }
    void build(vi& a, int p, int l, int r) {
        if (r - l == 1) {
            t[p] = a[l];
            return;
        }
        int m = (r + l) / 2;
        build(a, 2 * p + 1, l, m);
        build(a, 2 * p + 2, m, r);
        t[p] = t[2 * p + 1] + t[2 * p + 2];
    }
    void upd(int p, int l, int r, int idx, int x) {
        if (r - l == 1) {
            t[p] = x;
            return;
        }
        int m = (r + l) / 2;
        if (idx >= m) {
            upd(2 * p + 2, m, r, idx, x);
        } else {
            upd(2 * p + 1, l, m, idx, x);
        }
        t[p] = t[2 * p + 1] + t[2 * p + 2];
    }
    int get(int p, int l, int r, int lq, int rq) {
        if (l >= lq && r <= rq) {
            return t[p];
        }
        if (l >= rq || lq >= r) {
            return 0;
        }
        int m = (l + r) / 2;
        return get(2 * p + 1, l, m, lq, rq) + get(2 * p + 2, m, r, lq, rq);
    }
};
