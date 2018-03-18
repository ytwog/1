#ifndef NODE_H
#define NODE_H
#include <string.h>

class Node
{
public:
    Node();
    ~Node();
    Node *next;
    Node *prev;
    void Setlink(char *text);
    char *Getlink();
private:
    char *link;
};


bool str_Isnextequalto(char* first, char* second, int it);
bool Is_NodeFound(Node *first, char *text);

void Insert(Node **first, Node *prev, Node **end, char *text);

#endif // NODE_H


