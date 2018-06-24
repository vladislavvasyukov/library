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

void MainWindow::on_add_book_clicked()
{
    AddBook addbook;
    addbook.setModal(true);
    addbook.exec();
}

void MainWindow::on_add_reader_clicked()
{
    AddReader addreader;
    addreader.setModal(true);
    addreader.exec();
}

void MainWindow::on_switchBooksAndReaders_clicked()
{
    QStringList headersReaders = {"Имя", "Фамилия", "Дата рождения", "Адрес"};
    QStringList headersBooks = {"Автор", "Название", "ISBN", "Дата поступления", "Жанр"};
    QString lableButton = ui->switchBooksAndReaders->text();

    ui->tableView->setModel(0);

    if (lableButton == "Список книг") {
        ui->switchBooksAndReaders->setText("Список читателей");
        this->setupModel("books", headersBooks);
    } else {
        ui->switchBooksAndReaders->setText("Список книг");
        this->setupModel("readers", headersReaders);
    }
}
