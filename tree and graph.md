定义树结构  
'''c++
struct TreeNode{
    bool hasValue;
    int value;
    TreeNode *leftNode,*rightNode;
    //vector<TreeNode*> childList;
    TreeNode():hasValue(false),leftNode(nullptr),rightNode(nullptr){}
    TreeNode(int v):hasValue(true),value(v),leftNode(nullptr),rightNode(nullptr){}
};
'''
