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

    void on_add_book_clicked();

    void on_add_reader_clicked();

    void on_switchBooksAndReaders_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel  *model;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
