#include "return_book.h"
#include "ui_return_book.h"
#include <QSqlQueryModel>
#include <QDebug>

returnBook::returnBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnBook)
{
    ui->setupUi(this);
    QStringList headersIssuedBooks = {"Автор", "Название", "Имя", "Фамилия", "Дата выдачи", "Дата возврата"};

    QSqlQueryModel *compModel = new QSqlQueryModel();

    compModel->setQuery("select b.author, b.title, r.firstname, r.lastname, i.issued_date, i.return_date "
                        "FROM books b INNER JOIN issued_books i "
                        "ON b.id = i.book_id "
                        "INNER JOIN readers r "
                        "ON r.id = i.reader_id");

    for (int i = 0; i < compModel->columnCount(); i++) {
        compModel->setHeaderData(i, Qt::Horizontal, headersIssuedBooks[i]);
    }
    ui->tableView->setModel(0);
    ui->tableView->setModel(compModel);
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
    QModelIndex currentDiscount  = ui->tableView->currentIndex();
    qDebug() << ui->tableView->model()->data(ui->tableView->model()->index(currentDiscount.row(),2),0);
}
