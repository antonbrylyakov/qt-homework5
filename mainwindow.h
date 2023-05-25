#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_Start_clicked();

    void on_pb_Circle_clicked();

    void on_pb_Reset_clicked();

private:
    Ui::MainWindow *ui;
    StopWatch* m_stopWatch;

};
#endif // MAINWINDOW_H
