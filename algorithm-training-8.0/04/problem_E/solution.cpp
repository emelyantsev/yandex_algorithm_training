#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> events;
    
    for (int i = 0; i < n; i++) {
        events.push_back({i, 1});
    }
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({l - 1, 0});
        events.push_back({r, -1});
    }
    
    sort(events.begin(), events.end());
    
    int cur_buses = 0;
    vector<pair<int, int>> bus_counts;
    
    for (const auto& e : events) {
        int pos = e.first;
        int type = e.second;
        
        if (type == -1) {
            cur_buses--;
        } else if (type == 0) {
            cur_buses++;
        } else {
            bus_counts.push_back({cur_buses, pos});
        }
    }
    
    sort(bus_counts.begin(), bus_counts.end(), 
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.first > b.first;
         });
    
    for (auto& item : bus_counts) {
        if (k == 0) break;
        
        int buses = item.first;
        int ind = item.second;
        
        int ki = min(k, (long long) a[ind]);
        a[ind] -= ki;
        k -= ki;
    }
    
    long long res = 0;

    for (const auto& item : bus_counts) {
        int buses = item.first;
        int ind = item.second;
        res += (long long) buses * a[ind];
    }
    
    cout << res << endl;
    
    return 0;
}