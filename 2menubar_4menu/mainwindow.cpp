#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QAction>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    /*
    ui->pushButton->installEventFilter(this);
    ui->pushButton->move(0,0);
    mian_menu_qd_analysebystep = new QDialog (this);
    QPushButton* bt1 = new QPushButton("哈哈哈", mian_menu_qd_analysebystep);
    QPushButton* bt2 = new QPushButton("哈哈哈", mian_menu_qd_analysebystep);
    QPushButton* bt3 = new QPushButton("哈哈哈", mian_menu_qd_analysebystep);
    mian_menu_qd_analysebystep->setWindowFlags(Qt::FramelessWindowHint);
    mian_menu_qd_analysebystep->hide();
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::btClick);
    */

    menuBar = new QMenuBar(this);
    QMenu* rootmenu = new QMenu("文件");

    QAction* action1= new QAction("新建");
    action1->setIcon(QIcon(":/img/app_2menu_new.png"));
    action1->setFont(QFont("微软雅黑"));
    QAction* action2= new QAction("打开");
    action2->setIcon(QIcon(":/img/app_2menu_open.png"));
    action2->setFont(QFont("微软雅黑"));
    QAction* action3= new QAction("关闭");
    action3->setIcon(QIcon(":/img/app_2menu_save.png"));
    action3->setFont(QFont("微软雅黑"));
    rootmenu->addAction(action1);
    rootmenu->addAction(action2);
    rootmenu->addAction(action3);
    menuBar->addMenu(rootmenu);


    menuBar->setStyleSheet(
        //5、以下为对菜单和菜单栏的设置(较简单)
        "QMenuBar{background-color:rgb(41,47,68);spacing:10;}"
        //"QMenuBar::item{background-color:rgb(41,47,68);}"
        "QMenu{background-color:rgb(41,47,68);}"
        "QMenu{color:rgb(255,255,255);spacing:10;}"
        "QMenu{font-family:'微软雅黑';}"
        );

    rootmenu->setStyleSheet(
        "QMenu{background-color:rgb(41,47,68);}"
        "QMenu::item{background-color:rgb(41,47,68);}"
        "QMenu::item{color:rgb(234,234,234);}"
        "QMenu::item{font-family:'微软雅黑';}"
        "QMenu::item:selected{background-color:rgb(33,37,50);}");

}

MainWindow::~MainWindow(){
    delete ui;
}

bool MainWindow::eventFilter(QObject *target, QEvent *e){
//    QPoint coursePoint;
//    coursePoint = QCursor::pos();//获取当前光标的位置

//    if(target == ui->pushButton)
//    {
//        if(e->type() == QEvent::Enter)
//        {
//            mian_menu_qd_analysebystep->move(coursePoint.x(),coursePoint.y());//坐标
//            int x=coursePoint.x()-300;
//            int y=coursePoint.y()-300;
//            //mian_menu_qd_analysebystep->setGeometry(x,y,150,150);
//            mian_menu_qd_analysebystep->show();
//            qDebug()<<("---------------------test:QEvent::Enter");
//        }
//        if(e->type() == QEvent::Leave)
//        {
//            mian_menu_qd_analysebystep->hide();
//            qDebug()<<("---------------------test:QEvent::Leave");
//        }

//    }
        return QWidget::eventFilter(target, e);
}

void MainWindow::btClick(){
    qDebug()<<("---------------------test:QPushButton::Click");
}

