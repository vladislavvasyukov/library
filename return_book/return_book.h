#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QDialog>

namespace Ui {
class returnBook;
}

class returnBook : public QDialog
{
    Q_OBJECT

public:
    explicit returnBook(QWidget *parent = 0);
    ~returnBook();

private slots:
    void on_pushButton_2_clicked();    
    void on_pushButton_clicked();

private:
    Ui::returnBook *ui;
};

#endif // RETURNBOOK_H
