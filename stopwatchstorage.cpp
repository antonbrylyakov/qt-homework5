#include "stopwatchstorage.h"

StopWatchStorage::StopWatchStorage()
{

}

StopWatchTime StopWatchStorage::getElapsed(const QDateTime &currentTime)
{
    auto totalElapsed = m_storedTime + (m_started ? m_startTime.msecsTo(currentTime) : 0);
    return StopWatchTime(totalElapsed);
}

void StopWatchStorage::start(const QDateTime &currentTime)
{
    if (!m_started)
    {
        m_startTime = currentTime;
        m_started = true;
    }
}

void StopWatchStorage::stop(const QDateTime &currentTime)
{
    if (m_started)
    {
        auto elapsed = m_startTime.msecsTo(currentTime);
        m_storedTime += elapsed;
        m_started = false;
    }
}

void StopWatchStorage::reset(const QDateTime &currentTime)
{
    m_startTime = currentTime;
    m_storedTime = 0;
}
