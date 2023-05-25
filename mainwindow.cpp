#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_stopWatch = new StopWatch(this);

    connect(m_stopWatch, &StopWatch::sig_Started, [this]()
    {
        ui->pb_Start->setText("Стоп");
        ui->pb_Circle->setEnabled(true);
    });

    connect(m_stopWatch, &StopWatch::sig_Stopped, [this]()
    {
        ui->pb_Start->setText("Старт");
        ui->pb_Circle->setEnabled(false);
    });

    connect(m_stopWatch, &StopWatch::sig_TimeChanged, [this](StopWatchTime time)
    {
        ui->lb_Time->setText(time.toString());
    });

    connect(m_stopWatch, &StopWatch::sig_Reset, [this]()
    {
        ui->te_Circles->clear();
    });

    connect(m_stopWatch, &StopWatch::sig_CircleFinished, [this](int circleNum, StopWatchTime time)
    {
       auto str = QString("Круг %1, Время: %2").arg(circleNum).arg(time.toString());
       ui->te_Circles->append(str);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_Start_clicked()
{
    if (m_stopWatch->isStarted())
    {
        m_stopWatch->stop();
    }
    else
    {
        m_stopWatch->start();
    }
}


void MainWindow::on_pb_Circle_clicked()
{
    m_stopWatch->circle();
}


void MainWindow::on_pb_Reset_clicked()
{
    m_stopWatch->reset();
}

