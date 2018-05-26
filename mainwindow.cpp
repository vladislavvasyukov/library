#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::on_loginButton_clicked()
{
    ui->label->setText("You are successfully login!!!");
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
    } else {
        QMessageBox::about(this, "BYE", "Goodbye, stupid");
        QApplication::quit();
    }
}
