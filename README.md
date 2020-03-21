# **Qt学习文档**

​		那么，在该GitHub项目中，每一个目录都将会对应一个Qt项目，这些Qt项目的意义在于使用Qt的控件，并且还是关于开发自定义编辑器方面的。核心的Demo效果如下：

​		QTableWidget，多行多列控件。

![](C:\Users\MarkCen\Desktop\Qt-Learning-Demo\0res\999992dialog_1tablewidget.png)



​		BinaryTree，二叉树绘制（有点ugly）。

![](C:\Users\MarkCen\Desktop\Qt-Learning-Demo\0res\999992dialog_3satree.png)



​		Button，自定义按钮。

![](C:\Users\MarkCen\Desktop\Qt-Learning-Demo\0res\999992menubar_2button.png)



​		Dialog，模态框。

![](C:\Users\MarkCen\Desktop\Qt-Learning-Demo\0res\999992menubar_5modal.png)



​		Layout，Qt布局。

![](C:\Users\MarkCen\Desktop\Qt-Learning-Demo\0res\999992menubar_6layout.png)



​		ButtonMenu，按钮菜单。

![](C:\Users\MarkCen\Desktop\Qt-Learning-Demo\0res\999992menubar_7mymenu.png)



​		CodeEditor，好看的、有语法高亮的编辑器界面。

![](C:\Users\MarkCen\Desktop\Qt-Learning-Demo\0res\999994CCompilerUI.png)



## 一、标题栏

### 1、修改标题

​		方式一如下：

![](C:\Users\MarkCen\Desktop\Qt-Learning-Demo\0res\1583500948212.png)

​		方式二如下：

![](C:\Users\MarkCen\Desktop\Qt-Learning-Demo\0res\1583501501664.png)



### 2、修改图标

​		1、创建qrc文件。

![1583501662153](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583501662153.png)

​		然后在该项目目录之下新建一个资源文件夹，命名自定义，这个文件夹 便可以存放一些图片资源，这样项目在使用的时候可以使用相对路径，如果这些图片资源放在其他盘使用的则是绝对路径。比如，"res"。新建完后如下：

![1583502593883](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583502593883.png)

​	对刚刚添加的qrc文件添加“现有文件”。添加完后项目如下：

![1583502873866](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583502873866.png)

​		接下来在主窗口添加代码设置窗口图标：

![1583502956280](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583502956280.png)

​		修改完窗口图标和标题之后的效果如下：

![1583503650019](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583503650019.png)



## 二、菜单栏

### 1、信号和槽（事件处理）

​		原理如下：

![1583505605223](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583505605223.png)

​		demo：点击一个按钮，让另外一个按钮的文本发生变化。

![1583509718353](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583509718353.png)

![1583509733718](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583509733718.png)

​		MainWindow代码（记得在MainWindow头文件声明相关的成员）如下：

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
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

MainWindow::~MainWindow(){
    delete ui;
}
```

### 2、自定义按钮、文本样式

​		比较常用的方法是使用styleSheet的方式。使用如下（在代码中设置）：

```c++
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
```

​		除了在代码中设置，也可以在Qt Designer中点击控件的styleSheet属性，其中资源一般是图片。并对其添加相关的样式。如下：

![1583639858766](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583639858766.png)

![1583639869008](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1583639869008.png)

### 3、按钮菜单

​		具体代码如下：

```c++
//文件菜单项
QList<QAction*> file_menu_list;
QAction *file_menu_item_new = new QAction("新建       Ctrl+N");
QAction *file_menu_item_open = new QAction("打开       Ctrl+O");
QAction *file_menu_item_save = new QAction("保存       Ctrl+S");
QAction *file_menu_item_close = new QAction("关闭       Ctrl+X");
file_menu_list.append(file_menu_item_new);
file_menu_list.append(file_menu_item_open);
file_menu_list.append(file_menu_item_save);
file_menu_list.append(file_menu_item_close);
QMenu *file_menu = new QMenu;
file_menu->setStyleSheet("QMenu{background-color:rgb(33,37,50);}\
QMenu::item{font-size: 10pt;font-family: '微软雅黑';color: rgb(234,234,234);background-color:rgb(33,37,50);padding:8px 8px;margin:2px 2px;}\
QMenu::item:selected{background-color: rgb(234,234,234);color: rgb(33,37,50);}\
QMenu::item:pressed{border: 1px solid rgb(33,37,50);background-color: rgb(234,234,234);}");
file_menu->addActions(file_menu_list);
ui->main_menu_bt_1file->setMenu(file_menu);
```



### 4、Qt界面布局

​		1） Qt布局一般都使用水平布局和垂直布局。

​		2） 使用自底向上的方法为控件添加布局。选中控件、右键添加布局即可。

​		3） 每一个Widget都需要制定布局，这样才能使布局（或者里面的控件）最大化，也就是随着窗口自适应。而Widget指定布局的位置如下图：

![1584461432626](C:\Users\MarkCen\AppData\Roaming\Typora\typora-user-images\1584461432626.png)







## 三、主界面

### 1、CodeEditor

​		使用请参考文章：https://blog.csdn.net/gongjianbo1992/article/details/100828180。

​		美化请参考文章：https://www.bbsmax.com/A/MAzAXq0od9/。





## 四、状态栏

### 1、滑入滑出窗口

​		对Widget控件调用其的show()和hide()即可。



## 五、其他常用控件

### 1、QTableWidget

​		数据项（也就是item）的行数（rowCount）是需要自己更新的，当添加了一行，同时也需要setRowCount(当前count+1)，删除了一行也是如此。

​		关于QTableWidget的一些样式如下：

```c++
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
```



### 2、MessageBox

```c++
QMessageBox* msgBox = new QMessageBox;
msgBox->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
msgBox->setText("确实要删除吗?");
msgBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
msgBox->setDefaultButton(QMessageBox::Ok);
//设置QMessageBox的样式
msgBox->setStyleSheet("QPushButton{background-color:rgb(255, 85, 0);color: rgb(85, 255, 0);}"
"QMessageBox{background-color:white}");
int ret = msgBox->exec();
if(ret == QMessageBox::Ok){
ui->main_tw->removeRow(ui->main_tw->currentRow());
ui->main_tw->setRowCount(count-1);
}
delete msgBox;
```













































































































































































































































































































































