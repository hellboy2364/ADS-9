// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>
template <typename S>
class BST {
 public:
    struct Knot {
        S value;
        int count;
        Knot* left;
        Knot* right;
    };
 private:
    Knot* root;
    Knot* addNode(Knot*, S);
    int depthTree(Knot*);
    int searchNode(Knot*, S);
 public:
    BST();
    void add(S);
    int depth();
    int search(S);
};
template <typename S>
BST <S>::BST() : root(nullptr) {}
template <typename S>
typename BST <S>::Knot* BST <S>::addNode(Knot* orig, S perem) {
    if (orig == nullptr) {
        orig = new Knot;
        orig->value = perem;
        orig->count = 1;
        orig->left = orig->right = nullptr;
    } else if (orig->value > perem) {
        orig->left = addNode(orig->left, perem);
    } else if (orig->value < perem) {
        orig->right = addNode(orig->right, perem);
    } else {
        orig->count++;
    }
    return orig;
}
template <typename S>
void BST <S>::add(S perem) {
    root = addNode(root, perem);
}
template <typename S>
int BST<S>::depthTree(Knot* orig) {
    if (orig == nullptr) {
        return 0;
    } else {
        int leftDepth = depthTree(orig->left);
        int rightDepth = depthTree(orig->right);
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }
}
template <typename S>
int BST<S>::depth() {
    return depthTree(root) - 1;
}
BST<std::string> makeTree(const char* fn);
template <typename S>
int BST<S>::searchNode(Knot* orig, S val) {
    if (orig == nullptr)
        return 0;
    else if (orig->value == val)
        return orig->count;
    else if (orig->value > val)
        return searchNode(orig->left, val);
    else
        return searchNode(orig->right, val);
}
template <typename S>
int BST<S>::search(S t) {
    return searchNode(root, t);
}

#endif  // INCLUDE_BST_H_
