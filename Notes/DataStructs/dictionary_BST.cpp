#include <iostream>
#include <string>

using namespace std;

template <typename K, typename D>
class Dictionary
{
public:
    Dictionary()
    {
        root = NULL;
    }
    ~Dictionary() {}
    D find(K k)
    {
        if (contains(root, k))
            return findReference(root, k)->Data;
        else
            return -1;
    }

    void listKeys()
    {
        listKeys(root);
    }
    void insert(K k, D d)
    {
        if (!contains(root, k))
            findReference(root, k) = new Node(k, d);
        else
            return;
    }

    void remove(K k)
    {
        if (contains(root, k))
            remove(root, k);
        else
            return;
    }

private:
    struct Node
    {
        K Key;
        D Data;
        Node *left, *right;
        Node(K k, D d) : Key(k), Data(d), left(nullptr), right(nullptr) {}
    };
    Node *root;

    void remove(Node *&root, K k)
    {
        if (contains(root, k))
        {
            Node *handle = findReference(root, k); // Identify node to be deleted
            if (handle == NULL)
                return;                // node is already NULL, do nothing and return;
            Node *toDelete = handle;   // Assign pointer to node that is being deleted
            if (handle->right == NULL) // no right children
            {
                handle = handle->left;
            }
            else if (handle->left == NULL) // no left children
            {
                handle = handle->right;
            }
            else
            {
                Node *&succ = findMin(handle->right); // Find min of right child
                handle = succ;                        // Replace deleted node with successor
                succ = succ->right;                   // Successor's right child is in successor's place
                handle->left = toDelete->left;        // set new successor's left child to deleted node's left children
                handle->right = toDelete->right;      // set new successor's right child to deleted node's right children
            }
            delete toDelete; // Delete identified node;
        }
        return;
    }

    Node *&findMax(Node *&root)
    {
        if (root->right == NULL)
        {
            return root;
        }
        else
        {
            return findMax(root->right);
        }
    }

    Node *&findMin(Node *&root)
    {
        if (root->left == NULL)
        {
            return root;
        }
        else
        {
            return findMin(root->left);
        }
    }

    bool contains(Node *root, K key)
    {
        if (root == NULL)
            return false;
        if (root->Key == key)
            return true;
        if (key < root->Key)
            return contains(root->left, key);
        else
            return contains(root->right, key);
    }
    void listKeys(Node *root)
    {
        if (root != NULL)
        {
            listKeys(root->left);
            cout << root->Key << endl;
            listKeys(root->right);
        }
    }

    Node *&findReference(Node *&ref, K k)
    {
        if (ref == NULL)
            return ref;
        if (ref->Key == k)
            return ref;
        if (k < ref->Key)
        {
            return findReference(ref->left, k);
        }
        else
        {
            return findReference(ref->right, k);
        }
    }
};

int main()
{
    Dictionary<string, int> d;
    d.insert("grade", 90);
    d.insert("grade 1", 85);
    d.listKeys();
    d.remove("grade");
    d.listKeys();
}