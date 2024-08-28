#include "main.h"

int main() {
    {
        Log_Ptr<int> logPtr1(new int(42));
        Log_Ptr<int> logPtr2 = logPtr1;
        std::cout << "Value: " << *logPtr1 << std::endl;
        std::cout << "Value via operator->: " << *logPtr1.operator->() << std::endl;
    }

    return 0;
}