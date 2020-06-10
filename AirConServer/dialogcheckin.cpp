#include "dialogcheckin.h"
#include "ui_dialogcheckin.h"


DialogCheckIn::DialogCheckIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCheckIn)
{
    ui->setupUi(this);
}

DialogCheckIn::~DialogCheckIn()
{
    delete ui;
}

int DialogCheckIn::getCheckInRoomId()
{
    return ui->comboBox_roomid->currentText().toInt();
}
