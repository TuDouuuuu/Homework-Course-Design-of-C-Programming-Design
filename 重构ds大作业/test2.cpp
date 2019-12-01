#include <iostream>
#include <string>
using namespace std;
 
struct node
{
    int value;
    node* left;
    node* right;
 
    node(int v)
        : value(v)
        , left(0)
        , right(0)
    { }
 
    ~node()
    {
        delete left;
        delete right;
    }
};
 
node* create()
{
    node* root = 0;
    for (int n; cin >> n;)
    {
        node** parent = &root;
        node* cur = root;
        while (cur)
        {
            if (n < cur->value)
            {
                parent = &cur->left;
                cur = cur->left;
            }
            else
            {
                parent = &cur->right;
                cur = cur->right;
            }
        }
 
        *parent = new node(n);
    }
    return root;
}
 
void destroy(node* root)
{
    delete root;
}
 
void output_impl(node* n, bool left, string const& indent){
    if (n->right){
        output_impl(n->right, false, indent + (left ? "|      " : "       "));
    }
    cout << indent;
    cout << (left ? '\\' : '/');
    cout << "-----";
    cout << n->value << endl;
    if (n->left)
    {
        output_impl(n->left, true, indent + (left ? "       " : "|      "));
    }
}
 
void output(node* root){
    if (root->right){
        output_impl(root->right, false, " ");
    }
    cout << root->value << endl;
    if (root->left){
        output_impl(root->left, true, " ");
    }
}
 
int main()
{
    node* root = create();
    output(root);
    destroy(root);
}