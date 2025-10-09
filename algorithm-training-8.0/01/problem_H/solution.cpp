#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string_view>
#include <cassert>

int main() {

    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::string_view sv(s);

    std::unordered_map<std::string_view, std::vector<int> > chunk_to_index;

    int chunk_len = n / m;

    for (int i = 0; i < n; i += chunk_len) {

        std::string_view curr_chunk = sv.substr(i, chunk_len);
        chunk_to_index[curr_chunk] = {};
    }

    for (int i = 0; i < m; ++i) {

        std::string chunk;
        std::cin >> chunk;

        chunk_to_index[chunk].push_back(i+1);
    }

    std::vector<int> result;
    result.reserve(m);

    for (int i = 0; i < n; i += chunk_len) {

        std::string_view curr_chunk = sv.substr(i, chunk_len);

        assert(chunk_to_index.count(curr_chunk) == 1 && chunk_to_index[curr_chunk].size() > 0);

        result.push_back( chunk_to_index[curr_chunk].back() );
        chunk_to_index[curr_chunk].pop_back();

    }

    for (const int& item : result ) {

        std::cout << item << " ";
    }

    std::cout << std::endl;



    return 0;
}