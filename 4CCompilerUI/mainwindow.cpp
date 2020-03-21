#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadWindowUI();//加载、设置主窗口控件

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadWindowUI()
{
    loadTitlebar();//加载设置标题栏窗口控件
    loadMenubar();//加载设置菜单栏窗口控件
    loadMainPanel();//加载设置主面板编辑器控件
    loadResultbar();//加载设置编译输出结果控件
    loadStatusbar();//加载设置状态栏控件
}

void MainWindow::loadTitlebar()
{
    this->setWindowIcon(QIcon(":/img/app_1title_dark_appicon1.png"));
    this->setWindowTitle("C语言编译器");
}


void MainWindow::loadMenubar()
{
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

    //编辑菜单项
    QList<QAction*> edit_menu_list;
    QAction *edit_menu_item_format = new QAction("格式化     Alt+Shift+F");
    QAction *edit_menu_item_copy = new QAction("复制       Ctrl+C");
    QAction *edit_menu_item_delete = new QAction("删除       Ctrl+D");
    QAction *edit_menu_item_paste = new QAction("粘贴       Ctrl+V");
    QAction *edit_menu_item_undo = new QAction("撤销       Ctrl+Z");
    QAction *edit_menu_item_redo = new QAction("重做       Ctrl+Y");
    edit_menu_list.append(edit_menu_item_format);
    edit_menu_list.append(edit_menu_item_copy);
    edit_menu_list.append(edit_menu_item_delete);
    edit_menu_list.append(edit_menu_item_paste);
    edit_menu_list.append(edit_menu_item_undo);
    edit_menu_list.append(edit_menu_item_redo);
    QMenu *edit_menu = new QMenu;
    edit_menu->setStyleSheet("QMenu{background-color:rgb(33,37,50);}\
                         QMenu::item{font-size: 10pt;font-family: '微软雅黑';color: rgb(234,234,234);background-color:rgb(33,37,50);padding:8px 8px;margin:2px 2px;}\
                         QMenu::item:selected{background-color: rgb(234,234,234);color: rgb(33,37,50);}\
                         QMenu::item:pressed{border: 1px solid rgb(33,37,50);background-color: rgb(234,234,234);}");
    edit_menu->addActions(edit_menu_list);
    ui->main_menu_bt_2edit->setMenu(edit_menu);

    //编辑菜单项
    QList<QAction*> theme_menu_list;
    QAction *theme_menu_item_light = new QAction("亮色       Alt+Shift+L");
    QAction *theme_menu_item_dark = new QAction("夜色       Alt+Shift+D");
    theme_menu_list.append(theme_menu_item_light);
    theme_menu_list.append(theme_menu_item_dark);
    QMenu *theme_menu = new QMenu;
    theme_menu->setStyleSheet("QMenu{background-color:rgb(33,37,50);}\
                         QMenu::item{font-size: 10pt;font-family: '微软雅黑';color: rgb(234,234,234);background-color:rgb(33,37,50);padding:8px 8px;margin:2px 2px;}\
                         QMenu::item:selected{background-color: rgb(234,234,234);color: rgb(33,37,50);}\
                         QMenu::item:pressed{border: 1px solid rgb(33,37,50);background-color: rgb(234,234,234);}");
    theme_menu->addActions(theme_menu_list);
    ui->main_menu_bt_4theme->setMenu(theme_menu);

    //单步分析菜单项
    QList<QAction*> bystep_menu_list;
    QAction *bystep_menu_item_la = new QAction("词法分析");
    QAction *bystep_menu_item_ga = new QAction("语法分析");
    QAction *bystep_menu_item_sa = new QAction("语义分析");
    QAction *bystep_menu_item_icg = new QAction("中间代码生成");
    QAction *bystep_menu_item_ico = new QAction("中间代码优化");
    QAction *bystep_menu_item_ocg = new QAction("目标代码生成");
    bystep_menu_list.append(bystep_menu_item_la);
    bystep_menu_list.append(bystep_menu_item_ga);
    bystep_menu_list.append(bystep_menu_item_sa);
    bystep_menu_list.append(bystep_menu_item_icg);
    bystep_menu_list.append(bystep_menu_item_ico);
    bystep_menu_list.append(bystep_menu_item_ocg);
    QMenu *bystep_menu = new QMenu;
    bystep_menu->setStyleSheet("QMenu{background-color:rgb(33,37,50);}\
                         QMenu::item{font-size: 10pt;font-family: '微软雅黑';color: rgb(234,234,234);background-color:rgb(33,37,50);padding:8px 8px;margin:2px 2px;}\
                         QMenu::item:selected{background-color: rgb(234,234,234);color: rgb(33,37,50);}\
                         QMenu::item:pressed{border: 1px solid rgb(33,37,50);background-color: rgb(234,234,234);}");
    bystep_menu->addActions(bystep_menu_list);
    ui->main_menu_bt_6bystep->setMenu(bystep_menu);
}

void MainWindow::loadMainPanel()
{
    //编辑器类
    main_editor= new QsciScintilla();
    main_editor->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8);//设置编码为UTF-8


    //代码字体字体
    QFont code_font;
    code_font.setFamily("Consolas");
    code_font.setPointSize(16);//边栏字体大小

    //设置语法、语法高亮
    QsciLexerCPP *textLexer=new QsciLexerCPP;//创建一个C++词法分析器
    main_editor->setLexer(textLexer); //给QsciScintilla设置词法分析器
    textLexer->setPaper(QColor(33,37,50));//文本区域背景色
    textLexer->setFont(code_font);//设置代码字体大小
    textLexer->setDollarsAllowed(false);//设置不允许使用'$'符号
    textLexer->setFoldComments(true);//设置可以折叠多行注释
    textLexer->setColor(QColor(234, 234, 234), -1);//所有样式置为前景主题色
    textLexer->setColor(QColor(234, 234, 234), QsciLexerCPP::Default);//默认
    textLexer->setColor(QColor(255, 255, 255), QsciLexerCPP::Comment);//多行注释
    textLexer->setColor(QColor(30, 144, 255), QsciLexerCPP::CommentLine);//单行注释
    textLexer->setColor(QColor(234, 234, 234), QsciLexerCPP::CommentDoc);
    textLexer->setColor(QColor(255, 0, 255), QsciLexerCPP::Number);
    textLexer->setColor(QColor(255, 255, 0), QsciLexerCPP::Keyword);//关键词
    textLexer->setColor(QColor(255, 215, 0), QsciLexerCPP::DoubleQuotedString);//两次引用
    textLexer->setColor(QColor(255, 165, 0), QsciLexerCPP::SingleQuotedString);//单次引用
    textLexer->setColor(QColor(0, 255, 255), QsciLexerCPP::UUID);//唯一识别码
    textLexer->setColor(QColor(255, 0, 255), QsciLexerCPP::PreProcessor);//预处理头
    textLexer->setColor(QColor(234, 234, 234), QsciLexerCPP::Operator);//算符
    textLexer->setColor(QColor(	0, 250, 154), QsciLexerCPP::Identifier);//标识符
    textLexer->setColor(QColor(220, 20, 60), QsciLexerCPP::UnclosedString);//未封闭字符串
    textLexer->setColor(QColor(255, 255, 255), QsciLexerCPP::VerbatimString);//转义字符
    textLexer->setColor(QColor(30, 144, 255), QsciLexerCPP::RawString);//生字符串
    textLexer->setColor(QColor(255, 255, 255), QsciLexerCPP::CommentLineDoc);//单行注释文档

    //设置行号边栏
    QFont margin_font;
    margin_font.setFamily("Consolas");
    margin_font.setPointSize(12);//边栏字体大小
    main_editor->setMarginsFont(margin_font);//设置边栏字体
    main_editor->setMarginType(0,QsciScintilla::NumberMargin);//设置标号为0的边栏显示行号
    main_editor->setMarginLineNumbers(0,true);//设置第0个边栏为行号边栏，True表示显示
    main_editor->setMarginWidth(0,45);//设置0边栏宽度，经测试可以显示99999个行号（字体大小：12）
    main_editor->setMarginsForegroundColor(QColor(234, 234, 234));//边栏字体颜色
    main_editor->setMarginsBackgroundColor(QColor(33, 37, 50));//边栏字体背景
    main_editor->setFolding(QsciScintilla::PlainFoldStyle);//折叠样式
    main_editor->setFoldMarginColors(QColor(33, 37, 50),QColor(33, 37, 50));//折叠栏颜色

    //当前行设置
    main_editor->setCaretWidth(2);//光标宽度，0表示不显示光标
    main_editor->setCaretForegroundColor(QColor(234, 234, 234));  //光标颜色
    main_editor->setCaretLineVisible(true); //是否高亮显示光标所在行
    main_editor->setCaretLineBackgroundColor(QColor(41,47,68));//光标所在行背景颜色

    //选中部分设置
    main_editor->setSelectionBackgroundColor(QColor(234, 234, 234));//选中文本背景色
    main_editor->setSelectionForegroundColor(QColor(41,47,68));//选中文本前景色

    //缩进设置
    main_editor->setIndentationsUseTabs(false);//false表示用空格代替\t
    main_editor->setTabWidth(4);//缩进宽度设为8个空格
    main_editor->setIndentationGuides(true);//用tab键缩进时，在缩进位置上显示一个竖点线，缩进有效，在字符串后加空格不显示
    main_editor->setIndentationWidth(0);//如果在行首部空格位置tab，缩进的宽度字符数，并且不会转换为空格
    main_editor->setAutoIndent(true);//换行后自动缩进
    main_editor->setBackspaceUnindents(true);//删除缩进，直接删除这个缩进宽度，而不是空格
    main_editor->setTabIndents(true);//True如果行前空格数少于tabWidth，补齐空格数,False如果在文字前tab同true，如果在行首tab，则直接增加tabwidth个空格
    main_editor->setBraceMatching(QsciScintilla::SloppyBraceMatch);//括号匹配

    //设置空格
    main_editor->setWhitespaceVisibility(QsciScintilla::WsInvisible);
    main_editor->setWhitespaceSize(4);//空格点大小

    //代码提示静态集合
    QsciAPIs *apis=new QsciAPIs(textLexer);
    apis->add(QString("break"));
    apis->add(QString("case"));
    apis->add(QString("char"));
    apis->add(QString("continue"));
    apis->add(QString("default"));
    apis->add(QString("do"));
    apis->add(QString("else"));
    apis->add(QString("for"));
    apis->add(QString("if"));
    apis->add(QString("int"));
    apis->add(QString("long"));
    apis->add(QString("return"));
    apis->add(QString("short"));
    apis->add(QString("signed"));
    apis->add(QString("sizeof"));
    apis->add(QString("static"));
    apis->add(QString("struct"));
    apis->add(QString("switch"));
    apis->add(QString("typedef"));
    apis->add(QString("unsigned"));
    apis->add(QString("void"));
    apis->add(QString("while"));
    apis->add(QString("define"));
    apis->add(QString("#include"));
    apis->add(QString("main"));
    apis->prepare();

    //代码补全
    main_editor->setAutoCompletionSource(QsciScintilla::AcsAll);//自动补全
    main_editor->setAutoCompletionThreshold(1);//设置每输入1个字符就会出现自动补全的提示

    //换行设置
    main_editor->setWrapMode(QsciScintilla::WrapWord); //文本自动换行模式
    main_editor->setEolMode(QsciScintilla::EolWindows); //Windows操作系统风格换行符

    //滚动条设置
    main_editor->setScrollWidth(1);
    main_editor->setScrollWidthTracking(true);
    main_editor->verticalScrollBar()->setStyleSheet(
    "QScrollBar:vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"
    "QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"
    "QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"
    "QScrollBar::add-line:vertical{height:9px;width:8px;subcontrol-position:bottom;}"
    "QScrollBar::sub-line:vertical{height:9px;width:8px;subcontrol-position:top;}"
    "QScrollBar::add-line:vertical:hover{height:9px;width:8px;subcontrol-position:bottom;}"
    "QScrollBar::sub-line:vertical:hover{height:9px;width:8px;subcontrol-position:top;}"
    "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;}");
    main_editor->horizontalScrollBar()->setStyleSheet(
    "QScrollBar:horizontal{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"
    "QScrollBar::handle:horizontal{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"
    "QScrollBar::handle:horizontal:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"
    "QScrollBar::add-line:horizontal{height:9px;width:8px;subcontrol-position:bottom;}"
    "QScrollBar::sub-line:horizontal{height:9px;width:8px;subcontrol-position:top;}"
    "QScrollBar::add-line:horizontal:hover{height:9px;width:8px;subcontrol-position:bottom;}"
    "QScrollBar::sub-line:horizontal:hover{height:9px;width:8px;subcontrol-position:top;}"
    "QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{background:rgba(0,0,0,10%);border-radius:4px;}");


    //把编辑器类添加到布局中去
    main_editor->setParent(ui->main_wg_main);
    ui->main_vl_main->addWidget(main_editor);
    ui->main_wg_main->setLayout(ui->main_vl_main);
}

void MainWindow::loadResultbar()
{

}

void MainWindow::loadStatusbar()
{

}




