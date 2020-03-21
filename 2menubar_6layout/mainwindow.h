#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_bt_show_clicked();

    void on_bt_hide_clicked();

private:
    Ui::MainWindow *ui;

    void wg_result_show();
    void wg_result_hide();
    bool m_wg_result_value = false;
};
#endif // MAINWINDOW_H
