#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbook.h"
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

void MainWindow::on_showListBooks_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Question");
    msgBox.setInformativeText("Are you really want come to world of books?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setDefaultButton(QMessageBox::Ok);

    int res = msgBox.exec();
    if (res == QMessageBox::Ok){
        QMessageBox::about(this, "OK", "You are reader");
    }
}

void MainWindow::on_Quit_clicked()
{

    QMessageBox msgBox;
    msgBox.setText("GoodBye");
    msgBox.setInformativeText("We believe you will come again!!!");

    msgBox.exec();
    QApplication::quit();
}

void MainWindow::on_add_book_clicked()
{
    AddBook addbook;
    addbook.setModal(true);
    addbook.exec();
}
