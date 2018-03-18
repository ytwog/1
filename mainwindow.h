#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "node.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void SetError(char*);
    void ShowText(char*);
    void ShowRefined(Node *Refined, FILE *fout);
    bool IsClearText();
private slots:

    void on_GetButton_clicked();

    void on_ExitButton_clicked();

    void on_SaveButton_clicked();

    void on_RefineButton_clicked();

private:
    bool ClearedText = true;
    bool ClearedRefine = true;
    char *Text = NULL;
    Node *Refined = NULL;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
