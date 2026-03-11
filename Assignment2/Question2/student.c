/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int checkAVL(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) return 0;
    if ((long long)node->val <= min || (long long)node->val >= max) return -2;

    int leftH = checkAVL(node->left, min, (long long)node->val);
    if (leftH == -2) return -2;

    int rightH = checkAVL(node->right, (long long)node->val, max);
    if (rightH == -2) return -2;

    int diff = leftH - rightH;
    if (diff < -1 || diff > 1) return -2;

    return (leftH > rightH ? leftH : rightH) + 1;

}


bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced)
	return checkAVL(root, -2147483649LL, 2147483648LL) != -2;
}
