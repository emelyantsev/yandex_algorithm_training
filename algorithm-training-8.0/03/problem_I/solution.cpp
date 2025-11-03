#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <cassert>
#include <memory>
#include <utility>
#include <tuple>
#include <algorithm>

const std::unordered_map<char, int>  op_priorities = {
        {'+', 1}, 
        {'-', 1}, 
        {'*', 2}, 
        {'/', 2}, 
        {'^', 3}
    };

const std::unordered_map<char, bool>  right_associative = {
        {'+', false}, 
        {'-', false}, 
        {'*', false}, 
        {'/', false}, 
        {'^', true}
    };

struct Node {

    char val;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};


class Parser {

    public:

        std::vector<char> toRpn(const std::string& expression) {

            std::stack<char> stack;
            std::vector<char> result;

            for (char c : expression) {

                if (c == '(') {
                    stack.push(c);
                }
                else if ( c == ')' ) {
                    
                    while (stack.top() != '(' ) {
                        result.push_back( stack.top() ) ;
                        stack.pop();
                    }

                    stack.pop();
                }
                else if ( isalpha(c) ) {

                    result.push_back(c);
                }
                else {
                    
                    assert( op_priorities.count(c) == 1 && right_associative.count(c) == 1 );

                    if (right_associative.at(c) == true) {

                        while (!stack.empty() && stack.top() != '(' && op_priorities.at(c) < op_priorities.at(stack.top() )  ) {
                            result.push_back(stack.top());
                            stack.pop();
                        }
                    }
                    else {

                        while (!stack.empty() && stack.top() != '(' && op_priorities.at(c) <= op_priorities.at(stack.top() )  ) {
                            result.push_back(stack.top());
                            stack.pop();
                        }
                    }

                    stack.push(c);
                }
            }

            while ( !stack.empty() ) {
                result.push_back(stack.top());
                stack.pop();

            } 

            return result;
        }


        std::unique_ptr<Node> buildTree(const std::vector<char> rpn) {

            std::stack<std::unique_ptr<Node> > stack;

            for (char c : rpn) {

                if (isalpha(c)) {

                    stack.push( std::make_unique<Node>(c, nullptr, nullptr) );
                }
                else {

                    assert( stack.size() >= 2 );

                    std::unique_ptr<Node> right = std::move( stack.top() );
                    stack.pop();
                    std::unique_ptr<Node> left = std::move( stack.top() );
                    stack.pop();
                    stack.push(  std::make_unique<Node>(c, std::move(left), std::move(right) ) )  ;
                }
            }

            assert( stack.size() == 1) ;
            return std::move(stack.top()) ;

        }

        void PrintTree(const Node* root) {

            auto print_data = print(root);
            std::vector<std::string>& lines = std::get<1>(print_data);

            for (auto& line : lines) {
                std::cout << line << std::endl;
            }
        }

        std::tuple<int, std::vector<std::string> > print(const Node* node) {

            if ( isalpha( node->val) ) {

                return std::make_tuple( 0, std::vector<std::string>{ std::string(1, node->val)  }  ) ;
            }

            auto left_data = print(node->left.get());

            int lc = std::get<0>(left_data);
            std::vector<std::string>& l_lines = std::get<1>(left_data);
            int lh = l_lines.size();
            int lw = l_lines[0].size();


            auto right_data = print(node->right.get());

            int rc = std::get<0>(right_data);
            std::vector<std::string>& r_lines = std::get<1>(right_data);
            int rh = r_lines.size();
            int rw = r_lines[0].size();

            int total_width = rw + rw + 5;

            std::string l1 = std::string(lc-0, ' ') + "." + std::string(lw-lc-1, '-') +
                + "-[" + std::string(1, node->val) + "]-" +  std::string(rc-0, '-') + "." + std::string(rw-rc-1, ' ');


            std::string l2 = std::string(lc-0, ' ') + "|" + std::string(lw-lc-1 + 5 + rc, ' ') + "|" + std::string(rw-rc-1, ' ');
            int mid = lw + 2;

            std::vector<std::string> lines;
            lines.push_back(std::move(l1));
            lines.push_back(std::move(l2));

            int mh = std::max(lh, rh);

            for (int i = 0 ; i < mh; ++i) {

                std::string cur_line;

                if (i >= lh ) {

                    cur_line += std::string(lw, ' ');
                }
                else {
                    cur_line += l_lines[i];
                }

                cur_line += std::string( 5, ' ');

                if (i >= rh ) {

                    cur_line += std::string(rw, ' ');
                }
                else {
                    cur_line += r_lines[i];
                }

                lines.push_back(std::move(cur_line));
            }
            
            return std::make_tuple(mid, std::move(lines));
        }
        

    private:


};



int main() {

    //std::string expression = "(a+b+c)*(d-a/x^b^(c+k))";
    //std::string expression = "(a+b+c)*(d-a)";
    //std::string expression = "(a+b)";
    //std::string expression = "a";


    std::string expression ;
    std::cin >> expression ;

    Parser parser;

    auto res = parser.toRpn(expression);
    auto tree = parser.buildTree(res);

    parser.PrintTree( tree.get() );

    return 0;
}