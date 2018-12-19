#include "return_book.h"
#include "ui_return_book.h"
#include <QSqlQueryModel>
#include "QSqlQuery"
#include <QDebug>

returnBook::returnBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnBook)
{
    ui->setupUi(this);
    QStringList headersIssuedBooks = {"Автор", "Название", "Имя", "Фамилия", "Дата выдачи", "Дата возврата"};

    QSqlQueryModel *compModel = new QSqlQueryModel();

    compModel->setQuery("SELECT DISTINCT b.id, b.author, b.title, r.firstname, r.lastname, i.issued_date, i.return_date "
                        "FROM books b INNER JOIN issued_books i "
                        "ON b.id = i.book_id "
                        "INNER JOIN readers r "
                        "ON r.id = i.reader_id");

    for (int i = 1; i < compModel->columnCount(); i++) {
        compModel->setHeaderData(i, Qt::Horizontal, headersIssuedBooks[i-1]);
    }
    ui->tableView->setModel(0);
    ui->tableView->setModel(compModel);
    ui->tableView->setColumnHidden(0, true);
}

returnBook::~returnBook()
{
    delete ui;
}

void returnBook::on_pushButton_2_clicked()
{
    this->close();
}
void returnBook::on_pushButton_clicked()
{
    QModelIndex book  = ui->tableView->currentIndex();
    int book_id = ui->tableView->model()->data(ui->tableView->model()->index(book.row(),0),0).toInt();
    qDebug() << book_id;
    QSqlQuery query;
    query.prepare("DELETE FROM issued_books WHERE book_id=:book_id");
    query.bindValue(":book_id", book_id);
    query.exec();
    this->close();
}
