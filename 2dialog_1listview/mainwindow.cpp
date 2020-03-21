#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置
    ui->listWidget->setStyleSheet("QListWidget::Item:hover{background:rgb(33,37,50);}"
    "QListWidget::Item:selected{background:rgb(33,37,50);border:none;}");



    ui->listWidget->setFocusPolicy(Qt::NoFocus);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //删除一项
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}

void MainWindow::on_pushButton_2_clicked()
{
    //添加一项
    QWidget* plugin_0widget = new QWidget(ui->listWidget);
    QHBoxLayout *plugin_hl_item = new QHBoxLayout;
    QLabel *plugin_2name = new QLabel(this);
    plugin_2name->setText("词法分析插件");
    plugin_2name->setStyleSheet("QLabel{padding-left:5px;color:rgb(234,234,234);font-family:'微软雅黑';}");
    QLabel *plugin_3path = new QLabel(this);
    plugin_3path->setText("H:\\Learn_Code\\QtProjects\\Lab\2dialog_1listview\\img");
    plugin_3path->setStyleSheet("QLabel{padding-left:5px;padding-right:5px;color:rgb(234,234,234);font-family:'微软雅黑';}");
    QPushButton *plugin_4delete = new QPushButton(this);
    plugin_4delete->setFixedSize(32, 32);
    plugin_4delete->setIcon(QIcon(":/img/delete.png"));
    plugin_4delete->setIconSize(QSize(20, 20));
    connect(plugin_4delete, SIGNAL(clicked()), this, SLOT(OpenFolder()));
    //为布局添加上面的控件
    plugin_hl_item->setContentsMargins(0, 0, 0, 0);
    plugin_hl_item->setMargin(0);
    plugin_hl_item->setSpacing(0);
    plugin_hl_item->addWidget(plugin_2name);
    plugin_hl_item->addWidget(plugin_3path);
    plugin_hl_item->addStretch();//添加Spacer
    plugin_hl_item->addWidget(plugin_4delete);
    plugin_0widget->setLayout(plugin_hl_item);
    plugin_0widget->setStyleSheet("background:transparent;");

    //将plugin_0widget作为列表的item
    QListWidgetItem *item = new QListWidgetItem();
    QSize size = item->sizeHint();
    item->setSizeHint(QSize(size.width(), 36));
    ui->listWidget->addItem(item);
    ui->listWidget->setSizeIncrement(size.width(), 36);
    ui->listWidget->setItemWidget(item, plugin_0widget);
}

void MainWindow::on_pushButton_update_clicked()
{
    if(ui->listWidget->currentItem()!=Q_NULLPTR)
    {
        ui->listWidget->currentItem();
    }
}

void MainWindow::on_pushButton_read_clicked()
{

}
