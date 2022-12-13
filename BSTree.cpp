#include "BSTree.h"
#include "Account.h"

#include <iostream>
#include <stdlib.h>

BSTree::BSTree()
{
    root_ = NULL;
    size_ = 0;
}

BSTree::~BSTree()
{
    CleanUp();
}

bool BSTree::Insert(Account* account)
{
    if (IsEmpty())
    {
        root_ = new Node;
        root_->p_acct = account;
        root_->left = NULL;
        root_->right = NULL;
        size_++;
        return true;
    }
    else
    {
        Node *curr = root_;
        while (!IsEmpty())
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
                    curr->right = NULL;
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
    return false;
}

bool BSTree::Retrieve(const int& account_id, Account*& account) const
{
    Node *curr = root_;
    while (!IsEmpty())
    {
        if (curr->p_acct->getUserAccountID() > account_id && curr->left)
        curr = curr->left;

        else if (curr->p_acct->getUserAccountID() < account_id && curr->right)
        curr = curr->right;
        else if (curr->p_acct->getUserAccountID() == account_id)
        {
            account = curr->p_acct;
            curr = nullptr;
            return true;
        }
        else
        {
            curr = nullptr;
            return false;
        }   //  end if/else if/else
    }   //  end while (size_)
    return false;
}

void BSTree::CleanUp()
{
    DeleteNode(root_);
}

void BSTree::Display() const
{
    DisplayRecursively(root_);
}

bool BSTree::IsEmpty() const
{
    return !root_;
}

//  Helpers
void BSTree::DisplayRecursively(Node* node) const
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