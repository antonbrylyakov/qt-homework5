#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include "stopwatchtime.h"
#include "stopwatchstorage.h"

// Класс секундомера
class StopWatch : public QObject
{
    Q_OBJECT
public:
    explicit StopWatch(QObject *parent = nullptr);
    ~StopWatch();
    bool isStarted() const;

signals:
    void sig_Started();
    void sig_Stopped();
    void sig_TimeChanged(StopWatchTime time);
    void sig_CircleFinished(int circleNumber, StopWatchTime time);
    void sig_Reset();

public slots:
    void start();
    void stop();
    void circle();
    void reset();

protected slots:
    void timerTimeout();

protected:
    bool m_started = false;
    QTimer* m_timer;
    // Номер текущего круга
    int m_currentCircleNumber = 1;
    // Хранилище общего времени
    StopWatchStorage m_totalStorage;
    // Хранилище времени круга
    StopWatchStorage m_currentCircleStorage;
};

#endif // STOPWATCH_H
