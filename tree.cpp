#include <iostream>
#include <queue>
using namespace std;
//使用指针实现树
struct TreeNode{
    bool hasValue;
    int value;
    TreeNode *leftNode,*rightNode;
    //vector<TreeNode*> childList;
    TreeNode():hasValue(false),leftNode(nullptr),rightNode(nullptr){}
    TreeNode(int v):hasValue(true),value(v),leftNode(nullptr),rightNode(nullptr){}
};
void removeTree(TreeNode* t){
    if(t!=nullptr)
    {
        removeTree(t->leftNode);
        removeTree(t->rightNode);
        delete t;
    }
}
//使用数组实现树
struct TreeArrayNode{
    bool hasValue;
    int value;
    int height;
    TreeArrayNode():hasValue(false){}
};
TreeArrayNode nodeArray[1000];
size_t leftNodeId[1000];
size_t rightNodeId[1000];
size_t currentId=0;

void inOrder(TreeNode*r){
    if(r!=nullptr&&r->hasValue)
    {
        inOrder(r->leftNode);
        cout<<r->value<<' ';
        inOrder(r->rightNode);
    }
}


int main()
{
    /*
      4
    ------
    |    |
    2    6
    ---  ----
    | |  | |
    1 3  5 7
    */
    TreeNode* root=new TreeNode(4);
    root->leftNode=new TreeNode(2);
    root->leftNode->leftNode=new TreeNode(1);
    root->leftNode->rightNode=new TreeNode(3);
    root->rightNode=new TreeNode(6);
    root->rightNode->leftNode=new TreeNode(5);
    root->rightNode->rightNode=new TreeNode(7);
    inOrder(root);
    removeTree(root);
    return 0;
}
