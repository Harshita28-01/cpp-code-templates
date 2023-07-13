#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int mn = v[i], mx = v[i];
            for (int j = i; j <= min(n - 1, i + 900); j++)
            {
                mn = min(mn, v[j]);
                mx = max(mx, v[j]);
                if (mn == 0)
                {
                    long long cnt = n - j;
                    ans += cnt;
                    break;
                }
                int pro = mn * mx;
                int len = (j - i + 1);
                if (pro % len == 0)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
