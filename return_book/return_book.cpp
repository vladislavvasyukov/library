#include "return_book.h"
#include "ui_return_book.h"

returnBook::returnBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnBook)
{
    ui->setupUi(this);
}

returnBook::~returnBook()
{
    delete ui;
}

void returnBook::on_pushButton_2_clicked()
{
    this->close();
}
