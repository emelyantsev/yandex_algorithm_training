#include <iostream>
#include <cstdlib>
#include <cassert>
#include <memory>
#include <utility>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <unordered_set>


template<typename T>
class IList {

    public:

        virtual void set(size_t i, const T& val) = 0;
        virtual const T& get(size_t i) const = 0;
        virtual void add(const T& val) = 0;
        virtual std::shared_ptr<IList<T>> sublist(size_t from, size_t to) = 0;
};


template<typename T> 
class CListView;


template<typename T>
class CList : public IList<T> {

    public:

        CList( std::vector<T>&& items_) : items( items_ ) {}

        void set(size_t i, const T& val) override { items.at(i) = val;  }
        const T& get(size_t i) const override {  return items.at(i);   }
        virtual void add(const T& val) { items.push_back(val);  } 
        virtual std::shared_ptr<IList<T>> sublist(size_t from, size_t to) {  return std::make_shared<CListView<T>>(items, from, to) ;  }


    private:

        std::vector<T> items;
};


template<typename T> 
class CListView : public IList<T> {

    public:

        CListView( std::vector<T>& items_, size_t from_, size_t to_) : items( items_ ), from(from_) , to(to_)  {}

        void set(size_t i, const T& val) override { items.at( from + i ) = val;  }
        const T& get(size_t i) const override {  return items.at(from + i);   }
        virtual void add(const T& val) { assert(false ) ; } 
        virtual std::shared_ptr<IList<T>> sublist(size_t from_, size_t to_) {  return std::make_shared<CListView<T>>(items, from + from_, from + to) ; } 

    private:

        std::vector<T>& items;
        size_t from;
        size_t to;
};


class Interpreter {

    public:

        void Interpret(const std::string& code) {

            std::vector<std::string> codeSplited = split(code);
            parseAndCall(codeSplited);
        }

    private:

        void createNewList(const std::string& name, std::vector<int>&& nums) {

            assert(listMap.count(name) == 0);

            listMap[name] = std::make_shared< CList<int> >( std::move(nums) ) ; 
        }

        void createNewSublist(const std::string& src, const std::string& dest, size_t from, size_t to) {

            assert(listMap.count(src) == 1);
            assert(listMap.count(dest) == 0);

            listMap[ dest ] = listMap[src]->sublist(from, to) ; 
        }

        void setValue(const std::string& name, size_t ind, int val) {
            listMap.at(name)->set(ind, val);
        }

        void addValue(const std::string& name, int val) {
            listMap.at(name)->add( val );
        }

        void getValue( const std::string& name, size_t ind ) {

            int val = listMap.at(name)->get(ind);
            std::cout << val << std::endl;
        }

        void parseAndCall(const std::vector<std::string> & codeSplit) {
            
            if ( codeSplit[0] == "List") {

                const std::string& name = codeSplit[1];

                if ( codeSplit[2] == "new") {

                    std::vector<int> nums;

                    for (int i = 4; i < codeSplit.size(); ++i) {

                        nums.push_back( std::stoi( codeSplit[i] ) ) ;
                    }

                    createNewList(name, std::move(nums));
                }
                else {

                    const std::string& srcName = codeSplit[2];
                    int from = std::stoi( codeSplit[4] ) ;
                    int to = std::stoi( codeSplit[5] );

                    createNewSublist(srcName, name, from-1, to-1);
                }
            }
            else {

                const std::string& name = codeSplit[0];

                const std::string& memberFunc = codeSplit[1];

                if (memberFunc == "get") {

                    int ind = std::stoi(codeSplit[2]);

                    getValue(name, ind-1);
                }
                else if (memberFunc == "add") {

                    int val = std::stoi(codeSplit[2]);

                    addValue(name, val);
                }
                else if (memberFunc == "set") {

                    int ind = std::stoi(codeSplit[2]);
                    int val = std::stoi(codeSplit[3]);
                    setValue(name, ind-1, val);
                }
                else {
                    assert(false);
                }
            }
        }

        static std::vector<std::string> split(const std::string& line) {

            std::unordered_set<char> delims{' ', '(', ')', '=', '\t', '.', ','} ;

            std::vector<std::string> res;
            std::string curr;

            for (int i = 0; i < line.size(); ++i) {

                char c = line[i];

                if (delims.count(c)) {

                    if (!curr.empty()) {
                        res.push_back(std::move(curr));
                        curr.clear();
                    }                
                }
                else {
                    curr.push_back(c);
                }
            }

            return res;
        }


        std::unordered_map<std::string, std::shared_ptr<IList<int>> > listMap;

} ;






int main() {
    
    // {
    //     std::vector<int> v{2,3,5};
    //     auto a = std::make_shared<CList<int>>(std::move(v));
    //     auto b = a->sublist(1,2);
    //     int res = b->get(0);
    //     ++res;
    // }

    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);

    int n ;
    ss >> n;

    Interpreter interpeter;

    for (int i = 0; i < n; ++i) {

        std::getline(std::cin, line);
        interpeter.Interpret(line);
    }

    return EXIT_SUCCESS;
}