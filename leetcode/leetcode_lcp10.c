 /*Definition for a binary tree node.*/
#include "stdio.h"
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct node {
    int total;
    double max_parallel_time;
};

struct node DFS(struct TreeNode* root){
    if (root == NULL){
        return (struct node){0, 0.0};
    }
    struct node l = DFS(root->left);
    struct node r = DFS(root->right);

    int a = l.total, c = r.total;
    double b = l.max_parallel_time, d = r.max_parallel_time;
    int total = a+c+root->val;

    if (a < c){
        int temp = a;
        a = c;
        c = temp;
        double temp2 = b;
        b = d;
        d = temp2;
    }

    if (a - 2*b <= c){
        double max_pt = (a + c) / 2.0;
        return (struct node){total, max_pt};
    }
    else {
        double max_pt = b + c;
        return (struct node){total, max_pt};
    }
}

double minimalExecTime(struct TreeNode* root){
    struct node p = DFS(root);
    return p.total - p.max_parallel_time;
}

int main(){
    struct TreeNode root;
    root.val = 1;
    struct TreeNode l1;
    l1.val = 3;
    l1.left = NULL;
    l1.right = NULL;
    struct TreeNode r1;
    r1.val = 2;
    r1.left = NULL;
    r1.right = NULL;

    root.left = &l1;
    root.right = &r1;
    double t = minimalExecTime(&root);
    printf("time is %f\n", t);
}
