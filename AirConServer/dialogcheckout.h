#ifndef DIALOGCHECKOUT_H
#define DIALOGCHECKOUT_H

#include <QDialog>

namespace Ui {
class DialogCheckout;
}

class DialogCheckout : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCheckout(QWidget *parent = nullptr);
    ~DialogCheckout();
    int getCheckInRoomId();//返回选中的房间id
private:
    Ui::DialogCheckout *ui;
};

#endif // DIALOGCHECKOUT_H
