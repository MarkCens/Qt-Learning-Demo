#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QScrollBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->main_tw->setColumnCount(2);
    ui->main_tw->setRowCount(2);
    ui->main_tw->setHorizontalHeaderLabels(QStringList()<<"插件名称" << "插件路径");
    ui->main_tw->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->main_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->main_tw->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个
    ui->main_tw->setItem(0,0,new QTableWidgetItem("词法分析"));
    ui->main_tw->setItem(0,1,new QTableWidgetItem("C:\\Users\\MarkCen\\Desktop\\DProject\\000PROJECT\\ui"));
    ui->main_tw->verticalHeader()->setVisible(false);//隐藏列表头
    ui->main_tw->setItem(1,0,new QTableWidgetItem("语义分析"));
    ui->main_tw->setItem(1,1,new QTableWidgetItem("C:\\Users\\MarkCen\\Desktop\\DProject\\000PROJECT\\ui"));

    ui->main_tw->selectRow(0);
    //设置样式
    //设置表格样式
    ui->main_tw->setStyleSheet(
                "color:rgb(234,234,234);"
                "gridline-color:rgb(41,47,68);"   /*表格中的网格线条颜色*/
                "background:rgb(41,47,68);"
                /*"alternate-background-color:gray;"  *//*设置交替颜色*/
                "selection-color:rgb(234,234,234);"
                "selection-background-color:rgb(33,37,50);"
                "border:none;");

    //设置表头样式
    ui->main_tw->horizontalHeader()->setStyleSheet(
    "QHeaderView::section{background:rgb(33,37,50); padding:4px; border:0px solid rgb(41,47,68); color:rgb(234,234,234);}"
    "QHeaderView::section:checked{background-color:rgb(41,47,68); color:rgb(234,234,234);}");
    ui->main_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->main_tw->horizontalHeader()->setStretchLastSection(true);//最后一列伸缩铺满
    ui->main_tw->setFocusPolicy(Qt::NoFocus);

    ui->main_tw->verticalScrollBar()->setStyleSheet(
    "QScrollBar:vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"
    "QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"
    "QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"
    "QScrollBar::add-line:vertical{height:9px;width:8px;subcontrol-position:bottom;}"
    "QScrollBar::sub-line:vertical{height:9px;width:8px;subcontrol-position:top;}"
    "QScrollBar::add-line:vertical:hover{height:9px;width:8px;subcontrol-position:bottom;}"
    "QScrollBar::sub-line:vertical:hover{height:9px;width:8px;subcontrol-position:top;}"
    "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_main_bt_add_clicked()
{
    int count = ui->main_tw->rowCount();
    qDebug()<<QString::number(count);
    ui->main_tw->setRowCount(count+1);
    ui->main_tw->setItem(count,0,new QTableWidgetItem("语法分析"));
    ui->main_tw->setItem(count,1,new QTableWidgetItem("C:\\Users\\MarkCen\\Desktop\\DProject\\000PROJECT"));
    count = ui->main_tw->rowCount();
    qDebug()<<QString::number(count);
}

void MainWindow::on_main_bt_delete_clicked()
{
    int count = ui->main_tw->rowCount();
    if (ui->main_tw->currentItem() != Q_NULLPTR)
    {
        QMessageBox* msgBox = new QMessageBox;
        msgBox->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        msgBox->setText("确实要删除吗?");
        msgBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox->setDefaultButton(QMessageBox::Ok);
        msgBox->setStyleSheet("QPushButton{background-color:rgb(255, 85, 0);color: rgb(85, 255, 0);}"
                              "QMessageBox{background-color:white}");
        int ret = msgBox->exec();
        if(ret == QMessageBox::Ok){
            ui->main_tw->removeRow(ui->main_tw->currentRow());
            ui->main_tw->setRowCount(count-1);
        }
        delete msgBox;
    }
}

void MainWindow::on_main_bt_update_clicked()
{
    int row = ui->main_tw->currentRow();
    QTableWidgetItem *item1 =ui->main_tw->item(row, 1);
    item1->setText("哈哈哈哈");
    ui->main_tw->setItem(row, 1, item1);

}

void MainWindow::on_main_bt_read_clicked()
{
    int row = ui->main_tw->currentRow();

    QTableWidgetItem *item0 =ui->main_tw->item(row, 0);
    QTableWidgetItem *item1 =ui->main_tw->item(row, 1);

    qDebug()<< "---------> item0：" << item0->text() << endl;
    qDebug()<< "---------> item1：" << item1->text() << endl;

}
