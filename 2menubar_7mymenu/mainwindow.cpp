#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    QList<QAction*> lists;
    QAction *newFile = new QAction("新建", this);
    QAction *openFile = new QAction("打开", this);
    QAction *saveFile = new QAction("保存"); //恢复默认设置
    QAction *closeFile = new QAction("关闭", this);
    QMenu *mfile = new QMenu;
    lists.append(newFile);
    lists.append(openFile);
    lists.append(saveFile);
    lists.append(closeFile);
    mfile->addActions(lists);


    ui->bt_file->setMenu(mfile);
}

MainWindow::~MainWindow(){
    delete ui;
}

