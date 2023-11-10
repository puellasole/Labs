#include "lab8/Stack.hpp"

int main() {
    try
    {
        st::Stack<int> s(3);
        s.push(4);
        s.push(7);
        s.push(8);
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    }

    catch (const std::out_of_range& error)
    {
        std::cerr << "You cannot delete elements because of " << error.what() << std::endl;
    }
    catch (const std::logic_error& error)
    {
        std::cerr << "You cannot refer to the top element because of " << error.what() << std::endl;
    }
}
