#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

class Encoder {

    public:

        std::vector<unsigned char> Encode(const std::string& str) {

            words.clear();
            words_indexes.clear();
            words.push_back("");
            words_indexes[""] = 0;

            std::vector<unsigned char> result;

            std::string curr = "";

            for (char c : str) {
                
                if ( words_indexes.count(curr) == 1 && words_indexes.count( curr + c ) == 0 ) {
                    
                    int index = words_indexes[curr];

                    push_index( index, result);
                    result.push_back( c );

                    words.push_back( curr + c);
                    words_indexes[ curr + c ] = words.size() - 1;

                    curr.clear();
                }
                else {
                    curr += c;
                }
            }

            if (!curr.empty() ) {

                int index = words_indexes[curr];
                push_index( index, result);
            }



            return result;
        }

        void push_index(int index, std::vector<unsigned char>& result ) {

            if (words.size() < 256) {

                assert( index < 256 ) ;

                result.push_back(index) ;
            }
            else if (words.size() < 65536) {
                assert(  index < 65536  );

                result.push_back( index  );
                result.push_back( index >> 8 );
            }
            else {

                result.push_back( index  );
                result.push_back( index >> 8 );
                result.push_back( index >> 16 );
                result.push_back( index >> 24 );
            }
        }


         std::string Decode(const std::vector<unsigned char>& str) {

            words.clear();
            words_indexes.clear();
            words.push_back("");
            words_indexes[""] = 0;

            std::string result;

            int i = 0;

            while (true) {

                int index = pop_index(i, str);

                if (i != str.size()) {

                    std::string new_word = words[index] + (char) str[i];

                    result.append(new_word);

                    words.push_back(new_word);
                    words_indexes[new_word] = words.size() - 1;
                    ++i;

                    if (i == str.size() ) {
                        break;
                    }
                }
                else {

                    std::string new_word = words[index];
                    result.append(new_word);
                    break;
                }
            }

            return result;
         }

         int pop_index(int& i, const std::vector<unsigned char>& input ) {

            int index = 0;

            if (words.size() < 256) {

                assert( index < 256 ) ;

                index = input[i] ;
                i += 1;
                return index;
            }
            else if (words.size() < 65536) {
                
                index = input[i] | input[i + 1] << 8 ;
                i += 2;
                return index;
            }
            else {


                index = input[i] | input[i + 1] << 8 | input[i+2] << 16 | input[i+3] << 24;

                i += 4;
                return index;
            }
        }

    private:


        std::vector<std::string> words;
        std::unordered_map<std::string, int> words_indexes;

};


int main() {

    std::string command;
    std::cin >> command;

    if (command == "pack") {

        Encoder encoder;

        std::string input;
        std::cin >> input;

        auto res = encoder.Encode(input);

        std::cout << res.size() << std::endl;

        for (const auto& ri : res) {
            std::cout << (int) ri << " ";
        }
        std::cout << std::endl;

    }
    else {

        Encoder encoder;

        int n;

        std::cin >> n;

        std::vector<unsigned char> chars(n, 0);

        for (int i = 0; i < n; ++i) {

            int val;
            std::cin >> val;

            chars[i] = val;
        }

        auto res = encoder.Decode(chars);

        std::cout << res << std::endl;

    }

    return EXIT_SUCCESS;
}