#include <iostream>
using namespace std;

/// @brief 二叉树结构体,值,左子树,右子树
struct BinaryTree
{
    int val;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

/// @brief  创建一个树节点
/// @param  val:节点的值  
struct BinaryTree* CreateNode(int val)
{
    struct BinaryTree* TreeNode=(struct BinaryTree*)malloc(sizeof(BinaryTree));
    TreeNode->val=val;
    TreeNode->left=NULL;
    TreeNode->right=NULL;
    return TreeNode;
}

/// @brief 打印二叉树(先序) 
/// @param  要打印的树的指针
void PrintTree_front(struct BinaryTree* TreeNode)
{
    if(TreeNode==NULL)
        return;
    cout<<TreeNode->val<<' ';
    PrintTree_front(TreeNode->left);
    PrintTree_front(TreeNode->right);
}

/// @brief 打印二叉树(中序) 
/// @param  要打印的树的指针
void PrintTree_medium(struct BinaryTree* TreeNode)
{
    if(TreeNode==NULL)
        return;
    PrintTree_medium(TreeNode->left);
    cout<<TreeNode->val<<' ';
    PrintTree_medium(TreeNode->right);
}

/// @brief 打印二叉树(后序) 
/// @param  要打印的树的指针
void PrintTree_beside(struct BinaryTree* TreeNode)
{
    if(TreeNode==NULL)
        return;
    PrintTree_beside(TreeNode->left);
    PrintTree_beside(TreeNode->right);
    cout<<TreeNode->val<<' ';
}


int main()
{
    struct BinaryTree* TreeNode=CreateNode(0);
    TreeNode->left=CreateNode(1);
    TreeNode->right=CreateNode(2);
    TreeNode->left->left=CreateNode(3);
    TreeNode->left->right=CreateNode(4);
    TreeNode->right->left=CreateNode(5);
    TreeNode->right->right=CreateNode(6);
    cout<<"先序遍历二叉树"<<endl;
    PrintTree_front(TreeNode);
    cout<<endl;
    cout<<"中序遍历二叉树"<<endl;
    PrintTree_medium(TreeNode);
    cout<<endl;
    cout<<"后序遍历二叉树"<<endl;
    PrintTree_beside(TreeNode);
    cout<<endl;
    return 0;
}