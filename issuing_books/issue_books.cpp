#include "issue_books.h"
#include "ui_issue_books.h"
#include <QSqlTableModel>

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
    // There must be a code of issuing book
}
