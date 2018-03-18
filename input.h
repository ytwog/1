#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include "mainwindow.h"
#include <string>
#include <QApplication>
#include <node.h>

char* Read(FILE *fin);
char* GetText(MainWindow& w);
Node* fref(char *Text);

#endif // INPUT_H
