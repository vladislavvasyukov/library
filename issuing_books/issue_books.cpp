#include "issue_books.h"
#include "ui_issuedbooks.h"

IssuedBooks::IssuedBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IssuedBooks)
{
    ui->setupUi(this);
}

IssuedBooks::~IssuedBooks()
{
    delete ui;
}
