/********************************************************************************
** Form generated from reading UI file 'dialogcheckin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHECKIN_H
#define UI_DIALOGCHECKIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogCheckIn
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_roomid;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *DialogCheckIn)
    {
        if (DialogCheckIn->objectName().isEmpty())
            DialogCheckIn->setObjectName(QString::fromUtf8("DialogCheckIn"));
        DialogCheckIn->resize(346, 158);
        widget = new QWidget(DialogCheckIn);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 50, 181, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setTabletTracking(false);

        horizontalLayout->addWidget(label);

        comboBox_roomid = new QComboBox(widget);
        comboBox_roomid->addItem(QString());
        comboBox_roomid->addItem(QString());
        comboBox_roomid->addItem(QString());
        comboBox_roomid->addItem(QString());
        comboBox_roomid->addItem(QString());
        comboBox_roomid->setObjectName(QString::fromUtf8("comboBox_roomid"));

        horizontalLayout->addWidget(comboBox_roomid);

        widget1 = new QWidget(DialogCheckIn);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(80, 110, 181, 31));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_ok = new QPushButton(widget1);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        horizontalLayout_2->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(widget1);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_2->addWidget(pushButton_cancel);


        retranslateUi(DialogCheckIn);
        QObject::connect(pushButton_ok, SIGNAL(clicked()), DialogCheckIn, SLOT(accept()));
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), DialogCheckIn, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogCheckIn);
    } // setupUi

    void retranslateUi(QDialog *DialogCheckIn)
    {
        DialogCheckIn->setWindowTitle(QCoreApplication::translate("DialogCheckIn", "\345\212\236\347\220\206\345\205\245\344\275\217", nullptr));
        label->setText(QCoreApplication::translate("DialogCheckIn", "\346\210\277\351\227\264\345\217\267:  ", nullptr));
        comboBox_roomid->setItemText(0, QCoreApplication::translate("DialogCheckIn", "601", nullptr));
        comboBox_roomid->setItemText(1, QCoreApplication::translate("DialogCheckIn", "602", nullptr));
        comboBox_roomid->setItemText(2, QCoreApplication::translate("DialogCheckIn", "603", nullptr));
        comboBox_roomid->setItemText(3, QCoreApplication::translate("DialogCheckIn", "604", nullptr));
        comboBox_roomid->setItemText(4, QCoreApplication::translate("DialogCheckIn", "605", nullptr));

        pushButton_ok->setText(QCoreApplication::translate("DialogCheckIn", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("DialogCheckIn", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCheckIn: public Ui_DialogCheckIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHECKIN_H
