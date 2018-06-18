#include "addbook.h"
#include "ui_addbook.h"
#include <QMessageBox>
#include <QSqlDatabase>

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
    msgBox.setInformativeText("Here you must make request to database");
    msgBox.setIcon(QMessageBox::Information);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("library");
    db.setUserName("root");
    db.setPassword("robertheinlein1993");
    bool isOpen = db.open();
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
    this->close();
}
