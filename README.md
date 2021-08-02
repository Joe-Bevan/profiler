# C++ profiler
A single header scoped-based C++ timer class for profiling function execution times.

## Examples
```cpp
void Foo() { ... }

void Bar() 
{
    {
        Profiler p{"Foo() timer"};
        Foo();
    }
}
```
Output:
[Foo() timer] elapsed time: 2029 ms

The elapsed time can be retrieved at any point by calling
`GetElapsedTime()` on a valid profiler. Calling this function does not reset the timer.

## Optional
The profiler time format can be changed to seconds, milliseconds, or microseconds. By default it is set to milliseconds.
```cpp
void Foo() { ... }

void Bar() 
{
    {
        Profiler p{"Foo() timer", Format::Micro};
        Foo();
    }
}
```
Output:
[Foo() timer] elapsed time: 2029064 us