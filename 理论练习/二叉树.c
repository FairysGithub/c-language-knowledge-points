#include <stdio.h>
#include <stdlib.h>
// 定义二叉树节点
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
// 根据后序和中序遍历结果构建二叉树
TreeNode* buildTree(int* postorder, int postStart, int postEnd, int* inorder, int inStart, int inEnd) {
    if (postStart > postEnd || inStart > inEnd) return NULL;
    // 后序遍历的最后一个元素是根节点
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = postorder[postEnd];
    // 在中序遍历中找到根节点
    int inRoot = inStart;
    while (inorder[inRoot] != root->val) inRoot++;
    // 计算左子树的节点数
    int leftTreeSize = inRoot - inStart;
    // 递归构建左子树
    root->left = buildTree(postorder, postStart, postStart + leftTreeSize - 1, inorder, inStart, inRoot - 1);
    // 递归构建右子树
    root->right = buildTree(postorder, postStart + leftTreeSize, postEnd - 1, inorder, inRoot + 1, inEnd);
    return root;
}
// 先序遍历二叉树
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int main() {
    int N;
    printf("请输入节点个数：\n");
    scanf("%d", &N);
    int* postorder = (int*)malloc(N * sizeof(int));
    int* inorder = (int*)malloc(N * sizeof(int));
    printf("请输入二叉树的后序遍历序列：\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }
    printf("请输入二叉树的中序遍历序列：\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    TreeNode* root = buildTree(postorder, 0, N - 1, inorder, 0, N - 1);
    printf("该二叉树的先序遍历序列为：\n");
    preorderTraversal(root);
    printf("\n");
    free(postorder);
    free(inorder);
    return 0;
}
