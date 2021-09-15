/*
Binary search tree from pre-order using STL stack
*/

#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class BST {
private:
    Node* root;
public:
    BST() {
        root = nullptr;
    }
    Node* getRoot() {
        return root;
    }
    void iInsert(int key);
    void inorder(Node* p);
    Node* iSearch(int key);
    Node* rInsert(Node* p,int key);
    Node* rSearch(Node* p,int key);
    Node* deleteIt(Node* p,int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* inorderSuccessor(Node* p);
    void createFromPreorder(int pre[],int n);
};

void BST::iInsert(int key) {
    Node* t = root;
    Node* p;
    Node* r;

    // root is empty
    if (root == nullptr) {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while (t != nullptr) {
        r = t;
        if (key < t->data) {
            t = t->lchild;
        }
        else if (key > t->data) {
            t = t->rchild;
        }
        else {
            return;
        }
    }

    // t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data) {
        r->lchild = p;
    }
    else {
        r->rchild = p;
    }

}

void BST::inorder(Node* p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << ", " << flush;
        inorder(p->rchild);
    }
}

Node* BST::iSearch(int key) {
    Node* t = root;
    while (t != nullptr) {
        if (key == t->data) {
            return t;
        }
        else if (key < t->data) {
            t = t->lchild;
        }
        else {
            t = t->rchild;
        }
    }
    return nullptr;
}

Node* BST::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr) {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }

    if (key < p->data) {
        p->lchild = rInsert(p->lchild,key);
    }
    else if (key > p->data) {
        p->rchild = rInsert(p->rchild,key);
    }
    return p;  // key == p->data?
}

Node* BST::rSearch(Node *p, int key) {
    if (p == nullptr) {
        return nullptr;
    }

    if (key == p->data) {
        return p;
    }
    else if (key < p->data) {
        return rSearch(p->lchild,key);
    }
    else {
        return rSearch(p->rchild,key);
    }
}

Node* BST::deleteIt(Node *p,int key) {
    Node* q;

    if (p == nullptr) {
        return nullptr;
    }

    if (p->lchild == nullptr && p->rchild == nullptr) {
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if (key < p->data) {
        p->lchild = deleteIt(p->lchild,key);
    }
    else if (key > p->data) {
        p->rchild = deleteIt(p->rchild,key);
    }
    else {
        if (Height(p->lchild) > Height(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = deleteIt(p->lchild,q->data);
        }
        else {
            q = inorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = deleteIt(p->rchild,q->data);
        }
    }
    return p;
}

int BST::Height(Node *p) {
    int x;
    int y;
    if (p == nullptr) {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

Node* BST::InPre(Node *p) {
    while (p && p->rchild != nullptr) {
        p = p->rchild;
    }
    return p;
}

Node* BST::inorderSuccessor(Node *p) {
    while (p && p->lchild != nullptr) {
        p = p->lchild;
    }
    return p;
}

void BST::createFromPreorder(int *pre,int n) {
    // create root node
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = nullptr;
    root->rchild = nullptr;\
    // iterative steps
    Node* t;
    Node* p = root;
    stack<Node*> stk;

    while (i < n) {
        // left child case
        if (pre[i] < p->data) {
            t = new Node;
            t->data = pre[i++];
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else {
            // right child cases
            if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data) {
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                p = t;
            }
            else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

int main() {
    BST bst;
    // iterative insert
    bst.iInsert(15);
    bst.iInsert(4);
    bst.iInsert(27);
    bst.iInsert(93);
    bst.iInsert(44);
    bst.iInsert(313);

    // inorder traversal
    bst.inorder(bst.getRoot());
    cout << endl;

    // iterative search
    Node* temp = bst.iSearch(27);
    if (temp != nullptr) {
        cout << "element found: " << temp->data << endl;
    } else {
        cout << "element not found: 27" << endl;
    }

    // recursive search
    temp = bst.rSearch(bst.getRoot(),115);
    if (temp != nullptr) {
        cout << "element found: " << temp->data << endl;
    } else {
        cout << "element not found: 115" << endl;
    }

    // recursive insert
    bst.rInsert(bst.getRoot(),22);
    bst.rInsert(bst.getRoot(),99);
    bst.rInsert(bst.getRoot(),124);
    bst.rInsert(bst.getRoot(),47);
    bst.inorder(bst.getRoot());
    cout << "\n" << endl;

    // inorder predecessor and inorder successor
    BST bs;
    bs.iInsert(55);
    bs.iInsert(11);
    bs.iInsert(27);
    bs.iInsert(82);
    bs.iInsert(921);
    bs.iInsert(1411);

    temp = bs.InPre(bs.getRoot());
    cout << "inorder predecessor: " << temp->data << endl;

    temp = bs.inorderSuccessor(bs.getRoot());
    cout << "inorder successor: " << temp->data << endl;

    bs.inorder(bs.getRoot());
    cout << endl;

    // delete
    bs.deleteIt(bs.getRoot(),5);
    bs.inorder(bs.getRoot());
    cout << endl;

    // binary search tree from pre-order traversal
    cout << "binary search tree from pre-order traversal: " << flush;
    int pre[] = {331,204,111,911,444,761,121,821,119};
    int n = sizeof(pre) / sizeof(pre[0]);

    BST b;
    b.createFromPreorder(pre,n);
    b.inorder(b.getRoot());
    cout << endl;

    return 0;
}
