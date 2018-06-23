#ifndef ADDREADER_H
#define ADDREADER_H

#include <QDialog>

namespace Ui {
class AddReader;
}

class AddReader : public QDialog
{
    Q_OBJECT

public:
    explicit AddReader(QWidget *parent = 0);
    ~AddReader();

private slots:
    void on_cancelButton_clicked();

    void on_addReaderButton_clicked();

private:
    Ui::AddReader *ui;
};

#endif // ADDREADER_H
