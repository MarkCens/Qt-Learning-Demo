#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//Qt库头文件
#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QScrollBar>

//qsciscintilla编辑器库头文件
#include "Qsci/qsciscintilla.h"
#include "Qsci/qscilexercpp.h"
#include "Qsci/qsciapis.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //声明加载窗口UI函数
    void loadWindowUI();
    void loadTitlebar();
    void loadMenubar();
    void loadMainPanel();
    void loadResultbar();
    void loadStatusbar();

    //声明全局变量

    QsciScintilla *main_editor; //编辑器类

};
#endif // MAINWINDOW_H
