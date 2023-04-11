/*
 * This file is a part of the SubStandard C++ library.
 *
 * Developed for my own convenience in the future.
 * This product includes software developed by myself.
 * (Insert website here if I ever decide to make it)
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code security.
 *
 * This program is free software. You can redistribute and/or modify
 * it under the terms of the Creative Commons Attribution-NonCommercial-
 * ShareAlike 4.0 International License as published by Creative Commons,
 * either version 4.0 of the license, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0
 * International License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see
 * <https://creativecommons.org/licenses/by-nc/4.0/>.
 *
 *
 */

#ifndef SSTD_BINTREE_HPP
#define SSTD_BINTREE_HPP

#include <iostream>
#include <vector>

namespace sstd {

/// @brief Binary tree node class.
/// @tparam T : Type template parameter.
template <class T>
struct node {
  T value;
  node* left;
  node* right;

  /// @brief Constructor for node.
  /// @param value Value stored in node.
  node(T value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
  }
};

/// @brief Binary tree class.
/// @tparam T : Type template parameter.
template <class T>
class binTree {
 public:
  node<T>* root;

  /// @brief Constructor for binary tree.
  binTree() {
    root = nullptr;
    return;
  }

  /// @brief Adds a new node.
  /// @param value Value stored by the new node.
  void appendNode(int value) {
    node<T>* newNode = new node(value);
    if (root != nullptr) {
      node<T>* focus = root;
      node<T>* parent;
      while (true) {
        parent = focus;
        if (value < focus->value) {
          focus = focus->left;
          if (focus == nullptr) {
            parent->left = newNode;
            return;
          }
        } else {
          focus = focus->right;
          if (focus == nullptr) {
            parent->right = newNode;
            return;
          }
        }
      }
    }
    root = newNode;
    return;
  }

  /// @brief Preorder traverses a binary tree.
  /// @param focus Node focus.
  void preOrderTrav(node<T>* focus) {
    if (focus == nullptr) return;
    std::cout << focus->value << " ";
    preOrderTrav(focus->left);
    preOrderTrav(focus->right);
    return;
  }

  /// @brief Inorder traverses a binary tree.
  /// @param focus Node focus.
  void inOrderTrav(node<T>* focus) {
    if (focus == nullptr) return;
    inOrderTrav(focus->left);
    std::cout << focus->value << " ";
    inOrderTrav(focus->right);
    return;
  }

  /// @brief Postorder traverses a binary tree.
  /// @param focus Node focus.
  void postOrderTrav(node<T>* focus) {
    if (focus == nullptr) return;
    postOrderTrav(focus->left);
    postOrderTrav(focus->right);
    std::cout << focus->value << " ";
    return;
  }

  /// @brief Gets max value of a binary tree.
  /// @param focus Node focus.
  /// @return Largest value of the binary tree.
  T getMax(node<T>* focus) {
    node<T>* copy = focus;
    while (copy->right != nullptr) copy = copy->right;
    return copy->value;
  }

  /// @brief Gets min value of a binary tree.
  /// @param focus Node focus.
  /// @return Smallest value of the binary tree.
  T getMin(node<T>* focus) {
    node<T>* copy = focus;
    while (copy->left != nullptr) copy = copy->left;
    return copy->value;
  }

  node<T>* delNode(node<T>* focus, T value) {
    // T getMinRight(node<T> * focus) { return minRight; }

    if (focus == nullptr) return nullptr;
    if (focus->value < value)
      focus->right = delNode(focus->right, value);
    else if (focus->value > value)
      focus->left = delNode(focus->left, value);
    else {
      if (focus->left == nullptr && focus->right == nullptr) {
        free(focus);
        return nullptr;
      } else if (focus->left == nullptr) {
        node<T>* temp = focus->right;
        free(focus);
        return temp;
      } else if (focus->right == nullptr) {
        node<T>* temp = focus->left;
        free(focus);
        return temp;
      } else {
        T minRight = getMax(focus);
        focus->value = minRight;
        focus->right = delNode(focus->right, minRight);
      }
    }
    return focus;
  }
};

}  // namespace sstd

#endif