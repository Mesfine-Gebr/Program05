#include "BSTree.h"

#include <iostream>
#include <stdlib.h>

BSTree::BSTree()
{
    root = NULL;
    size = 0;
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
                if (curr->left)
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
            else
            {
                if (curr->right)
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
            }   //  end if/else
        }   //  end while (size_)
    }   //  end if/else
}

bool BSTree::Retrieve()

bool BSTree::IsEmpty()
{
    return !root;
}