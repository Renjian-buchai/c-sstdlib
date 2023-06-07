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

#ifndef SSTD_BINTREE_HH
#define SSTD_BINTREE_HH

#include <array>
#include <iostream>
#include <stack>
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

template <class T>
class binTree {
 private:
  size_t sz;
  node<T>* rt;

 public:
  binTree() {
    rt == nullptr;
    sz = 0;
    return;
  }

  template <size_t N>
  binTree(std::array<T, N> arr) {
    for (auto x : arr) this->appendNode(x);
    sz += arr.size();
    return;
  }

  // void appendNode(int value) {
  //   ++sz;
  //   node<T>* newNode = new node(value);
  //   if (rt == nullptr) {
  //     rt = newNode;
  //     return;
  //   }
  //   node<T>* focus = rt;
  //   node<T>* parent;
  //   while (true) {
  //     parent = focus;
  //     if (value < focus->value) {
  //       focus = focus->left;
  //       if (focus == nullptr) {
  //         parent->left = newNode;
  //         return;
  //       }
  //     } else {
  //       focus = focus->right;
  //       if (focus != nullptr) {
  //         parent->right = newNode;
  //         return;
  //       }
  //     }
  //   }
  // }

  std::vector<T> preOrd(node<T>* focus) {
    std::vector<T> val{};
    if (focus == nullptr) return val;
    std::stack<node<T>*> stack;
    stack.push(focus);
    while (stack.empty() == false) {
      node<T>* copy = stack.top();
      val.push_back(copy->value);
      stack.pop();
      if (copy->right) stack.push(copy->right);
      if (copy->left) stack.push(copy->left);
    }
    return val;
  }

  node<T>* root() { return rt; }
  size_t size() { return sz; }
};

//   std::vector<T> pOT(node<T>* focus) {
//     std::vector<T> val{};
//     if (focus == nullptr) return val;
//     std::stack<node<T>*> stack;
//     stack.push(focus);
//     while (stack.empty() == false) {
//       node<T>* copy = stack.top();
//       val.push_back(copy->value);
//       stack.pop();
//       if (copy->right) stack.push(copy->right);
//       if (copy->left) stack.push(copy->left);
//     }
//     return val;
//   }
//
//   /// @brief Inorder traverses a binary tree.
//   /// @param focus Node focus.
//   /// @return Vector containing binary tree after inorder traversal.
//   std::vector<T> inOrderTrav(node<T>* focus) {
//     std::vector<T> val{};
//     if (focus == nullptr) return val;
//     std::stack<node<T>*> stack;
//     node<T>* copy = focus;
//     while (copy != nullptr || stack.empty() == false) {
//       while (copy != nullptr) {
//         stack.push(copy);
//         copy = copy->left;
//       }
//       copy = stack.top();
//       stack.pop();
//       val.push_back(copy->value);
//       copy = copy->right;
//     }
//     return val;
//   }
//
//   /// @brief Postorder traverses a binary tree.
//   /// @param focus Node focus.
//   void postOrderTrav(node<T>* focus) {
//     if (focus == nullptr) return;
//     postOrderTrav(focus->left);
//     postOrderTrav(focus->right);
//     std::cout << focus->value << " ";
//     return;
//   }
//
//   /// @brief Gets max value of a binary tree.
//   /// @param focus Node focus.
//   /// @return Largest value of the binary tree.
//   T getMax(node<T>* focus) {
//     node<T>* copy = focus;
//     while (copy->right != nullptr) copy = copy->right;
//     return copy->value;
//   }
//
//   /// @brief Gets min value of a binary tree.
//   /// @param focus Node focus.
//   /// @return Smallest value of the binary tree.
//   T getMin(node<T>* focus) {
//     node<T>* copy = focus;
//     while (copy->left != nullptr) copy = copy->left;
//     return copy->value;
//   }
//
//   node<T>* delNode(node<T>* focus, T value) {
//     // T getMinRight(node<T> * focus) { return minRight; }
//
//     if (focus == nullptr) return nullptr;
//     if (focus->value < value)
//       focus->right = delNode(focus->right, value);
//     else if (focus->value > value)
//       focus->left = delNode(focus->left, value);
//     else {
//       if (focus->left == nullptr && focus->right == nullptr) {
//         free(focus);
//         return nullptr;
//       } else if (focus->left == nullptr) {
//         node<T>* temp = focus->right;
//         free(focus);
//         return temp;
//       } else if (focus->right == nullptr) {
//         node<T>* temp = focus->left;
//         free(focus);
//         return temp;
//       } else {
//         T minRight = getMax(focus);
//         focus->value = minRight;
//         focus->right = delNode(focus->right, minRight);
//       }
//     }
//     return focus;
//   }
//
// #ifdef SSTD_PRINTCONT_HH
//   /// @brief Preorder traverses and prints a binary tree.
//   /// @tparam T : Any arithmetic type.
//   /// @param focus Node focus.
//   void prePrintBinTree(node<T>* focus) {
//     if (focus == nullptr) return;
//     std::cout << focus->value << " ";
//     prePrintBinTree(focus->left);
//     prePrintBinTree(focus->right);
//     return;
//   }
//
//   /// @brief Inorder traverses and prints a binary tree.
//   /// @tparam T : Any arithmetic type.
//   /// @param focus Node focus.
//   /// @note Prints from smallest to largest.
//   void inPrintBinTree(node<T>* focus) {
//     if (focus == nullptr) return;
//     inPrintBinTree(focus->left);
//     std::cout << focus->value << " ";
//     inPrintBinTree(focus->right);
//     return;
//   }
//   // TODO Postprint bintree
//
//   void postPrintBinTree(node<T>* focus) {
//     if (focus == nullptr) return;
//     postPrintBinTree(focus->left);
//     postPrintBinTree(focus->right);
//     std::cout << focus->value << " ";
//     return;
//   }
//
// #endif
//
//   // Getter methods
//
//   node<T>* getRoot() { return root; }
// };

}  // namespace sstd

#endif