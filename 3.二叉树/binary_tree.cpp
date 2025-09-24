#include <iostream>
using namespace std;

/// @brief �������ṹ��,ֵ,������,������
struct BinaryTree
{
    int val;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

/// @brief  ����һ�����ڵ�
/// @param  val:�ڵ��ֵ  
struct BinaryTree* CreateNode(int val)
{
    struct BinaryTree* TreeNode=(struct BinaryTree*)malloc(sizeof(BinaryTree));
    TreeNode->val=val;
    TreeNode->left=NULL;
    TreeNode->right=NULL;
    return TreeNode;
}

/// @brief ��ӡ������(����) 
/// @param  Ҫ��ӡ������ָ��
void PrintTree_front(struct BinaryTree* TreeNode)
{
    if(TreeNode==NULL)
        return;
    cout<<TreeNode->val<<' ';
    PrintTree_front(TreeNode->left);
    PrintTree_front(TreeNode->right);
}

/// @brief ��ӡ������(����) 
/// @param  Ҫ��ӡ������ָ��
void PrintTree_medium(struct BinaryTree* TreeNode)
{
    if(TreeNode==NULL)
        return;
    PrintTree_medium(TreeNode->left);
    cout<<TreeNode->val<<' ';
    PrintTree_medium(TreeNode->right);
}

/// @brief ��ӡ������(����) 
/// @param  Ҫ��ӡ������ָ��
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
    cout<<"�������������"<<endl;
    PrintTree_front(TreeNode);
    cout<<endl;
    cout<<"�������������"<<endl;
    PrintTree_medium(TreeNode);
    cout<<endl;
    cout<<"�������������"<<endl;
    PrintTree_beside(TreeNode);
    cout<<endl;
    return 0;
}