#include "issue_books.h"
#include "ui_issuedbooks.h"
#include <QSqlTableModel>

IssuedBooks::IssuedBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IssuedBooks)
{
    ui->setupUi(this);

    QStringList headersBooks = {"Автор", "Название", "ISBN", "Дата поступления", "Жанр"};
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("books");

    for (int i = 1; i < model->columnCount(); i++) {
        model->setHeaderData(i, Qt::Horizontal, headersBooks[i-1]);
    }
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
}

IssuedBooks::~IssuedBooks()
{
    delete ui;
}
