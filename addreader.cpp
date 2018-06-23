#include "addreader.h"
#include "ui_addreader.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

AddReader::AddReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReader)
{
    ui->setupUi(this);
}

AddReader::~AddReader()
{
    delete ui;
}

void AddReader::on_cancelButton_clicked()
{
    this->close();
}

void AddReader::on_addReaderButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Information");
    msgBox.setInformativeText("Вы завели новую карточку читателя.");
    msgBox.setIcon(QMessageBox::Information);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\my_projects\\library.db");
    bool isOpen = db.open();

    QSqlQuery query;
    query.prepare("INSERT INTO readers (firstname, lastname, birth_date, address)"
             "VALUES (:firstname, :lastname, :birth_date, :address)");
    query.bindValue(":firstname", ui->firstname->text());
    query.bindValue(":lastname", ui->lastname->text());
    query.bindValue(":birth_date", ui->birth_date->text());
    query.bindValue(":address", ui->address->text());
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
