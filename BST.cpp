#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    int value;
    Node* left;
    Node* right;
};
class BST {
    Node* root;
public:
    BST() {
        this->root = nullptr;
    }
    // Function to help insert function
    void insert(int val) {
        Node* newnode = new Node();
        newnode->left = nullptr;
        newnode->right = nullptr;
        newnode->value = val;
        if (root == nullptr)
            root = newnode;
        else
            helpInsert(root, val);
    }

    // Function to help Insert Function
    void helpInsert(Node* temp, int val) {
        if (val > temp->value) {
            if (temp->right != nullptr) {
                helpInsert(temp->right, val);
            }
            else {
                Node* newnode = new Node();
                newnode->left = nullptr;
                newnode->right = nullptr;
                newnode->value = val;
                temp->right = newnode;
            }
        }
        else {
            if (temp->left != nullptr) {
                helpInsert(temp->left, val);
            }
            else {
                Node* newnode = new Node();
                newnode->left = nullptr;
                newnode->right = nullptr;
                newnode->value = val;
                temp->left = newnode;
            }
        }
    }

    // Function to get the min number
    int getMin() {
        return getMinHelp(root);
    }
    // Funcrion to help getMin Function
    int getMinHelp(Node* temp) {
        if (temp->left != nullptr) {
            return getMinHelp(temp->left);
        }
        else
            return temp->value;
    }

    // Function to get the Max number
    int getMax() {
        return getMaxHelp(root);
    }
    // Funcrion to help getMax Function
    int getMaxHelp(Node* temp) {
        if (temp->right != nullptr) {
            getMaxHelp(temp->right);
        }
        else
            return temp->value;
    }

    // this function to apply BFS on this Tree
    void BFS() {
        if (root == nullptr) {
            return;
        }
        queue<Node*>q;
        Node* Temp;
        q.push(root);
        while (!q.empty()) {
            Temp = q.front();
            cout << Temp->value << " ";
            if (Temp->left != nullptr)
                q.push(Temp->left);
            if (Temp->right != nullptr)
                q.push(Temp->right);
            q.pop();
        }
    }
    // This Function to apply Preorder (DFS)
    void PreOrder() {
        if (root == nullptr) {
            return;
        }
        hPreOrder(root);
    }
    // This Function to help PreOrder Function
    void hPreOrder(Node* Temp) {
        if (Temp == nullptr) {
            return;
        }
        cout << Temp->value << " ";
        hPreOrder(Temp->left);
        hPreOrder(Temp->right);
    }
    
    // This Function to apply InOrder (DFS)
    void InOreder() {
        if (root == nullptr)
            return;
        hInorder(root);
    }
    // This Function to help InOrder Function
    void hInorder(Node* temp) {
        if (temp == nullptr)
            return;
        hInorder(temp->left);
        cout << temp->value << " ";
        hInorder(temp->right);
    }
    // This Function to apply PostOrder
    void PostOrder() {
        if (root == nullptr)
            return;
        hPostOrder(root);
    }
    // This Function to help PostOrder Function
    void hPostOrder(Node* temp) {
        if (temp == nullptr)
            return;
        hPostOrder(temp->left);
        hPostOrder(temp->right);
        cout << temp->value << " ";
    }
    // This Function to search in BST 
    void search(int val) {
        Node* temp = root;
        while (temp) {
            if (temp->value == val) {
                cout << "I found it";
                break;
            }
            else if (val > temp->value) {
                temp = temp->right;
            }
            else if (val < temp->value) {
                temp = temp->left;
            }
        }
    }

};
int main() {
    BST bst;
    bst.insert(25);
    bst.insert(15);
    bst.insert(10);
    bst.insert(4);
    bst.insert(12);
    bst.insert(22);
    bst.insert(18);
    bst.insert(24); 
    
    cout << "The Max element = " << bst.getMax();
    cout << endl << endl;

    
    cout << "The minimum element = " << bst.getMin();
    cout << endl << endl;

    
    cout << "BFS -> ";
    bst.BFS();
    cout << endl << endl;

    cout << "Preorder -> ";
    bst.PreOrder();
    cout << endl<<endl;

    cout << "Inorder -> ";
    bst.InOreder();
    cout << endl << endl;

    cout << "Postorder-> ";
    bst.PostOrder();
    cout << endl << endl;

    bst.search(22);
    return 0;
}
