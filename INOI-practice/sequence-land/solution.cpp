#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<unordered_set<int> > a;
    vector<bool> used(n);

    int p, e;
    for (int i = 0; i < n; i++) {
        cin >> p; 
        unordered_set<int> id;
        for (int j = 0; j < p; j++) {
            cin >> e;
            id.insert(e);
        }
        a.push_back(id);
    }

    queue<int> q; 
    q.push(0);
    unordered_set<int> ans;
    ans.insert(0);

    // int ans = 1;
    while (!q.empty()) {
        int m = q.front();
        q.pop();

        if (used[m]) continue;
        used[m] = true;

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            int cnt = 0;
            for (auto j : a[m]) {
                if (a[i].find(j) != a[i].end()) {
                    cnt++;
                }
            }
            if (cnt >= k) {
                // ans++;
                ans.insert(i);
                q.push(i);
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}