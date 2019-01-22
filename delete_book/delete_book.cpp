#include "delete_book.h"
#include "ui_delete_book.h"
#include <QSqlTableModel>

deleteBook::deleteBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteBook)
{
    ui->setupUi(this);

    QStringList headers = {"Автор", "Название", "Имя", "Фамилия", "Дата выдачи", "Дата возврата"};
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("books");

    for (int i = 1; i < model->columnCount(); i++) {
        model->setHeaderData(i, Qt::Horizontal, headers[i-1]);
    }
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
}

deleteBook::~deleteBook()
{
    delete ui;
}

void deleteBook::on_deleteBookButton_clicked()
{

}

void deleteBook::on_cancel_clicked()
{
    this->close();
}
