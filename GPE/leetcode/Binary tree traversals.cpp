// C++ program to print postorder traversal from preorder and inorder traversals 
#include <iostream> 
#include <vector>
using namespace std; 

vector<char> tree;

// A utility function to search x in arr[] of size n 
int search(char arr[], char x, int n) 
{ 
    for (int i = 0; i < n; i++) 
        if (arr[i] == x)
            return i;
    return -1; 
} 
  
// Prints postorder traversal from given inorder and preorder traversals 
void printPostOrder(char in[], char pre[], int n) 
{ 
    // The first element in pre[] is always root, search it 
    // in in[] to find left and right subtrees 
    int root = search(in, pre[0], n); 

    // If left subtree is not empty, print left subtree 
    if (root != 0) 
        printPostOrder(in, pre + 1, root); 
  
    // If right subtree is not empty, print right subtree 
    if (root != n - 1) 
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1); 
  
    tree.push_back(pre[0]);
} 
  
// Driver program to test above functions 
int main() 
{ 
    int cases;
    cin >> cases;

    int n;
    while (cases--) {

        cin >> n;
        char * pre = new char [n+1];
        char * in = new char [n+1];

        for (int i=0; i<n; i++) {
            cin >> pre[i];
        }
        for (int i=0; i<n; i++) {
            cin >> in[i];
        }

        printPostOrder(in, pre, n); 
        
        vector<char>::iterator ite;
        for(ite = tree.begin(); ite!=tree.end(); ite++) {
            cout << *ite;
            if (ite!=tree.end()-1) {
                cout << " ";
            }
        }
        cout << endl;

        tree.clear();

        delete [] pre;
        delete [] in;
    }

    return 0; 
} 