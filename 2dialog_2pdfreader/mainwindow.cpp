#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString qtManulFile="C:\\Users\\MarkCen\\Desktop\\DProject\\000PROJECT\\ui\\note_1Duilib下载与运行Demo.pdf";
    QDesktopServices::openUrl(QUrl::fromLocalFile(qtManulFile));
}
