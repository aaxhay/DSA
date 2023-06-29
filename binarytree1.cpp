#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data for the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void LOT(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inorder1(node* root,int &count){
    if(root == NULL)
    return ;

    inorder1(root->left,count);

    if(root->left == NULL && root->right == NULL)
    count++;

    inorder1(root->right,count);


}

int countleafNodes(node* &root,int &count)
{

    inorder1(root,count);
    
    return count;
}

void buildFromLevelOrderTraversal(node *&root)
{
    queue<node *> q;
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter the data for the left of " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the data for the right of " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{

    node *root = NULL;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // buildFromLevelOrderTraversal(root);
    root = buildTree(root);

    // cout << "printing tree in the form of level order traversal" << endl;
    // LOT(root);
    int count = 0;
    int res = countleafNodes(root,count);
    cout << "number of lead nodes in the binary tree is " <<res<< endl;
    /*
        // root = buildTree(root);

        // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

        cout<<"Inorder Traversal"<<endl;
        inorder(root);

        cout<<"preorder Traversal"<<endl;
        preOrder(root);

        cout<<"postorder Traversal"<<endl;
        postOrder(root);

        // cout<<"printing tree in the form of level order traversal"<<endl;
        // LOT(root);
        */
}