/********************************************************************************
** Form generated from reading UI file 'admincontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINCONTROLLER_H
#define UI_ADMINCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_save;
    QAction *action_exit;
    QAction *action_checkout;
    QAction *action_table;
    QAction *action_checkin;
    QWidget *centralwidget;
    QTableWidget *tableRoomState;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *TurnOnButton;
    QPushButton *TurnOffButton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QDoubleSpinBox *LFeeSpin;
    QLabel *label_3;
    QDoubleSpinBox *MFeeSpin;
    QLabel *label_9;
    QDoubleSpinBox *HFeeSpin;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpinBox *HighestTempSpin;
    QLabel *label_6;
    QLabel *label_5;
    QSpinBox *LowestTempSpin;
    QLabel *label_10;
    QGroupBox *groupBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *ModeCold;
    QSpacerItem *horizontalSpacer;
    QRadioButton *ModeHot;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QLCDNumber *HourLcd;
    QLabel *label_11;
    QLCDNumber *MinuteLcd;
    QLabel *label_12;
    QLCDNumber *SecondLcd;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1286, 684);
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_checkout = new QAction(MainWindow);
        action_checkout->setObjectName(QString::fromUtf8("action_checkout"));
        action_table = new QAction(MainWindow);
        action_table->setObjectName(QString::fromUtf8("action_table"));
        action_checkin = new QAction(MainWindow);
        action_checkin->setObjectName(QString::fromUtf8("action_checkin"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableRoomState = new QTableWidget(centralwidget);
        if (tableRoomState->columnCount() < 9)
            tableRoomState->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableRoomState->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableRoomState->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableRoomState->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        tableRoomState->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        tableRoomState->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        tableRoomState->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        tableRoomState->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        tableRoomState->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        tableRoomState->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableRoomState->setObjectName(QString::fromUtf8("tableRoomState"));
        tableRoomState->setGeometry(QRect(360, 10, 911, 601));
        tableRoomState->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableRoomState->horizontalHeader()->setVisible(true);
        tableRoomState->horizontalHeader()->setHighlightSections(true);
        tableRoomState->verticalHeader()->setVisible(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 570, 301, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        TurnOnButton = new QPushButton(layoutWidget);
        TurnOnButton->setObjectName(QString::fromUtf8("TurnOnButton"));

        horizontalLayout->addWidget(TurnOnButton);

        TurnOffButton = new QPushButton(layoutWidget);
        TurnOffButton->setObjectName(QString::fromUtf8("TurnOffButton"));

        horizontalLayout->addWidget(TurnOffButton);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 140, 301, 171));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 40, 265, 121));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        LFeeSpin = new QDoubleSpinBox(layoutWidget1);
        LFeeSpin->setObjectName(QString::fromUtf8("LFeeSpin"));
        LFeeSpin->setKeyboardTracking(false);
        LFeeSpin->setSingleStep(0.100000000000000);
        LFeeSpin->setValue(0.000000000000000);

        gridLayout->addWidget(LFeeSpin, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        MFeeSpin = new QDoubleSpinBox(layoutWidget1);
        MFeeSpin->setObjectName(QString::fromUtf8("MFeeSpin"));
        MFeeSpin->setKeyboardTracking(false);
        MFeeSpin->setSingleStep(0.100000000000000);
        MFeeSpin->setValue(0.000000000000000);

        gridLayout->addWidget(MFeeSpin, 1, 1, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 2, 1, 1);

        HFeeSpin = new QDoubleSpinBox(layoutWidget1);
        HFeeSpin->setObjectName(QString::fromUtf8("HFeeSpin"));
        HFeeSpin->setKeyboardTracking(false);
        HFeeSpin->setSingleStep(0.100000000000000);
        HFeeSpin->setValue(0.000000000000000);

        gridLayout->addWidget(HFeeSpin, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 320, 301, 131));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 40, 271, 61));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        HighestTempSpin = new QSpinBox(layoutWidget2);
        HighestTempSpin->setObjectName(QString::fromUtf8("HighestTempSpin"));
        HighestTempSpin->setKeyboardTracking(false);
        HighestTempSpin->setMinimum(0);
        HighestTempSpin->setValue(30);

        gridLayout_2->addWidget(HighestTempSpin, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        LowestTempSpin = new QSpinBox(layoutWidget2);
        LowestTempSpin->setObjectName(QString::fromUtf8("LowestTempSpin"));
        LowestTempSpin->setKeyboardTracking(false);
        LowestTempSpin->setMinimum(0);
        LowestTempSpin->setMaximum(99);
        LowestTempSpin->setValue(16);

        gridLayout_2->addWidget(LowestTempSpin, 1, 1, 1, 1);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 1, 2, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 460, 301, 81));
        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 30, 221, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ModeCold = new QRadioButton(layoutWidget3);
        ModeCold->setObjectName(QString::fromUtf8("ModeCold"));
        ModeCold->setChecked(true);

        horizontalLayout_2->addWidget(ModeCold);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ModeHot = new QRadioButton(layoutWidget3);
        ModeHot->setObjectName(QString::fromUtf8("ModeHot"));

        horizontalLayout_2->addWidget(ModeHot);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(40, 30, 301, 91));
        layoutWidget4 = new QWidget(groupBox_4);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 30, 261, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        HourLcd = new QLCDNumber(layoutWidget4);
        HourLcd->setObjectName(QString::fromUtf8("HourLcd"));

        horizontalLayout_3->addWidget(HourLcd);

        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font;
        font.setPointSize(12);
        label_11->setFont(font);

        horizontalLayout_3->addWidget(label_11);

        MinuteLcd = new QLCDNumber(layoutWidget4);
        MinuteLcd->setObjectName(QString::fromUtf8("MinuteLcd"));

        horizontalLayout_3->addWidget(MinuteLcd);

        label_12 = new QLabel(layoutWidget4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        horizontalLayout_3->addWidget(label_12);

        SecondLcd = new QLCDNumber(layoutWidget4);
        SecondLcd->setObjectName(QString::fromUtf8("SecondLcd"));

        horizontalLayout_3->addWidget(SecondLcd);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1286, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_checkin);
        menu->addAction(action_checkout);
        menu->addAction(action_table);
        menu->addAction(action_save);
        menu->addAction(action_exit);

        retranslateUi(MainWindow);
        QObject::connect(action_exit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\263\242\346\231\256\347\211\271\351\205\222\345\272\227\347\251\272\350\260\203\350\256\241\350\264\271\347\263\273\347\273\237\345\220\216\345\217\260", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\203\250\344\277\235\345\255\230", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        action_checkout->setText(QCoreApplication::translate("MainWindow", "\351\241\276\345\256\242\351\200\200\346\210\277", nullptr));
        action_table->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\346\212\245\350\241\250", nullptr));
        action_checkin->setText(QCoreApplication::translate("MainWindow", "\345\212\236\347\220\206\345\205\245\344\275\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableRoomState->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableRoomState->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\210\277\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableRoomState->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableRoomState->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableRoomState->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\351\243\216\351\200\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableRoomState->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableRoomState->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\347\233\256\346\240\207\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableRoomState->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\350\264\271\347\224\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableRoomState->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201", nullptr));
        TurnOnButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\346\234\272", nullptr));
        TurnOffButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\346\234\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\264\271\347\216\207\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\205\203/\347\247\222", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\344\270\255\351\243\216\351\200\237", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\205\203/\347\247\222", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\351\253\230\351\243\216\351\200\237", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\205\203/\347\247\222", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\275\216\351\243\216\351\200\237", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\351\231\220\345\210\266\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\200\351\253\230\346\270\251\345\272\246\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\302\260C", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\234\200\344\275\216\346\270\251\345\272\246\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\302\260C", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\250\241\345\274\217\357\274\232", nullptr));
        ModeCold->setText(QCoreApplication::translate("MainWindow", "\345\210\266\345\206\267\346\250\241\345\274\217", nullptr));
        ModeHot->setText(QCoreApplication::translate("MainWindow", "\345\210\266\347\203\255\346\250\241\345\274\217", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\346\227\266\351\227\264\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINCONTROLLER_H
