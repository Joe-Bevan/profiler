#pragma once
#include <cstdio>
#include <chrono>

enum Format {
    Second,
    Milli,
    Micro
};

// A simple scope-based timer, starts when object is created and stops when deleted.
class Profiler
{
public:
    Profiler(const char *Name = "unnamed timer", Format format = Format::Milli)
        : mName{Name}, mFormat{format}, mStart{std::chrono::high_resolution_clock::now()} {}

    ~Profiler() { PrintElapsedTime(); }

    int64_t GetElapsedTime()
    {
        mEnd = std::chrono::high_resolution_clock::now();
        
        switch (mFormat)
        {
        case Format::Second:
            return std::chrono::duration_cast<std::chrono::seconds>(mEnd - mStart).count();
            break;

        case Format::Milli:
            return std::chrono::duration_cast<std::chrono::milliseconds>(mEnd - mStart).count();
            break;

        case Format::Micro:
            return std::chrono::duration_cast<std::chrono::microseconds>(mEnd - mStart).count();
            break;

        default:
            return -1;
            break;
        }
    }

    void PrintElapsedTime()
    {
        switch (mFormat)
        {
        case Format::Second:
            printf("[%s] elapsed time: %li s\n", mName, GetElapsedTime());
            break;

        case Format::Milli:
            printf("[%s] elapsed time: %li ms\n", mName, GetElapsedTime());
            break;

        case Format::Micro:
            printf("[%s] elapsed time: %li us\n", mName, GetElapsedTime());
            break;
        }
    }

private:
    const char *mName;
    Format mFormat;
    std::chrono::high_resolution_clock::time_point mStart;
    std::chrono::high_resolution_clock::time_point mEnd;
};
