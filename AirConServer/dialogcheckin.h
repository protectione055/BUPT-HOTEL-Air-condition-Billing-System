#ifndef DIALOGCHECKIN_H
#define DIALOGCHECKIN_H

#include <QDialog>

namespace Ui {
class DialogCheckIn;
}

class DialogCheckIn : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCheckIn(QWidget *parent = nullptr);
    ~DialogCheckIn();
    int getCheckInRoomId();//返回选中的房间id

private slots:

private:
    Ui::DialogCheckIn *ui;
};

#endif // DIALOGCHECKIN_H
