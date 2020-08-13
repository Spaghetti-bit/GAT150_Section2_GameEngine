#include "pch.h"
#include "Timer.h"


namespace nc
{
    void Timer::Reset()
    {
        m_timePoint = clock::now();
    }

    Timer::clock::rep Timer::ElaspedTicks()
    {
        Timer::clock::duration duration = (Timer::clock::now() - m_timePoint);

        return duration.count();
    }

    Timer::clock::rep Timer::TicksPerSecond()
    {
        return clock_duration::period::den;
    }

    double Timer::ElaspedSeconds()
    {
        return ElaspedTicks() / static_cast<double>(TicksPerSecond());
    }

    //Frame Timer

    void FrameTimer::Tick()
    {
        m_dt = static_cast<float>(ElaspedSeconds());
        m_timePoint = clock::now();

    }

    

}
