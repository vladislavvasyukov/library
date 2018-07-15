#ifndef ISSUEDBOOKS_H
#define ISSUEDBOOKS_H

#include <QDialog>
#include <QTableView>

namespace Ui {
class IssuedBooks;
}

class IssuedBooks : public QDialog
{
    Q_OBJECT

public:
    explicit IssuedBooks(QWidget *parent = 0);
    ~IssuedBooks();

private slots:
    void setupModel(const QString &tableName, const QStringList &headers, QTableView *view);

    void on_cancelButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::IssuedBooks *ui;
};

#endif // ISSUEDBOOKS_H
