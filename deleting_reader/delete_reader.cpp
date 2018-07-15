#include "delete_reader.h"
#include "ui_delete_reader.h"
#include <QSqlDatabase>
#include <QSqlTableModel>

DeleteReader::DeleteReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteReader)
{
    ui->setupUi(this);

    QStringList headers = {"Имя", "Фамилия", "Дата рождения", "Адрес", "Телефон"};
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("readers");

    for (int i = 1; i < model->columnCount(); i++) {
        model->setHeaderData(i, Qt::Horizontal, headers[i-1]);
    }
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
}

DeleteReader::~DeleteReader()
{
    delete ui;
}
