#include "issue_books.h"
#include "ui_issue_books.h"
#include <QSqlTableModel>
#include "QDate"
#include "QSqlQuery"

IssuedBooks::IssuedBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IssuedBooks)
{
    ui->setupUi(this);

    QStringList headersBooks = {"Автор", "Название", "ISBN", "Дата поступления", "Жанр"};
    QString tableName = "books";
    QTableView *view = ui->tableBooks;
    this->setupModel(tableName, headersBooks, view);

    QStringList headersReaders = {"Имя", "Фамилия", "Дата рождения", "Адрес", "Телефон"};
    tableName = "readers";
    view = ui->tableReaders;
    this->setupModel(tableName, headersReaders, view);
}

void IssuedBooks::setupModel(const QString &tableName, const QStringList &headers, QTableView *view)
{
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable(tableName);

    for (int i = 1; i < model->columnCount(); i++) {
        model->setHeaderData(i, Qt::Horizontal, headers[i-1]);
    }
    model->select();

    view->setModel(model);
    view->setColumnHidden(0, true);
}

IssuedBooks::~IssuedBooks()
{
    delete ui;
}

void IssuedBooks::on_cancelButton_clicked()
{
    this->close();
}

void IssuedBooks::on_pushButton_clicked()
{
    QModelIndex book = ui->tableBooks->currentIndex();
    int book_id = ui->tableBooks->model()->data(ui->tableBooks->model()->index(book.row(), 0), 0).toInt();

    QModelIndex reader = ui->tableReaders->currentIndex();
    int reader_id = ui->tableBooks->model()->data(ui->tableReaders->model()->index(reader.row(), 0), 0).toInt();

    QDate issued_date = ui->issue_date->date();
    QDate return_date = issued_date.addDays(ui->count_days->value());

    QSqlQuery query;
    query.prepare("INSERT INTO issued_books(reader_id, book_id, issued_date, return_date)"
                  "VALUES (:reader_id, :book_id, :issued_date, :return_date)");

    query.bindValue(":reader_id", reader_id);
    query.bindValue(":book_id", book_id);
    query.bindValue(":issued_date", issued_date.toString("yyyy-MM-dd"));
    query.bindValue(":return_date", return_date.toString("yyyy-MM-dd"));

    query.exec();
    this->close();
}
