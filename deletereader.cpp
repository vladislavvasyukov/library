#include "deletereader.h"
#include "ui_deletereader.h"

DeleteReader::DeleteReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteReader)
{
    ui->setupUi(this);
}

DeleteReader::~DeleteReader()
{
    delete ui;
}
