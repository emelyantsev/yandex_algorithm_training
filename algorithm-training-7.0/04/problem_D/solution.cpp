#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <iterator>
#include <utility>
#include <cassert>
#include <sstream>

class WindowManager {

    public:

        void Run(const std::string& name) {

            programs.push_back(name);
        }

        std::string GetActiveProgram() const {
            return programs.back();
        }

        void ProcessAlt(int n ) {

            n = n % programs.size();

            if (n == 0) {
                return;
            }

            auto it = programs.end();

            std::advance( it, -n - 1);
            std::string val = std::move(*it);
            programs.erase(it);
            programs.push_back(std::move(val));
        }

    private:

        std::list<std::string> programs;
};


int main() {

    std::string line;
    std::getline(std::cin, line);

    std::istringstream input(line);

    int n;
    input >> n;

    WindowManager manager;

    for (int i = 0; i < n; ++i) {

        std::getline(std::cin, line);

        if (line.substr(0, 3) == "Run") {

            manager.Run( line.size() > 3 ? line.substr(4) : "");
        }
        else if (line.substr(0, 3) == "Alt") {

            int tab_count = ( line.size() - 3 ) / 4;
            assert( ( line.size() - 3 ) % 4 == 0 ) ;

            manager.ProcessAlt(tab_count);
        }

        std::cout << manager.GetActiveProgram() << std::endl;
    }

    return EXIT_SUCCESS;
}