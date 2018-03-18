#include "input.h"

using namespace std;



Node *fref(char *Text)
{
    char *form1 = "http://";
    char *form2 = "https://";
    char *form3 = "ftp://";
    char *toAdd = NULL;
    char WTF;
    Node *first = NULL;
    Node *end = NULL;
    int adding = -1;// -1 -> don't ; 0 -> seeking for space; 1+ -> adding pre symbols
    for(int i = 0; i < strlen(Text); i++)
    {
        WTF = Text[i];
        if((((Text[i] == ' ') || (Text[i] == '\n')) && (adding != -1)) || ((adding >= 0) && (i + 1 == strlen(Text))))
        {
            Insert(&first, end, &end, toAdd);
            delete[] toAdd;
            toAdd = NULL;
            adding = -1;
            continue;
        }
        if(adding == -1)
        {   if(str_Isnextequalto(Text, form1, i))
            {
                adding = 7;
            }
            else if(str_Isnextequalto(Text, form2, i))
            {
                adding = 8;
            }
            else if(str_Isnextequalto(Text, form3, i))
            {
                adding = 6;
            }
        }
        if(adding != -1)
        {
            if(toAdd)
            {
                char *tmp = new char[strlen(toAdd) + 2];
                strcpy(tmp, toAdd);
                tmp[strlen(toAdd)] = Text[i];
                tmp[strlen(toAdd) + 1] = '\0';
                delete[] toAdd;
                toAdd = tmp;
            }
            else
            {
                toAdd = new char[2];
                toAdd[0] = Text[i];
                toAdd[1] = '\0';
            }
        }
    }
    return first;
}

char* Read(FILE* fin)
{
    char* text = NULL;
    char ch;

    fscanf(fin, "%c %c %c %c", &ch, &ch, &ch, &ch);
    while(!feof(fin))
    {
        if(text)
        {
            char* tmp = new char[strlen(text) + 2];
            for(unsigned int i = 0; i < strlen(text); i++)
            {
                tmp[i] = text[i];
            }
            tmp[strlen(text)] = ch;
            tmp[strlen(text) + 1] = '\0';
            delete[] text;
            text = tmp;
        }
        else
        {
            text = new char[2];
            text[0] = ch;
            text[1] = '\0';
        }
        fscanf(fin, "%c", &ch);
    }

    return text;
}

char* GetText(MainWindow &w)
{
    char* text = NULL;
    w.SetError("");
    FILE* fin = fopen("input.txt", "r");
    if(!fin)
    {
        w.SetError("Возникла ошибка\nсо считыванием\nтекста");
    }
    else
    {
        text = Read(fin);

    }
    fclose(fin);
    return text;
}
