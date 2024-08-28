#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string currentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm tm;
    localtime_s(&tm, &in_time_t);
    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %X");
    return ss.str();
}

template <typename T>
class Log_Ptr {
public:
    explicit Log_Ptr(T* ptr) : ptr_(ptr) {
        logEvent("omistajuus siirretty", ptr_);
    }
    
    ~Log_Ptr() {
        logEvent("olio tuhottu", ptr_);
        delete ptr_;
    }
    
    Log_Ptr(const Log_Ptr&) = delete;
    
    Log_Ptr& operator=(const Log_Ptr&) = delete;
    
    T* get() const {
        return ptr_;
    }

private:
    T* ptr_;

    
    void logEvent(const std::string& event, T* ptr) {
        std::ofstream logFile("log_ptr.txt", std::ios_base::app);
        logFile << currentTimestamp() << " " << event << " " << ptr << std::endl;
    }
};