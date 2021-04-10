#include "binary_search_tree.h"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType>* rhs)
{
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType>& rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    // TODO 

    if(root == 0)
    {
        Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>; //temporary pointer
        newNode->key = key;
        newNode->data = item;
        root = newNode;
        return true;
    }
    Node<KeyType, ItemType>* curr = root;
    Node<KeyType, ItemType>* curr_parent = 0;;
    search(key, curr, curr_parent);
    if (curr->key == key) 
    {
        return false;
    }
    else if(key < curr->key)
    {
        //insert left child
        Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>; //temporary pointer
        newNode->key = key;
        newNode->data = item;
        curr->left = newNode;
        newNode->right = 0;
        return true;
    }
    else if(key > curr->key) //"curr->key" = last visited
    {
        //insert right child
        Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>; //temporary pointer
        newNode->key = key;
        newNode->data = item;
        curr->right = newNode;
        newNode->left = 0;
        return true;
    }
    return false;
  
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false; // empty tree
    
    Node<KeyType, ItemType>* curr = root;
    Node<KeyType, ItemType>* curr_parent = 0;;
    search(key, curr, curr_parent);

    // case one thing in the tree
    if(curr = nullptr)
    {
        return false;
    }
    // case, found deleted item at leaf
    if(curr->key != key)
    {
        return false;
    }
    // case, item to delete has only a right child
    else
    {
        if(curr->left == 0 && curr->right == 0)
        {
            if(curr != root)
            {
                if(curr_parent->left == curr)
                {
                    curr_parent->left = nullptr;
                }
                else
                {
                    curr_parent->right = nullptr;
                }
            }
            else
            {
                root = nullptr;
            }
            free(curr);
        }
        else if (curr->left && curr->right)  // case, item to delete has only a left child
        {
            Node<KeyType, ItemType>* in = new Node<KeyType, ItemType>;
            inorder(curr, in, curr_parent);
            curr->data = in->data;
            remove(in->key);
            return true;
        }
        else // case, item to delete has two children
        {
            Node<KeyType, ItemType>* child = curr->left ? curr->left:curr->right;
            if(curr!=root)
            {
                if(curr == curr_parent->left)
                {
                    curr_parent->left = child;
                }
                else
                {
                    curr_parent->right = child;
                }
            }
            else
            {
                root = child;
            }
            free(curr);
        }
        
        
    }
    return false; // default should never get here
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    curr = curr->right; // move right once
    while(curr->left != 0)
    {
        in = curr->left;   // move left as far as possible
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(ItemType arr[], int size) {
    // check for duplicate items in the input array
    for (int i = 0; i < size-1; i++)
    {
        for(int j = 1+j; j < size ; j++)
        {
            if(arr[i] == arr[j])
            {
                throw std::runtime_error("There are duplicate items in the input array.");
            }
        }
    }
    // use the tree to sort the array items
    for (int i = 0; i < size ; i++)
    {
        insert(arr[i], arr[i]);
    }
    // overwrite input array values with sorted values
    std::stack<Node<KeyType, ItemType>*> stack;
    Node<KeyType, ItemType>* curr = root;
    int i = 0;
    
    while(stack.empty() == false || curr != NULL)
    {
        while(curr != NULL)
        {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();
        arr[i] = curr->data;
        curr = curr->right;
        i++;
    }
}
