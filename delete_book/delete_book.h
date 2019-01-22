#ifndef DELETE_BOOK_H
#define DELETE_BOOK_H

#include <QDialog>

namespace Ui {
class deleteBook;
}

class deleteBook : public QDialog
{
    Q_OBJECT

public:
    explicit deleteBook(QWidget *parent = 0);
    ~deleteBook();

private slots:
    void on_deleteBookButton_clicked();

    void on_cancel_clicked();

private:
    Ui::deleteBook *ui;
};

#endif // DELETE_BOOK_H
