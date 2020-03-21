#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);



    ui->wg_result->hide();

}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_bt_show_clicked()
{
    ui->wg_result->show();
}

void MainWindow::on_bt_hide_clicked()
{
    ui->wg_result->hide();
}
