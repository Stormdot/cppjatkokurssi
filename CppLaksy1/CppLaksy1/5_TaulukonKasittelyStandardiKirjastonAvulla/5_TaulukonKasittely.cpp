#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <numeric>

using namespace std;

//Tehtävä tehty jdoodlen online c++17 compilerilla, joten suorituskyvyn vertailu on vaikeaa.
int main() {
    const size_t N = 1000000; 
    std::vector<int> vec(N);
    
    std::iota(vec.begin(), vec.end(), 0);
    std::for_each(std::execution::seq, vec.begin(), vec.end(), [](int& n) { n += 1; });
    std::for_each(std::execution::par, vec.begin(), vec.end(), [](int& n) { n += 1; });
    std::for_each(std::execution::par_unseq, vec.begin(), vec.end(), [](int& n) { n += 1; });


    for (size_t i = 0; i < 10; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}