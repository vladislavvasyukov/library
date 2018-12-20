#include "add_book.h"
#include "ui_add_book.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "QDebug"

AddBook::AddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::on_add_book_in_library_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Information");
    msgBox.setInformativeText("Вы добавили книгу в библиотеку.");
    msgBox.setIcon(QMessageBox::Information);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\my_projects\\library.db");
    bool isOpen = db.open();
    qDebug() << 'This is adding book';

    QSqlQuery query;
    query.prepare("INSERT INTO books (author, title, isbn, genre, create_date)"
             "VALUES (:author, :title, :isbn, :genre, :create_date)");
    query.bindValue(":author", ui->author->text());
    query.bindValue(":title", ui->title->text());
    query.bindValue(":isbn", ui->isbn->text());
    query.bindValue(":genre", ui->genre->text());
    query.bindValue(":create_date", ui->create_date->text());
    query.exec();

    if (isOpen){
        int res = msgBox.exec();
        if (res == QMessageBox::Ok){
            this->close();
        }
    } else {
        this->close();
    }
}


void AddBook::on_cancel_additing_book_clicked()
{
    qDebug() << "Youpush cancel button v2.0";
    this->close();
}
