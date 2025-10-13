#include <iostream>
#include <tuple>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <iomanip>

struct Segment {

    double b;
    double e;
    double w;

    friend bool operator<(const Segment& l, const Segment& r)
    {
        return std::tie(l.e, l.b, l.w) < std::tie(r.e, r.b, r.w); 
    }
};


int main() {

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<Segment> segments;
    segments.reserve(n);

    for (int i = 0; i < n; ++i) {

        Segment seg;
        std::cin >> seg.b >> seg.e >> seg.w ;
        segments.push_back(seg);
    }

    std::sort(segments.begin(), segments.end() ) ;

    std::map<double, double> dp;

    for (const Segment& seg : segments) {

        if (dp.empty()) {
            dp[seg.e] = seg.w;
            continue;
        }

        auto it_last = std::prev( dp.end() ) ;
        assert( it_last->first <= seg.e );
        double last_w = it_last->second;

        auto it = dp.upper_bound(seg.b);

        if ( it == dp.begin() ) {

            if (seg.w > last_w) {
                dp[seg.e] = seg.w;
            }            
        }
        else {

            auto prev_it = std::prev(it);
            assert( prev_it->first <= seg.b );
            double prev_w = prev_it->second;

            if (seg.w + prev_w > last_w) {
                dp[seg.e] = seg.w + prev_w;
            }    
        }
    }

    auto last_it = std::prev( dp.end() ) ;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << last_it->second << std::endl;

    return 0;
}