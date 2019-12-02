#ifndef TIMER_H_
#define TIMER_H_
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>

class timer{
public:
    timer(const std::string& str) : prgStr{str}, isTimeout{false},
        start(std::chrono::system_clock::now())
    {
    }
    timer()
    {
        timer("prag");
    }
    void out()
    {
        end = std::chrono::system_clock::now();
        std::cout << prgStr << ": " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
        isTimeout = true;
    }

    void print(std::stringstream& ss)
    {
        end = std::chrono::system_clock::now();
        ss << prgStr << ": " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    }
    void reset(const std::string& str)
    {
        this->out();
        prgStr = str;
        isTimeout = false;
        start = std::chrono::system_clock::now();
    }
    ~timer()
    {
       if(!isTimeout)
           out();
    }
private:
    std::string prgStr;
    bool isTimeout;
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
};

#endif
