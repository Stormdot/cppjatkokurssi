#include "main.h"

int main() {
    {
        Log_Ptr<int> logPtr(new int(42));
        std::cout << "Value: " << *logPtr.get() << std::endl;
    } 

    return 0;
}