/********************************************************************************
** Form generated from reading UI file 'dialogcheckout.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHECKOUT_H
#define UI_DIALOGCHECKOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogCheckout
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_roomid;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *DialogCheckout)
    {
        if (DialogCheckout->objectName().isEmpty())
            DialogCheckout->setObjectName(QString::fromUtf8("DialogCheckout"));
        DialogCheckout->resize(302, 198);
        widget = new QWidget(DialogCheckout);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 60, 196, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox_roomid = new QComboBox(widget);
        comboBox_roomid->addItem(QString());
        comboBox_roomid->addItem(QString());
        comboBox_roomid->addItem(QString());
        comboBox_roomid->addItem(QString());
        comboBox_roomid->addItem(QString());
        comboBox_roomid->setObjectName(QString::fromUtf8("comboBox_roomid"));

        horizontalLayout->addWidget(comboBox_roomid);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_ok = new QPushButton(widget);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        horizontalLayout_2->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(widget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_2->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DialogCheckout);
        QObject::connect(pushButton_ok, SIGNAL(clicked()), DialogCheckout, SLOT(accept()));
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), DialogCheckout, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogCheckout);
    } // setupUi

    void retranslateUi(QDialog *DialogCheckout)
    {
        DialogCheckout->setWindowTitle(QCoreApplication::translate("DialogCheckout", "\345\212\236\347\220\206\351\200\200\346\210\277", nullptr));
        label->setText(QCoreApplication::translate("DialogCheckout", "\351\200\200\346\210\277\346\210\277\345\217\267: ", nullptr));
        comboBox_roomid->setItemText(0, QCoreApplication::translate("DialogCheckout", "601", nullptr));
        comboBox_roomid->setItemText(1, QCoreApplication::translate("DialogCheckout", "602", nullptr));
        comboBox_roomid->setItemText(2, QCoreApplication::translate("DialogCheckout", "603", nullptr));
        comboBox_roomid->setItemText(3, QCoreApplication::translate("DialogCheckout", "604", nullptr));
        comboBox_roomid->setItemText(4, QCoreApplication::translate("DialogCheckout", "605", nullptr));

        pushButton_ok->setText(QCoreApplication::translate("DialogCheckout", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("DialogCheckout", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCheckout: public Ui_DialogCheckout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHECKOUT_H
