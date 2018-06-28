#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbook.h"
#include "addreader.h"
#include "returnbook.h"
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
    QStringList headers = {"Имя", "Фамилия", "Дата рождения", "Адрес", "Телефон"};
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
    QStringList headersReaders = {"Имя", "Фамилия", "Дата рождения", "Адрес", "Телефон"};
    ui->tableView->setModel(0);
    this->setupModel("readers", headersReaders);
}

void MainWindow::on_listOfIssuedBooks_clicked()
{
    QStringList headersIssuedBooks = {"Автор", "Название", "Имя", "Фамилия", "Дата выдачи", "Дата возврата"};
    compModel = new QSqlQueryModel();
//    QSqlQueryModel queryModel(QSqlDatabase::database("NAME_CONNECTION"));

    compModel->setQuery("select b.author, b.title, r.firstname, r.lastname, i.issued_date, i.return_date"
                        "FROM books b INNER JOIN issued_books i"
                        "ON b.id = i.book_id"
                        "INNER JOIN readers r"
                        "ON r.id = i.reader_id");

    for (int i = 0; i < compModel->columnCount(); i++) {
        model->setHeaderData(i, Qt::Horizontal, headersIssuedBooks[i]);
    }

    ui->tableView->setModel(0);
    ui->tableView->setModel(compModel);
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

void MainWindow::on_returnBook_clicked()
{
    returnBook returnBook;
    returnBook.setModal(true);
    returnBook.exec();
}
