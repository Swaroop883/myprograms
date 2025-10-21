#include <sstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Node structure for AVL tree
struct Node {
    int val;
    Node* left;
    Node* right;
    int height;
    int size;
    Node(int v) {
        val = v;
        left = right = NULL;
        height = 1;
        size = 1;
    }
};

int getHeight(Node* n) { return n ? n->height : 0; }
int getSize(Node* n) { return n ? n->size : 0; }
void update(Node* n) {
    if (n) {
        n->height = 1 + max(getHeight(n->left), getHeight(n->right));
        n->size = 1 + getSize(n->left) + getSize(n->right);
    }
}
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    update(y);
    update(x);
    return x;
}
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    update(x);
    update(y);
    return y;
}
int getBalance(Node* n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    update(root);
    int balance = getBalance(root);
    if (balance > 1 && val < root->left->val) return rotateRight(root);
    if (balance < -1 && val > root->right->val) return rotateLeft(root);
    if (balance > 1 && val > root->left->val) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && val < root->right->val) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}
int kth(Node* root, int k) {
    int leftSize = getSize(root->left);
    if (k == leftSize + 1) return root->val;
    if (k <= leftSize) return kth(root->left, k);
    return kth(root->right, k - leftSize - 1);
}

// MedianFinder
class MedianFinder {
    Node* root;
    int count;
public:
    MedianFinder() { root = NULL; count = 0; }
    void addNum(int num) {
        root = insert(root, num);
        count++;
    }
    double findMedian() {
        if (count % 2 == 1) {
            return kth(root, count / 2 + 1);
        } else {
            int a = kth(root, count / 2);
            int b = kth(root, count / 2 + 1);
            return (a + b) / 2.0;
        }
    }
};

// ---- NEW MAIN ----
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);

    vector<vector<int>> vals;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '[') {
            vector<int> v;
            string num = "";
            i++;
            while (i < line.size() && line[i] != ']') {
                if (isdigit(line[i]) || line[i] == '-') {
                    num += line[i];
                } else {
                    if (!num.empty()) {
                        v.push_back(stoi(num));
                        num.clear();
                    }
                }
                i++;
            }
            if (!num.empty()) {
                v.push_back(stoi(num));
            }
            vals.push_back(v);
        }
    }

    MedianFinder mf;
    vector<string> res;

    for (auto &v : vals) {
        if (v.empty()) {
            ostringstream oss;
            oss << fixed << setprecision(5) << mf.findMedian();
            string out = oss.str();
            while (out.size() > 1 && out.back() == '0') out.pop_back();
            if (out.back() == '.') out.push_back('0');
            res.push_back(out);
        } else {
            mf.addNum(v[0]);
            res.push_back("null");
        }
    }

    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        if (i) cout << ",";
        cout << res[i];
    }
    cout << "]\n";
}
