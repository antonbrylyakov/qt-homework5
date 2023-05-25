#include "stopwatchtime.h"

StopWatchTime::StopWatchTime()
{

}

StopWatchTime::StopWatchTime(qint64 milliseconds)
{
    static const int MSECS_IN_TENTH = 100;
    static const int MSECS_IN_SEC = 1000;
    static const int MSECS_IN_MIN = MSECS_IN_SEC * 60;
    static const int MSECS_IN_HOUR = MSECS_IN_MIN * 60;

    m_hours = static_cast<unsigned char>(milliseconds / MSECS_IN_HOUR);
    m_minutes = static_cast<unsigned char>((milliseconds % MSECS_IN_HOUR) / MSECS_IN_MIN);
    m_seconds = static_cast<unsigned char>((milliseconds % MSECS_IN_MIN) / MSECS_IN_SEC);
    m_tenths = static_cast<unsigned char>((milliseconds % MSECS_IN_SEC) / MSECS_IN_TENTH);
}

unsigned char StopWatchTime::hours() const
{
    return m_hours;
}

unsigned char StopWatchTime::minutes() const
{
    return m_minutes;
}

unsigned char StopWatchTime::seconds() const
{
    return m_seconds;
}

unsigned char StopWatchTime::tenths() const
{
    return m_tenths;
}

QString StopWatchTime::toString() const
{
    return QString("%1:%2:%3.%4").arg(m_hours, 2, 10, QChar('0')).arg(m_minutes, 2, 10, QChar('0')).arg(m_seconds, 2, 10, QChar('0')).arg(m_tenths);
}
