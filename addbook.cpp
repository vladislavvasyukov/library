#include "addbook.h"
#include "ui_addbook.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

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
    QDebug() << "Start working window";
    QMessageBox msgBox;
    msgBox.setText("Information");
    msgBox.setInformativeText("Here you must make request to database");
    msgBox.setIcon(QMessageBox::Information);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\my_projects\library.db");
    bool isOpen = db.open();
    QSqlQuery query;
    query.exec("select id, lname from readers");
    QString message = "";
    while (query.next()){
        message += query.value(0).toString();
        message += query.value(1).toString();
        ui->textEdit->insertPlainText(message+"\n");
    }


    if (isOpen){
        int res = msgBox.exec();
        if (res == QMessageBox::Ok){
            QDebug() << "End working window";
            this->close();
        }
    } else {
        QDebug() << "End working window";
        this->close();
    }
}


void AddBook::on_cancel_additing_book_clicked()
{
    this->close();
}
