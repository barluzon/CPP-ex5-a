#include "BinaryTree.hpp"
#include "doctest.h"
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Build and change"){
    BinaryTree<string> stringsTree;

    CHECK_THROWS(stringsTree.add_left("should", "throw"));
    CHECK_THROWS(stringsTree.add_right("you", "out"));

    CHECK_NOTHROW(stringsTree.add_root("Root"));
    CHECK_NOTHROW(stringsTree.add_left("Root", "B"));
    CHECK_NOTHROW(stringsTree.add_right("Root", "C"));
    CHECK_NOTHROW(stringsTree.add_root("A"));

    CHECK_NOTHROW(stringsTree.add_right("B", "D"));
    CHECK_NOTHROW(stringsTree.add_right("B", "E"));

    CHECK_NOTHROW(stringsTree.add_left("C", "D"));
    CHECK_NOTHROW(stringsTree.add_right("C", "E"));

    CHECK_NOTHROW(stringsTree.add_left("C", "F"));
    CHECK_NOTHROW(stringsTree.add_right("C", "G"));

    CHECK_THROWS(stringsTree.add_right("X", "A"));
    CHECK_THROWS(stringsTree.add_left("X", "A"));
}

TEST_CASE("Preorder"){
    BinaryTree<char> charsTree;

    charsTree.add_root ('A');
    charsTree.add_left ('A','B');
    charsTree.add_right ('A','C');

    charsTree.add_left ('B','D');
    charsTree.add_right ('B','E');

    charsTree.add_left ('D','H');
    charsTree.add_right ('D','I');

    charsTree.add_left ('C','F');
    charsTree.add_right ('C','G');

    charsTree.add_left ('G','J');

    string preorder;

    for (auto it = charsTree.begin_preorder(); it != charsTree.end_preorder(); it++){
        preorder += to_string(*it);
    }

    CHECK(*(charsTree.begin_postorder()) == 'A');
    CHECK(*(charsTree.end_postorder()) == 'J');
    CHECK_EQ("ABDHIECFGJ",preorder);
}

TEST_CASE("Inorder"){
    BinaryTree<char> charsTree;

    charsTree.add_root ('A');
    charsTree.add_left ('A','B');
    charsTree.add_right ('A','C');

    charsTree.add_left ('B','D');
    charsTree.add_right ('B','E');

    charsTree.add_left ('D','H');
    charsTree.add_right ('D','I');

    charsTree.add_left ('C','F');
    charsTree.add_right ('C','G');

    charsTree.add_left ('G','J');

    string inorder;

    for (auto it = charsTree.begin_inorder(); it != charsTree.end_inorder(); it++){
        inorder += to_string(*it);
    }

    CHECK(*(charsTree.begin_inorder()) == 'H');
    CHECK(*(charsTree.end_inorder()) == 'G');
    CHECK_EQ("HDIBEAFCJG",inorder);
}

TEST_CASE("Postorder"){
    BinaryTree<char> charsTree;

    charsTree.add_root ('A');
    charsTree.add_left ('A','B');
    charsTree.add_right ('A','C');

    charsTree.add_left ('B','D');
    charsTree.add_right ('B','E');

    charsTree.add_left ('D','H');
    charsTree.add_right ('D','I');

    charsTree.add_left ('C','F');
    charsTree.add_right ('C','G');

    charsTree.add_left ('G','J');

    string postorder;

    for (auto it = charsTree.begin_postorder(); it != charsTree.end_postorder(); it++){
        postorder += to_string(*it);
    }
    CHECK(*(charsTree.begin_postorder()) == 'H');
    CHECK(*(charsTree.end_postorder()) == 'A');
    CHECK_EQ("HIDEBFJGCA",postorder);
}

TEST_CASE("Preorder / Inorder / Postorder") {
    BinaryTree<char> charsTree;

    charsTree.add_root ('A');
    charsTree.add_left ('A','B');
    charsTree.add_right ('A','C');

    charsTree.add_left ('B','D');
    charsTree.add_right ('B','E');

    charsTree.add_left ('D','H');
    charsTree.add_right ('D','I');

    charsTree.add_left ('C','F');
    charsTree.add_right ('C','G');

    charsTree.add_left ('G','J');

    CHECK_NE(*(charsTree.begin_preorder()), *(charsTree.begin_inorder()));
    CHECK_NE(*(charsTree.begin_preorder()), *(charsTree.begin_postorder()));
    CHECK_EQ(*(charsTree.begin_inorder()), *(charsTree.begin_postorder()));

    CHECK_NE(*(charsTree.end_preorder()), *(charsTree.end_inorder()));
    CHECK_NE(*(charsTree.end_preorder()), *(charsTree.end_postorder()));
    CHECK_NE(*(charsTree.end_inorder()), *(charsTree.end_postorder()));
}
