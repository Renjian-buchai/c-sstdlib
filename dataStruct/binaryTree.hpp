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
 * TODO This.
 */

#ifndef SSTD_BINTREE_HPP
#define SSTD_BINTREE_HPP

namespace sstd {

#include <iostream>

struct Node {
  long data;
  Node* left;
  Node* right;

  Node(long data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BinaryTree {
 public:
  Node* root;

  BinaryTree() { root = nullptr; }

  void addNode(long data) {
    Node* newNode = new Node(data);

    if (root == nullptr) {
      root = newNode;
    } else {
      Node* focusNode = root;
      Node* parent;

      while (true) {
        parent = focusNode;

        if (data < focusNode->data) {
          focusNode = focusNode->left;
          if (focusNode == nullptr) {
            parent->left = newNode;
            return;
          }
        } else {
          focusNode = focusNode->right;
          if (focusNode == nullptr) {
            parent->right = newNode;
            return;
          }
        }
      }
    }
  }

  void preOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
      std::cout << focusNode->data << " ";
      preOrderTraversal(focusNode->left);
      preOrderTraversal(focusNode->right);
    }
  }
};

// template <typename T>
// class binNode : binRoot {
//  public:
//   T* value;
//   binRoot*
//
//   binRoot() {}
// };
//
// template <typename T>
// class binRoot {
//  public:
//   binRoot* leftChild;
//   binRoot* rightChild;
//
//   binRoot() { this->leftChild = this->rightChild = nullptr; }
// };
//
// class bintree {};

}  // namespace sstd

#endif