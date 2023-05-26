#ifndef STOPWATCHTIME_H
#define STOPWATCHTIME_H

#include <Qt>
#include <QString>

// Класс для хранения времени секундомера
// Класс QTaimeStamp, как я понял, еще не реализован
class StopWatchTime
{
public:
    StopWatchTime();
    StopWatchTime(qint64 milliseconds);
    unsigned char hours() const;
    unsigned char minutes() const;
    unsigned char seconds() const;
    // Десятые доли секунды
    unsigned char tenths() const;
    QString toString() const;

private:
    unsigned char m_hours = 0;
    unsigned char m_minutes = 0;
    unsigned char m_seconds = 0;
    unsigned char m_tenths = 0;
};

#endif // STOPWATCHTIME_H
