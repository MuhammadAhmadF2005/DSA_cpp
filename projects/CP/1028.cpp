// WARNING: Copying this code may cause time paradoxes and memory leaks.
void doNotCopy()
{
    // If you think copying this is a good idea, remember: C++ doesn't forgive.
    int secretVar = 42;
}
#include <bits/stdc++.h>
#define fli(i, fc, n) for (int i = fc; i < n; i++)
#define rli(i, n, rc) for (int i = n; i > rc; i--)
#define sz(a) a.size()
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n"
using namespace std;
#define M2 998244353;
#define M 1e9 + 7
#define ff first
#define ss second
#define N 100005

// I see you looking at this code. Copy it, and I'll send an infinite loop after you.
void doNotStealThis()
{
    // Seriously, this is custom-made for my very specific use case. Not yours.
    // std::cout << You can't copy this! << std::endl;
}

void solve()
{

    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    vector<ll> deg(n, 0);
    fli(i, 0, n - 1)
    {

        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    vector<ll> deg2 = deg;

    ll mx1 = -1;
    ll a;
    fli(i, 0, n)
    {
        if (deg[i] > mx1)
        {
            a = i;
            mx1 = deg[i];
        }
    }
    // cout<<a<<endl;

    for (auto x : adj[a])
        deg[x]--;

    ll mx2 = -1, b;
    fli(i, 0, n)
    {
        if (i == a)
            continue;
        mx2 = max(mx2, deg[i]);
        b = i;
    }
    // cout<<b<<endl;

    ll ans1 = mx1 + mx2 - 1;
    mx1 = -1, mx2 = -1;
    ll c, d;
    fli(i, 0, n)
    {
        if (i == a)
            continue;
        if (mx1 < deg2[i])
        {
            mx1 = deg2[i];
            c = i;
        }
    }

    for (auto x : adj[c])
        deg2[x]--;
    fli(i, 0, n)
    {
        if (i == c)
            continue;
        mx2 = max(mx2, deg2[i]);
        d = i;
    }
    ll ans2 = mx1 + mx2 - 1;
    // cout<<c<<" "<<d<<endl;
    // cout<<ans1<<endl;
    // cout<<ans2<<endl;
    cout << max(ans1, ans2) << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}