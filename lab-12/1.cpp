#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#define rep(x, y, z) for (ll x = y; x < z; x++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define ll long long
#define pb push_back
#define f first
#define s second
 
const ll INF = 1e18;
 
int main() {
    ll n;
    std::cin >> n;
    std::vector<ll> g(n);
    rep(i, 0, n) {
        std::cin >> g[i];
    }
    std::vector<ll> d(n + 1, INF);
    d[0] = -INF;
    std::map<std::pair<ll, ll>, std::pair<ll, ll>> p;
    rep(i, 0, n) {
        ll j = (ll)(upper_bound(all(d), g[i]) - d.begin());
        if (d[j - 1] < g[i] && g[i] < d[j]) {
            d[j] = g[i];
            p[{g[i], j}] = {d[j - 1], j - 1};
        }
    }
    ll mx = -1, ch;
    for (auto e : p) {
        if (e.f.s > mx) {
            mx = e.f.s;
            ch = e.f.f;
        }
    }
    std::vector<ll> way;
    std::pair<ll, ll> w = {ch, mx};
    while(true) {
        way.pb(w.f);
        w = p[w];
        if (w.f == -INF) {
            break;
        }
    }
    reverse(all(way));
    std::cout << sz(way) << std::endl;
    for (auto e : way) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return 0;
}
