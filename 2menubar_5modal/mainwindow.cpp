#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    //把给定的组件设定成主窗口的中央组件，这里是把plainTextEdit设为窗口的中央组件
    setCentralWidget(ui->pushButton);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_actionNew_Window_triggered);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionNew_Window_triggered()  {
    //新建一个窗口对象，其中的this指定了新的窗口的父对象是MainWindow，在销毁Mainwindow时也会销毁子对象，即该窗口对象
    settingDialog = new SettingDialog(this);
    //Modal属性决定了show()应该将弹出的dialog设置为模态还是非模态
    //默认情况下该属性为false并且show（）弹出的窗口是非模态的
    //把这个属性设置为true就详单与设置QWidget::windowModality为Qt::ApplicationModal
    //执行exec（）忽略这个Modal这个属性，并且把弹出的dialog设置为模态的
    settingDialog->setModal(true);    //此处ture为模态，false为非模态
    settingDialog->show();
}


