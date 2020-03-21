#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置图标
    setWindowIcon(QIcon(":/res/app_1title_dark_appicon.png"));

    //设置窗口标题
    setWindowTitle(tr("C语言编译器"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

