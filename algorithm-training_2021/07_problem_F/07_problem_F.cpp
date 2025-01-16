#include <iostream>
#include <chrono>
#include <unordered_set>
#include <tuple>

using std::chrono::year;
using std::chrono::month;
using std::chrono::day;
using std::chrono::year_month_day;

struct Event {

    year_month_day date;
    int type;
    int id;

    friend bool operator<(const Event& l, const Event& r) {

        return std::tie(l.date, l.type, l.id) < std::tie(r.date, r.type, r.id);
    }
};


int main()
{
    
    int N;
    std::cin >> N;

    std::vector<Event> events;
    events.reserve(2 * N);

    for (int i = 0; i < N; ++i) {

        int d, m, y;
        std::cin >> d >> m >> y;

        year_month_day birth18;

        if (y == 29 && m == 2) {
            birth18 = year_month_day( year(y + 18), month(3), day(1) );
        }
        else {
            birth18 = year_month_day( year(y + 18), month(m), day(d) );
        }
        
        year_month_day birth80;

        if (y == 29 && m == 2 && !year(y + 80).is_leap() ) {

            birth80 = year_month_day( year(y + 80), month(3), day(1) );
        }
        else {

            birth80 = year_month_day( year(y + 80), month(m), day(d) ) ;
        }


        std::cin >> d >> m >> y;

        year_month_day death{ year(y), month(m), day(d) };

        if (death <= birth18) {
            continue;
        }

        year_month_day from = birth18;
        year_month_day to = std::min(death, birth80);

        events.push_back({ to, -1, i });
        events.push_back({ from, 1, i });

    }

    if (events.size() == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }


    std::sort( events.begin(), events.end() );

    std::vector< std::unordered_set<int> > sets;

    std::unordered_set<int> current_set;
    current_set.insert(events[0].id);

    bool prev_is_greater = true;

    for (int i = 1; i < events.size(); ++i) {

        if (events[i].type == -1) {

            if (prev_is_greater) {
                sets.push_back(current_set);
            }

            current_set.erase(events[i].id);
            prev_is_greater = false;
        }
        else {
            current_set.insert( events[i].id );
            prev_is_greater = true;
        }
    }

    if (sets.size() == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (const auto& set : sets) {

        for (const int id : set) {
            std::cout << id+1 << " ";
        }
        std::cout << std::endl;

    }

    return 0;
}

