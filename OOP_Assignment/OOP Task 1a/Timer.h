#pragma once

#include <chrono>

class Timer
{

public:
    void Start();
    float GetDuration() const;

private:
    std::chrono::time_point<std::chrono::steady_clock> m_StartTime;

};