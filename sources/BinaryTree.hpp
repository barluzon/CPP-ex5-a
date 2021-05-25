#pragma once
#include <iostream>

using namespace std;

namespace ariel{
    template<typename T>
    class BinaryTree {

        struct Node {
        T data;
        Node* right;
        Node* left;
        Node(T val) : data(val), right(NULL), left(NULL) {};
        };

        class iterator {
            Node* currNode;
        public:

            iterator(Node* ptr = nullptr) : currNode(ptr) {}
            iterator(): currNode(nullptr){}

            T& operator*() const {
                return currNode->data;
            }

            T* operator->() const {
                return &(currNode->data);
            }

            iterator& operator++() {
                currNode = currNode->right;
                return *this;
            }
            const iterator operator++(int) {
                iterator tmp= *this;
                currNode = currNode->left;
                return tmp;
            }
            bool operator==(const iterator& it) const {
                return currNode == it.currNode;
            }
            bool operator!=(const iterator& it) const {
                return currNode != it.currNode;
            }
        };

        Node* root;
        public:
            BinaryTree(){}
            ~BinaryTree(){}
            BinaryTree<T>& add_root(T root){
                return *this;
            }
            BinaryTree<T>& add_left(T exist, T add){
                return *this;
            }
            BinaryTree<T>& add_right(T exist, T add){
                return *this;
            }
            iterator begin(){
                return iterator(root);
            }
            iterator end(){
                return iterator(root);
            }
            iterator begin_preorder(){
                return iterator(root);
            }
            iterator end_preorder(){
                return iterator(root);
            }
            iterator begin_inorder(){
            return iterator(root);
            }
            iterator end_inorder(){
                return iterator(root);
            }
            iterator begin_postorder(){
            return iterator(root);
            }
            iterator end_postorder(){
                return iterator(root);
            }

            friend std::ostream& operator<<(std::ostream &out, const BinaryTree<T> &b){
                return out;
            }
    };
}

