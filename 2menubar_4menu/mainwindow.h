#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QDialog *mian_menu_qd_analysebystep;
    bool eventFilter(QObject *target, QEvent *e);


private:
    Ui::MainWindow *ui;

    void btClick();

    QMenu* file_menu;
    QMenuBar* menuBar;
};
#endif // MAINWINDOW_H
