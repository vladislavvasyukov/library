#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbook.h"
#include "addreader.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    QString lableButton = ui->switchBooksAndReaders->text();
    if (lableButton == "Список книг") {
        ui->switchBooksAndReaders->setText("Список читателей");
    } else {
        ui->switchBooksAndReaders->setText("Список книг");
    }
}
