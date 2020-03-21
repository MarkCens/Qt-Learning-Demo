#include "binarytreepainter.h"
#include <QPainter>

#include<QStack>
#include<QStack>
#include<QPoint>

BinaryTreePainter::BinaryTreePainter(QWidget *parent) : QWidget(parent)
{
    resize(600, 400);
    myTree = new linkedBinaryTree();
}

bool BinaryTreePainter::setInput(QString input1, QString input2)
{
    std::string s1 = input1.toStdString();
    std::string s2 = input2.toStdString();
    vector<char>v1;
    vector<char>v2;
    for(int i=0;i<s1.size();i++){v1.push_back(s1[i]);};
    for(int i=0;i<s2.size();i++){v2.push_back(s2[i]);};
    myTree->set(v1,v2);
    return true;
}
BinTreeNode* BinaryTreePainter::test()
{
    BinTreeNode*root=NULL;
    root=new BinTreeNode('A');
    root->leftChild=new BinTreeNode('B');
    root->rightChild=new BinTreeNode('C');
    root->leftChild->leftChild=new BinTreeNode('D');
    root->leftChild->rightChild=new BinTreeNode('E');
    root->rightChild->leftChild=new BinTreeNode('F');
    root->rightChild->rightChild=new BinTreeNode('G');
    return root;
}
void BinaryTreePainter::draw(BinTreeNode *node, int x, int y, int angle, bool isLeft, int depth, QPainter *p)
{
    int leftAngle, rightAngle;
    int dx,dy,nx,ny;
    if (node==NULL)
        return;
    p->drawText(x,y,QChar(node->data));
    if (node->leftChild!=NULL)
    {
        if (depth<2)
        {
            leftAngle = angle + rand()%15;
        } else
        {
            if (!isLeft) {
                leftAngle = angle + rand()%5 + 10;
            } else {
                leftAngle = rand()%45;
            }
        }
        int lenEdge = rootLengt-depth*35;
        dx = -cos(leftAngle*PI/180)*lenEdge;
        dy = sin(leftAngle*PI/180)*lenEdge;
        nx = x+dx;
        ny = y+dy;
        p->drawLine(x,y,nx,ny);
        draw(node->leftChild,nx,ny,leftAngle,true,depth+1,p);
    }
    if (node->rightChild!=NULL)
    {
        if (depth<2)
        {
            rightAngle = angle + rand()%15;
        } else
        {
            if (isLeft)
            {
                rightAngle = angle + rand()%5 + 10;
            }
            else
            {
                rightAngle = rand()%45;
            }
        }
        int lenEdge = rootLengt-depth*15;
        dx = cos(rightAngle*PI/180)*lenEdge;
        dy = sin(rightAngle*PI/180)*lenEdge;
        nx = x+dx;
        ny = y+dy;
        p->drawLine(x,y,nx,ny);
        draw(node->rightChild,nx,ny,rightAngle,false,depth+1,p);

    }
    if (node->leftChild==NULL && node->rightChild==NULL) {return ; }

}

void BinaryTreePainter::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    draw(myTree->getRoot(), width()/2, height()/2, 10, true, 0, &p);
}
