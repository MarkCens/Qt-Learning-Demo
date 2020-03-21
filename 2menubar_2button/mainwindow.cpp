#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->main_menu_bt_analyse->setStyleSheet(
                "QPushButton{font-family:'微软雅黑'}"/*设置字体*/
                "QPushButton{color:rgb(234,234,234)}"/*设置字体颜色*/
                "QPushButton{border-image: url(:/img/app_round_button_darkblue.9.png);}"/*设置按钮背景*/
                "QPushButton:hover{border-image: url(:/img/app_round_button_green.9.png);}"/*设置鼠标滑过按钮背景*/
                "QPushButton:pressed{border-image: url(:/img/app_round_button_darkblue.9.png);}");/*设置鼠标点击按钮背景*/
}

MainWindow::~MainWindow(){
    delete ui;
}

