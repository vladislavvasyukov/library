#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbook.h"
#include "addreader.h"
#include <QSqlDatabase>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\my_projects\\library.db");

    QString tableName = "readers";
    QStringList headers = {"Имя", "Фамилия", "Дата рождения", "Адрес"};
    this->setupModel(tableName, headers);
}

void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel();
    model->setTable(tableName);

    for (int i = 1; i < model->columnCount(); i++) {
        model->setHeaderData(i, Qt::Horizontal, headers[i-1]);
    }
    model->select();

    db.close();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Quit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_listOfBooks_clicked()
{
    QStringList headersBooks = {"Автор", "Название", "ISBN", "Дата поступления", "Жанр"};
    ui->tableView->setModel(0);
    this->setupModel("books", headersBooks);
}

void MainWindow::on_listOfReaders_clicked()
{
    QStringList headersReaders = {"Имя", "Фамилия", "Дата рождения", "Адрес"};
    ui->tableView->setModel(0);
    this->setupModel("readers", headersReaders);
}

void MainWindow::on_addBook_clicked()
{
    AddBook addbook;
    addbook.setModal(true);
    addbook.exec();
}

void MainWindow::on_addReader_clicked()
{
    AddReader addreader;
    addreader.setModal(true);
    addreader.exec();
}
