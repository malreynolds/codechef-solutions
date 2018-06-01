#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Citizen {
    int i, j;
};

bool cmp(const Citizen c1, const Citizen c2) {
    return c1.j > c2.j;
}

int main() {
    int n;
    cin >> n;

    vector<Citizen> a(n);
    int x, y, z;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        a[i].i = x; a[i].j = y + z;
    }

    sort(a.begin(), a.end(), cmp);

    int agg = 0, ans = 0, cur = 0;
    for (auto c: a) {
        agg += c.i;
        cur = agg + c.j;
        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}