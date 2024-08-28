#include "main.h"

int main() {
    {
        Log_Ptr<int> logPtr(new int(42));
        std::cout << "Value: " << *logPtr << std::endl;
        std::cout << "Value via operator->: " << *logPtr.operator->() << std::endl;
    }

    return 0;
}