#include "StopWatch.h"

StopWatch::StopWatch(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &StopWatch::timerTimeout);
}

StopWatch::~StopWatch()
{

}

bool StopWatch::isStarted() const
{
    return m_started;
}

void StopWatch::start()
{
    // таймаут таймера
    static const int TIMEOUT = 10;

    if (m_started)
    {
        return;
    }

    m_started = true;
    auto currentTime = QDateTime::currentDateTime();
    m_totalStorage.start(currentTime);
    m_currentCircleStorage.start(currentTime);
    m_timer->start(TIMEOUT);
}

void StopWatch::stop()
{
    if (!m_started)
    {
        return;
    }

    m_started = false;
    m_timer->stop();
    auto currentTime = QDateTime::currentDateTime();
    m_totalStorage.stop(currentTime);
    m_currentCircleStorage.stop(currentTime);
    timerTimeout();
}

void StopWatch::circle()
{
    if (!m_started)
    {
        return;
    }

    auto currentTime = QDateTime::currentDateTime();
    auto circleTime = m_currentCircleStorage.getElapsed(currentTime);
    m_currentCircleStorage.reset(currentTime);
    emit sig_CircleFinished(m_currentCircleNumber++, circleTime);
}

void StopWatch::reset()
{
    m_currentCircleNumber = 1;
    auto currentTime = QDateTime::currentDateTime();
    m_totalStorage.reset(currentTime);
    m_currentCircleStorage.reset(currentTime);
    timerTimeout();
}

void StopWatch::timerTimeout()
{
    auto currentTime = QDateTime::currentDateTime();
    auto elapsed = m_totalStorage.getElapsed(currentTime);
    emit sig_TimeChanged(elapsed);
}
