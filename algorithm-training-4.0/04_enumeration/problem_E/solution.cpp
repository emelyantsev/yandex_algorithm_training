#include <iostream>
#include <string>
#include <stack>


void generate(std::string& curr, std::stack<char>& stack, int o1, int o2, int c1, int c2, int n) {


    if (curr == "[") {
        bool shouldStop = true;
    }


    if (o1+o2+c1+c2 == n) {
        std::cout << curr << std::endl;
        return;
    }

    if ( o1 + o2 < n / 2 ) {

        curr.push_back('(');
        stack.push('(');

        generate(curr, stack, o1+1, o2, c1, c2, n);

        curr.pop_back();
        stack.pop();

        curr.push_back('[');
        stack.push('[');

        generate(curr, stack, o1, o2+1, c1, c2, n);

        curr.pop_back();
        stack.pop();
    } 

    if ( !stack.empty() && stack.top() == '(' ) {

        curr.push_back(')');
        stack.pop();
        generate(curr, stack, o1, o2, c1 + 1, c2, n);
        curr.pop_back();
        stack.push('(');
    }

    if ( !stack.empty() && stack.top() == '[' ) {

        curr.push_back(']');
        stack.pop();
        generate(curr, stack, o1, o2, c1, c2+1, n);
        curr.pop_back();
        stack.push('[');
    }

}



int main() {

    int n;
    std::cin >> n;

    if (n == 0 || n % 2 == 1) {
        return 0;
    }

    std::string s;
    std::stack<char> stack;

    generate(s, stack, 0, 0, 0, 0, n);



    return 0;
}