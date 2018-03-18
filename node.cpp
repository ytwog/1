#include "node.h"

Node::Node()
{
    next = NULL;
    prev = NULL;
    link = NULL;
}


Node::~Node()
{
    delete[] link;
}

void Node::Setlink(char *text)
{
    char *tnew = new char[strlen(text) + 1];
    strcpy(tnew, text);
    link = tnew;
}

bool str_Isnextequalto(char* first, char* second, int it)
{
    if(strlen(first) < strlen(second))
    {
        return false;
    }
    for(int i = 0; i < strlen(second); i++)
    {
        if(it == strlen(first))
        {
            return false;
        }
        if(first[it] != second[i])
        {
            return false;
        }
        it++;
    }
    return true;
}


char *Node::Getlink()
{
    return link;
}

bool Is_NodeFound(Node *first, char *text)
{
    while(first)
    {
        if(str_Isnextequalto(first->Getlink(),text, 0))
        {
            return true;
        }
        first = first->next;
    }
    return false;
}

void Insert(Node **first, Node *prev, Node **end, char *text)
{
    Node *obj = NULL;
    if(prev == NULL)
    {
        obj = new Node();
        obj->Setlink(text);
        *first = obj;
        *end = obj;
        return;
    }
    else
    {
        if(Is_NodeFound(*first, text))
        {
            return;
        }
        else
        {
            obj = new Node();
            prev->next = obj;
            obj->prev = prev;
            obj->Setlink(text);
            if(*end == prev)
            {
                *end = obj;
            }
        }
    }
}
