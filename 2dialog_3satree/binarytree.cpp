#include "binarytree.h"
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

BinTreeNode* linkedBinaryTree::Rebuild(vector<char> pre, vector<char> mid)
{
    int nodeSize = mid.size();
    if (nodeSize == 0)
        return NULL;
    vector<char> leftPre, leftMid, rightPre, rightMid;
    BinTreeNode* Root = new BinTreeNode(pre[0]);
    int rootPos = 0;
    for (int i = 0; i < nodeSize; i++)
    {
        if (mid[i] == pre[0])
        {
            rootPos = i;
            break;
        }
    }
    for (int i = 0; i < nodeSize; i++)
    {
        if (i < rootPos)
        {

            leftMid.push_back(mid[i]);

            leftPre.push_back(pre[i + 1]);
        }
        else if (i > rootPos)
        {

            rightMid.push_back(mid[i]);
            rightPre.push_back(pre[i]);
        }
    }
    Root->leftChild = Rebuild(leftPre, leftMid);
    Root->rightChild = Rebuild(rightPre, rightMid);
    return Root;
}
