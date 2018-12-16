#include "main_window.h"
#include "ui_main_window.h"
#include "issuing_books/issue_books.h"
#include "adding_book/add_book.h"
#include "adding_reader/add_reader.h"
#include "return_book/return_book.h"
#include "deleting_reader/delete_reader.h"
#include <QSqlDatabase>
#include "QDebug"
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
    ui->main_title->setText("Список читателей");
}

void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel();
    model->setTable(tableName);

    for (int i = 1; i < model->columnCount(); i++) {
        model->setHeaderData(i, Qt::Horizontal, headers[i-1]);
    }
    model->select();

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
    ui->main_title->setText("Список книг");
    this->setupModel("books", headersBooks);
}

void MainWindow::on_listOfReaders_clicked()
{
    QStringList headersReaders = {"Имя", "Фамилия", "Дата рождения", "Адрес", "Телефон"};
    ui->tableView->setModel(0);
    ui->main_title->setText("Список читателей");
    this->setupModel("readers", headersReaders);
    qDebug() << 'This is adding bok';
}

void MainWindow::on_listOfIssuedBooks_clicked()
{
    QStringList headersIssuedBooks = {"Автор", "Название", "Имя", "Фамилия", "Дата выдачи", "Дата возврата"};

    compModel = new QSqlQueryModel();

    compModel->setQuery("select distinct b.author, b.title, r.firstname, r.lastname, i.issued_date, i.return_date "
                        "FROM books b INNER JOIN issued_books i "
                        "ON b.id = i.book_id "
                        "INNER JOIN readers r "
                        "ON r.id = i.reader_id");

    for (int i = 0; i < compModel->columnCount(); i++) {
        compModel->setHeaderData(i, Qt::Horizontal, headersIssuedBooks[i]);
    }

    ui->tableView->setModel(0);
    ui->tableView->setModel(compModel);
    ui->main_title->setText("Список выданных книг");
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

void MainWindow::on_deleteReader_clicked()
{
    DeleteReader deletereader;
    deletereader.setModal(true);
    deletereader.exec();
}

void MainWindow::on_issueBook_clicked()
{
    IssuedBooks issueBook;
    issueBook.setModal(true);
    issueBook.exec();
}
