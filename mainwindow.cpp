#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "input.h"
#include <string.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetError(char *Text)
{
    ui->errorInfo->setText(Text);
}


void MainWindow::ShowText(char *Text)
{
    ui->textBrowser->setText(Text);
}

bool MainWindow::IsClearText()
{
    return ClearedText;
}

void MainWindow::on_GetButton_clicked()
{
    if(Text)
    {
        delete Text;
    }
    Text = GetText(*this);
    if(Text)
    {
        this->ShowText(Text);
    }
    ClearedText = false;
}


void MainWindow::on_ExitButton_clicked()
{
    this->close();
}

void MainWindow::on_SaveButton_clicked()
{
    if(ClearedRefine)
    {
        SetError("Нечего сохранять.\n Сперва обработайте текст");
    }
    else
    {
        SetError("");
        FILE *fout = fopen("output.txt", "w");
        if(fout)
        {
            ShowRefined(Refined, fout);
            SetError("Успешное сохранение");
        }
        else
        {
            SetError("Не удалось открыть файл.");
        }
        fclose(fout);
    }
}

void MainWindow::ShowRefined(Node *Refined, FILE *fout)
{
    char *text = NULL;
    while(Refined)
    {
        if(text)
        {
            short len = strlen(text) + strlen(Refined->Getlink()) + 2;
            char *tmp = new char[len];
            strcpy(tmp, text);
            strcat(tmp, Refined->Getlink());
            tmp[len - 2] = '\n';
            tmp[len - 1] = '\0';
            delete[] text;
            text = tmp;
        }
        else
        {
            text = new char[strlen(Refined->Getlink()) + 2];
            strcpy(text, Refined->Getlink());
            text[strlen(Refined->Getlink())] = '\n';
            text[strlen(Refined->Getlink()) + 1] = '\0';
        }
        Refined = Refined->next;
    }
    if(fout)
    {
        fprintf(fout, "%s", text);
    }
    else
    {
        ui->textBrowser_2->setText(text);
    }
    delete[] text;
}

void MainWindow::on_RefineButton_clicked()
{
    if(ClearedText)
    {
        SetError("Нечего преобразовывать.\n Сперва нужно получить текст");
    }
    else
    {
        SetError(Text);
        if(Refined)
        {
            delete Refined;
        }
        Refined = fref(Text);
        if(Refined)
        {
            SetError("");
            ShowRefined(Refined, NULL);
            ClearedRefine = false;
        }
        else
        {
            SetError("Обработанный текст не\nсодержит ссылок");
        }
    }
}
