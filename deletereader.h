#ifndef DELETEREADER_H
#define DELETEREADER_H

#include <QDialog>

namespace Ui {
class DeleteReader;
}

class DeleteReader : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteReader(QWidget *parent = 0);
    ~DeleteReader();

private:
    Ui::DeleteReader *ui;
};

#endif // DELETEREADER_H
