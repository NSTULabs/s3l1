#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <iomanip>

using namespace std;

struct TreeNode {
    int value;
    int height;
    int balance;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const int val) : value(val), height(0), left(nullptr), right(nullptr) {}
};

struct Tree {
    TreeNode* head;
    Tree() : head(nullptr) {}

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Метод вставки нового значения
    void insertNum(int value) {
        head = insert(head, value);
    }
};

void printTree(ostream& os, TreeNode* tree, int depth = 0, string prefix = "") {
    if (tree == nullptr) {
        return;
    }

    // Выводим правое поддерево (расположено выше в консоли)
    if (tree->right != nullptr) {
        printTree(os, tree->right, depth + 1, prefix + "\t");
    }

    // Выводим текущий узел с отступом
    os << prefix;
    if (depth > 0) {
        os << "└──";
    }
    os << "[" << tree->value << "]" << endl;

    // Выводим левое поддерево (расположено ниже в консоли)
    if (tree->left != nullptr) {
        printTree(os, tree->left, depth + 1, prefix + "\t");
    }
}

ostream& operator<<(ostream& os, const Tree& tree) {
    printTree(os, tree.head);
    return os;
}

#endif