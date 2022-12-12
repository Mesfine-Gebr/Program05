#include "BSTree.h"

#include <iostream>
#include <stdlib.h>

BSTree::BSTree()
{
    root = NULL;
    size = 0;
}

BSTree::~BSTree()
{
    CleanUp();
}

bool BSTree::Insert(Account &account)
{
    if (IsEmpty)
    {
        root = new Node;
        root->p_acct = account;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        Node *curr = root;
        while (size_)
        {
            if (curr->p_acct > account)
            {
                if (!curr->left)
                {
                    curr->left = new Node;
                    curr = curr->left;
                    curr->p_acct = account;
                    curr->left = NULL;
                    curr->right = NULL;
                    curr = nullptr;
                    size_++;
                    return true;
                }
                else
                curr = curr->left;
            }
            else if(curr->p_acct < account)
            {
                if (!curr->right)
                {
                    curr->right = new Node;
                    curr = curr->right;
                    curr->p_acct = account;
                    curr->left = NULL;
                    curr-right = NULL;
                    curr = nullptr;
                    size_++;
                    return true;
                }
                else curr = curr->right;
            }
            else
            {
                curr = nullptr;
                return false;
            }   //  end if/else if/else
        }   //  end while (size_)
    }   //  end if/else
}

bool BSTree::Retrieve(const int& account_id, Account*& account) const
{
    Node *curr = root;
    while (size_)
    {
        if (curr->p_acct.getUserAccountID() > account_id && curr->left)
        curr = curr->left;
        else if (curr->p_acct.getUserAccountID() < account_id && curr->right)
        curr = curr->right;
        else if (curr->p_acct.getUserAccountID() == account_id)
        {
            account = curr;
            curr = nullptr;
            return true;
        }
        else
        {
            curr = nullptr;
            return false;
        }   //  end if/else if/else
    }   //  end while (size_)
}

void BStree::CleanUp()
{
    DeleteNode(root);
}

void BSTree::Display()
{
    DisplayRecursively(root);
}

bool BSTree::IsEmpty()
{
    return !root;
}

//  Helpers
void DisplayRecursively(Node* node) const
{
    if (node->left)
    DisplayRecursively(node->left);

    cout << node->p_acct;

    if (node->right)
    DisplayRecursively(node->right);
}

void BSTree::DeleteNode(Node* curr)
{
    if(curr->left)
    DeleteNode(curr->left);

    if (curr->right)
    DeleteNode(curr->right);

    delete curr->p_acct;
    curr->p_acct = nullptr;
    curr->left = nullptr;
    curr->right = nullptr;
    delete curr;
    curr = nullptr;
}