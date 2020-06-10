#include "dialogcheckout.h"
#include "ui_dialogcheckout.h"

DialogCheckout::DialogCheckout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCheckout)
{
    ui->setupUi(this);
}

DialogCheckout::~DialogCheckout()
{
    delete ui;
}

int DialogCheckout::getCheckInRoomId()
{
    return ui->comboBox_roomid->currentText().toInt();
}
