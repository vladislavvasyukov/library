#ifndef ISSUEDBOOKS_H
#define ISSUEDBOOKS_H

#include <QDialog>

namespace Ui {
class IssuedBooks;
}

class IssuedBooks : public QDialog
{
    Q_OBJECT

public:
    explicit IssuedBooks(QWidget *parent = 0);
    ~IssuedBooks();

private:
    Ui::IssuedBooks *ui;
};

#endif // ISSUEDBOOKS_H
