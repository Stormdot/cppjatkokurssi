#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <mutex>

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
    explicit Log_Ptr(T* ptr) 
        : ptr_(ptr), count_(new int(1)), mtx_(std::make_shared<std::mutex>()) {
        logEvent("omistajuus siirretty", ptr_);
    }

    ~Log_Ptr() {
        std::lock_guard<std::mutex> lock(*mtx_);
        if (--(*count_) == 0) {
            logEvent("olio tuhottu", ptr_);
            delete ptr_;
            delete count_;
        }
    }

    Log_Ptr(const Log_Ptr& other) 
        : ptr_(other.ptr_), count_(other.count_), mtx_(other.mtx_) {
        std::lock_guard<std::mutex> lock(*mtx_);
        ++(*count_);
        logEvent("kopioitu", ptr_);
    }

    Log_Ptr& operator=(const Log_Ptr& other) {
        if (this != &other) {
            std::lock_guard<std::mutex> lock(*mtx_);
            if (--(*count_) == 0) {
                logEvent("olio tuhottu", ptr_);
                delete ptr_;
                delete count_;
            }
            ptr_ = other.ptr_;
            count_ = other.count_;
            mtx_ = other.mtx_;
            ++(*count_);
            logEvent("sijoitettu", ptr_);
        }
        return *this;
    }

    T* get() const {
        return ptr_;
    }

    T* operator->() {
        logEvent("operator->", ptr_);
        return ptr_;
    }

    T& operator*() {
        logEvent("operator*", ptr_);
        return *ptr_;
    }

private:
    T* ptr_;
    int* count_;
    std::shared_ptr<std::mutex> mtx_;

    void logEvent(const std::string& event, T* ptr) {
        std::ofstream logFile("log_ptr.txt", std::ios_base::app);
        logFile << currentTimestamp() << " " << event << " " << ptr << std::endl;
    }
};