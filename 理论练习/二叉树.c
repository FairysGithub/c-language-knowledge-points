#include <stdio.h>
#include <stdlib.h>
// ����������ڵ�
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
// ���ݺ������������������������
TreeNode* buildTree(int* postorder, int postStart, int postEnd, int* inorder, int inStart, int inEnd) {
    if (postStart > postEnd || inStart > inEnd) return NULL;
    // ������������һ��Ԫ���Ǹ��ڵ�
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = postorder[postEnd];
    // ������������ҵ����ڵ�
    int inRoot = inStart;
    while (inorder[inRoot] != root->val) inRoot++;
    // �����������Ľڵ���
    int leftTreeSize = inRoot - inStart;
    // �ݹ鹹��������
    root->left = buildTree(postorder, postStart, postStart + leftTreeSize - 1, inorder, inStart, inRoot - 1);
    // �ݹ鹹��������
    root->right = buildTree(postorder, postStart + leftTreeSize, postEnd - 1, inorder, inRoot + 1, inEnd);
    return root;
}
// �������������
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int main() {
    int N;
    printf("������ڵ������\n");
    scanf("%d", &N);
    int* postorder = (int*)malloc(N * sizeof(int));
    int* inorder = (int*)malloc(N * sizeof(int));
    printf("������������ĺ���������У�\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }
    printf("�����������������������У�\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    TreeNode* root = buildTree(postorder, 0, N - 1, inorder, 0, N - 1);
    printf("�ö������������������Ϊ��\n");
    preorderTraversal(root);
    printf("\n");
    free(postorder);
    free(inorder);
    return 0;
}
