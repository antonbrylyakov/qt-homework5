#ifndef STOPWATCHSTORAGE_H
#define STOPWATCHSTORAGE_H

#include <QDateTime>
#include "stopwatchtime.h"

// Класс для хранения состояния секундомера с учетом паузы и текущего статуса
class StopWatchStorage
{
public:
    StopWatchStorage();
    StopWatchTime getElapsed(const QDateTime& currentTime);
    void start(const QDateTime& currentTime);
    void stop(const QDateTime& currentTime);
    void reset(const QDateTime& currentTime);
private:
    // Накопленное время в мс за предыдущие запуски
    qint64 m_storedTime = 0;
    // Время начала текущего запуска
    QDateTime m_startTime;
    bool m_started = false;
};

#endif // STOPWATCHSTORAGE_H
