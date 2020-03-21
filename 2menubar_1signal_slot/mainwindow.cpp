#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton* bt_one = new QPushButton;
    bt_one->setParent(this);
    bt_one->setFixedWidth(200);
    bt_one->setFixedHeight(30);
    bt_one->setText("点我让另一个按钮变成傻子");

    bt_another = new QPushButton;
    bt_another->setParent(this);
    bt_another->move(250,0);
    bt_another->setFixedWidth(150);
    bt_another->setFixedHeight(30);
    bt_another->setText("我不是傻子");

    //信号实际上是发送者对象的一个方法
    //槽实际上也是接收者对象的一个方法
    connect(bt_one, &QPushButton::clicked, this, &MainWindow::change);
}

//槽处理的事件
void MainWindow::change(){
    bt_another->setText("我是傻子");
}

MainWindow::~MainWindow()
{
    delete ui;
}

