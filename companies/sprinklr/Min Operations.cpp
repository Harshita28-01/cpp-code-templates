#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<int, int>
#define debug(x) 0

// 1 indexing
struct LCA
{
    ll LOG, n;
    vector<vector<pll>> adj;
    vector<vector<ll>> btree;
    vector<ll> depth;

    LCA(ll _n, vector<vector<pll>> &_adj) // no of nodes
    {
        n = _n;
        LOG = log2(n) + 1;
        btree.resize(n + 1, vector<ll>(LOG));
        adj = _adj;
        depth.resize(n + 1, 0);
    }

    void make_tree(ll a, ll prv = -1)
    {
        for (auto [b, w] : adj[a])
        {
            if (b == prv)
                continue;

            depth[b] = depth[a] + 1;
            btree[b][0] = a; // a is parent of b
            for (int j = 1; j < LOG; j++)
                btree[b][j] = btree[btree[b][j - 1]][j - 1];
            make_tree(b, a);
        }
    }

    ll find_lca(ll u, ll v)
    {
        if (depth[u] < depth[v])
            swap(u, v);
        int k = depth[u] - depth[v];
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (k & (1 << i))
                u = btree[u][i];
        }
        if (u == v)
            return u;
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (btree[u][i] != btree[v][i])
            {
                u = btree[u][i];
                v = btree[v][i];
            }
        }
        return btree[u][0];
    }
};

void get_sum(int curr, int prv, vector<int> &ans, vector<vector<pll>> &adj, vector<vector<ll>> &psum)
{
    psum[curr] = ans;
    for (auto const [x, w] : adj[curr])
    {
        if (x == prv)
            continue;
        ans[w]++;
        get_sum(x, curr, ans, adj, psum);
        ans[w]--;
    }
}

vector<int> solve(int n, vector<vector<pll>> &adj, int q, vector<vector<int>> &queries)
{

    vector<vector<ll>> psum(n + 1, vector<ll>(27, 0));
    LCA lc(n, adj);
    lc.make_tree(1);

    vector<ll> f_arr(27, 0);
    get_sum(1, 0, f_arr, adj, psum);

    debug(psum[1]);

    vector<int> res;
    res.reserve(q);
    for (int qq = 0; qq < q; qq++)
    {
        int a = queries[qq][0];
        int b = queries[qq][1];

        int par = lc.find_lca(a, b), tot = 0, cnt = 0, val = 0;
        fill(f_arr.begin(), f_arr.end(), 0);

        for (int i = 0; i < 27; i++)
        {
            f_arr[i] += (psum[a][i] + psum[b][i]) - 2 * psum[par][i];
            tot += f_arr[i];
        }
        cnt = (tot + 1) / 2;
        tot = 0;
        for (int i = 0; i < 27; i++)
        {
            tot += f_arr[i];
            if (tot >= cnt)
            {
                cnt = i;
                break;
            }
        }
        int ans = 0;

        for (int i = 0; i < 27; i++)
        {
            ans += f_arr[i] * abs(i - cnt);
        }
        res.push_back(ans);
    }
    return res;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> edges(n - 1, vector<int>(3));
    for (int i_edges = 0; i_edges < n - 1; i_edges++)
    {
        for (int j_edges = 0; j_edges < 3; j_edges++)
        {
            cin >> edges[i_edges][j_edges];
        }
    }

    vector<vector<pll>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int Q;
    cin >> Q;
    vector<vector<int>> Queries(Q, vector<int>(2));
    for (int i_Queries = 0; i_Queries < Q; i_Queries++)
    {
        for (int j_Queries = 0; j_Queries < 2; j_Queries++)
        {
            cin >> Queries[i_Queries][j_Queries];
        }
    }

    vector<int> out_;
    out_ = solve(n, adj, Q, Queries);
    cout << out_[0];
    for (int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
        cout << " " << out_[i_out_];
    }
}
