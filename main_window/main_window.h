#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setupModel(const QString &tableName, const QStringList &headers);

    void on_Quit_clicked();

    void on_listOfBooks_clicked();

    void on_listOfReaders_clicked();

    void on_addBook_clicked();

    void on_addReader_clicked();

    void on_listOfIssuedBooks_clicked();

    void on_returnBook_clicked();

    void on_deleteReader_clicked();

    void on_issueBook_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel  *model;
    QSqlQueryModel *compModel;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
