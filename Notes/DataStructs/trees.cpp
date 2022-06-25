#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    Node(int d, Node *l = NULL, Node *r = NULL) : data(d), left(l), right(r) {}
    int data;
    Node *left;
    Node *right;
};

class BinaryTree
{
public:
    BinaryTree()
    {
        root = NULL;
    };
    ~BinaryTree()
    {
        destroy_tree();
    };

    void insert(int key)
    {
        if (root == NULL)
        {
            root = new Node(key);
        }
        else
        {
            insert(key, root);
        }
    }
    Node *search(int key)
    {
        return search(key, root);
    }
    void destroy_tree()
    {
        destroy_tree(root);
    };

    void inOrderTraversal()
    {
        if (root != NULL)
        {
            inOrderTraversal(root);
        }
    }

    void levelOrderTraversal()
    {
        if (root != NULL)
        {
            levelOrderTraversal(root);
        }
    }

    void preOrderTraversal()
    {
        if (root != NULL)
        {
            preOrderTraversal(root);
        }
    }

    void postOrderTraversal()
    {
        if (root != NULL)
        {
            postOrderTraversal(root);
        }
    }
    void prePrintIterative()
    {
        if (root != NULL)
        {
            prePrintIterative(root);
        }
    }

private:
    void levelOrderTraversal(Node *leaf)
    {
        queue<Node *> q;
        q.push(leaf);
        while (!q.empty())
        {
            Node *next = q.front();
            q.pop();
            if (next != NULL)
            {
                cout << next->data << endl;
                q.push(next->left);
                q.push(next->right);
            }
        }
    }
    void prePrintIterative(Node *leaf)
    {
        stack<Node *> s;
        s.push(leaf);
        while (!s.empty())
        {
            Node *next = s.top();
            s.pop();
            if (next != NULL)
            {
                cout << next->data << endl;
                s.push(next->right); // Ensure that left sub-tree is processed first
                s.push(next->left);
            }
        }
    }
    void preOrderTraversal(Node *leaf)
    {
        if (leaf != NULL)
        {
            cout << leaf->data << endl;
            preOrderTraversal(leaf->left);
            preOrderTraversal(leaf->right);
        }
    }
    void postOrderTraversal(Node *leaf)
    {
        if (leaf != NULL)
        {
            postOrderTraversal(leaf->left);
            postOrderTraversal(leaf->right);
            cout << leaf->data << endl;
        }
    }
    void inOrderTraversal(Node *leaf)
    {
        if (leaf != NULL)
        {
            inOrderTraversal(leaf->left);
            cout << leaf->data << endl;
            inOrderTraversal(leaf->right);
        }
    }
    void destroy_tree(Node *leaf)
    {
        if (leaf != NULL)
        {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    };
    void insert(int key, Node *leaf)
    {
        if (key < leaf->data)
        {
            if (leaf->left == NULL)
            {
                leaf->left = new Node(key);
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
            else
            {
                insert(key, leaf->left);
            }
        }
        else if (key >= leaf->data)
        {
            if (leaf->right == NULL)
            {
                leaf->right = new Node(key);
                leaf->right->left = NULL;
                leaf->right->right = NULL;
            }
            else
            {
                insert(key, leaf->right);
            }
        }
    };
    Node *search(int key, Node *leaf)
    {
        if (key == leaf->data)
        {
            return leaf;
        }
        else if (key < leaf->data)
        {
            search(key, leaf->left);
        }
        else if (key > leaf->data)
        {
            search(key, leaf->right);
        }
        return NULL;
    }

    Node *root;
};

int main()
{
    BinaryTree binary;
    binary.insert(3);
    binary.insert(1);
    binary.insert(2);
    binary.insert(4);
    binary.insert(5);
    binary.inOrderTraversal();
    cout << "that was inOrder" << endl;
    binary.preOrderTraversal();
    cout << "that was preOrder" << endl;
    binary.postOrderTraversal();
    cout << "that was postOrder" << endl;
    binary.prePrintIterative();
    cout << "that was iterative preOrder" << endl;
    binary.levelOrderTraversal();
    cout << "that was levelOrder" << endl;
}