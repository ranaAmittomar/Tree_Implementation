// Tree_Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;


/*
class Node { //using the pointers
public:

    Node* left, * right;
    int data;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//Implementing a regular tree using dynamic arrays
void addEdge(int x, int y, vector<vector<int>>& adj) { //function to add EDGE between nodes(basically two way node..)
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void printParent(int node, vector<vector<int>>& adj, int parent) { //function to print the parent of each node..
    //current node is root..
    if (parent == 0)
        cout << node << "->Root" << endl;
    else
        cout << node << "->" << parent << endl;

    //using DFS
    for (auto cur : adj[node]) {
        if (cur != parent) {
            printParent(cur, adj, node);
        }
    }
}
void printChildren(int Root, vector<vector<int>>& adj) {
    queue<int>q;
    q.push(Root);

    int visitedArray[adj.size()] = { 0 };
    //BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visitedArray[node] = 1;
        cout << node << "->";
        for (auto cur : adj[node]) {
            if (visitedArray[cur] == 0) {
                cout << cur << " ";
                q.push(cur);
            }
        }
        cout << endl;
    }
}
// Function to print the leaf nodes
void printLeafNodes(int Root, vector<vector<int> >& adj)
{
    // Leaf nodes have only one edge and are not the root
    for (int i = 1; i < adj.size(); i++)
        if (adj[i].size() == 1 && i != Root)
            cout << i << " ";
    cout << endl;

}
void printDegrees(int Root, vector<vector<int> >& adj)
{
    for (int i = 1; i < adj.size(); i++) {
        cout << i << ": ";
        // Root has no parent, thus, its degree is equal to
        // the edges it is connected to
        if (i == Root)
            cout << adj[i].size() << endl;
        else
            cout << adj[i].size() - 1 << endl;
    }
}

*/

//CREATING TREE USING STRUCT METHOD

struct Node {
    int data;
    struct Node* left, * right;
};

Node* newNode(int data) //utility func to create a new Tree Node.
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printInOrder(struct Node* node) {
    if (node == NULL)
        return;

    printInOrder(node->left); //recursion to left child
    cout << node->data << " "; //print data of node
    printInOrder(node->right);//recursion to right child
}

void printPreOrder(struct Node* node) {
    if (node == NULL)
        return;
    //first print data of node...
    cout << node->data << " ";
    //recursion call for left subtree;
    printPreOrder(node->left);
    //recursion call for righ subtree;
    printPreOrder(node->right);
}

void printPostOrder(struct Node* node) {
    if (node == NULL)
        return;
    //first left subtree recursion call
    printPostOrder(node->left);
    //now right subtree recursion call
    printPostOrder(node->right);
    //now print the data of the node
    cout << node->data << " ";
}

int heightOfNode(struct Node* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int left_side;
        int right_side;
        left_side = heightOfNode(root->left);
        right_side = heightOfNode(root->right);
        if (left_side > right_side)
        {
            return left_side + 1;

        }
        else
            return right_side + 1;
    }
}


int main()
{

    /*
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    cout << root->left->data << " ";
    cout << root->left->left->data << " ";
    cout << root->right->data << " ";
    */
    // Number of nodes
    /*
  int N = 7, Root = 1;
    // Adjacency list to store the tree
    vector<vector<int> > adj(N + 1, vector<int>());
    // Creating the tree
    addEdge(1, 2, adj);
    addEdge(1, 3, adj);
    addEdge(1, 4, adj);
    addEdge(2, 5, adj);
    addEdge(2, 6, adj);
    addEdge(4, 7, adj);
    // Printing the parents of each node
    cout << "The parents of each node are:" << endl;
    printParent(Root, adj, 0);

    // Printing the children of each node
    cout << "The children of each node are:" << endl;
    printChildren(Root, adj);

    // Printing the leaf nodes in the tree
    cout << "The leaf nodes of the tree are:" << endl;
    printLeafNodes(Root, adj);

    // Printing the degrees of each node
    cout << "The degrees of each node are:" << endl;
    printDegrees(Root, adj);
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    // Function call
    cout << "Inorder traversal of binary tree is :  ";

    printInOrder(root);
    cout << endl;
    cout << endl;
    cout << "PreOrder traversal of binary tree is :  ";
    printPreOrder(root);
    cout << endl;
    cout << endl;
    cout << "Post traversal of binary tree is :  ";
    printPostOrder(root);
    cout << endl;
    cout << endl;
    cout<<"Height of the tree from the deepest node : " << heightOfNode(root);
    cout << endl;

   

    return 0;
}

