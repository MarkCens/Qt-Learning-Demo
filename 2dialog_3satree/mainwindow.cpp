#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "binarytreepainter.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString input1 = "ABC##D##EF#";
    QString input2 = "#C#B#D#AFE#";
    BinaryTreePainter *p = new BinaryTreePainter();
    p->setInput(input1,input2);
    p->show();
}
