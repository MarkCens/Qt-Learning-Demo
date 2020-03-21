#ifndef BINARYTREEPAINTER_H
#define BINARYTREEPAINTER_H
#include <binarytree.h>
#include <QWidget>
#include<stack>
#include<cstdio>
#include<math.h>

class BinaryTreePainter:public QWidget
{
    Q_OBJECT
public:
    explicit BinaryTreePainter(QWidget* parent = 0);
    bool setInput(QString input1, QString input2);

protected:
    void paintEvent(QPaintEvent *);
    void draw(BinTreeNode *node, int x, int y, int angle, bool isLeft, int depth, QPainter *p);
    BinTreeNode* test();

private:
    linkedBinaryTree* myTree;
    const int rootLengt=100;
    const double PI=3.1415926;
};

#endif // BINARYTREEPAINTER_H
