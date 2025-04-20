
 
#include <iostream> 
#include <cstring> 
#include <cctype> 
using namespace std; 
 
struct Node { 
    char data; 
    Node *le , *right; 
    Node(char val) : data(val), le (nullptr), right(nullptr) {} 
}; 
 
class Tree { 
public: 
    Node *root; 
    Tree() : root(nullptr) {} 
 
    void buildExpressionTree(const char *prefix) { 
        Node *stack[50]; 
        int top = -1; 
 
        for (int i = strlen(prefix) - 1; i >= 0; i--) { 
            if (isalpha(prefix[i])) { 
                stack[++top] = new Node(prefix[i]); 
            } else { 
                Node *node = new Node(prefix[i]); 
                node->le = stack[top--]; 
                node->right = stack[top--]; 
                stack[++top] = node; 
            } 
        } 
        root = stack[top]; 
    } 
 
    void displayPostfix(Node *node) { 
        if (!node) return; 
        displayPostfix(node->le ); 
        displayPostfix(node->right); 
        cout << node->data; 
    } 
 
    void deleteTree(Node *node) { 
        if (!node) return; 
        deleteTree(node->le ); 
        deleteTree(node->right); 
        cout << "Deleing node: " << node->data << endl; 
        delete node; 
    } 
}; 
 
int main() { 
    Tree tree; 
    char expression[50]; 
    int choice; 
 
    do { 
        cout << "1 -> Enter prefix expression\n"; 
        cout << "2 -> Display pos ix expression\n"; 
        cout << "3 -> Delete tree\n"; 
        cout << "4 -> Exit\n"; 
        cout << "Choose an op on (1-4): "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter the prefix expression (e.g., +--a*bc/def): "; 
                cin >> expression; 
                tree.buildExpressionTree(expression); 
                break; 
            case 2: 
                if (tree.root) { 
                    tree.displayPostfix(tree.root); 
                    cout << endl; 
                } else { 
                    cout << "Tree is empty.\n"; 
                } 
                break; 
            case 3: 
                if (tree.root) { 
                    tree.deleteTree(tree.root); 
                    tree.root = nullptr; 
                } else { 
                    cout << "Tree is already empty.\n"; 
                } 
                break; 
            case 4: 
                cout << "\n// END OF CODE\n"; 
                break; 
            default: 
                cout << "Choose a valid op on (1-4).\n"; 
        } 
    } while (choice != 4); 
 
    return 0; 
} 
 
 