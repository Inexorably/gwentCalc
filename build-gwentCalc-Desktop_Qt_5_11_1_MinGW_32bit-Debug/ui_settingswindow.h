/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *settingsLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *multithreadCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *nIterationsCheckBox;
    QSpinBox *nIterationsSpinBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *percentCheckBox;
    QDoubleSpinBox *percentSpinBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpinBox *r1SpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpinBox *r2SpinBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpinBox *r3SpinBox;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *varyRoundCheckBox;
    QSpinBox *varyRoundSpinBox;
    QCheckBox *closeParentWindowCheckBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDoubleSpinBox *bloodThirst0SpinBox;
    QLabel *label_6;
    QDoubleSpinBox *bloodThirst1SpinBox;
    QLabel *label_4;
    QDoubleSpinBox *bloodThirst2SpinBox;
    QLabel *label_5;
    QDoubleSpinBox *bloodThirst3SpinBox;

    void setupUi(QDialog *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(392, 411);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsWindow->sizePolicy().hasHeightForWidth());
        SettingsWindow->setSizePolicy(sizePolicy);
        settingsLayoutWidget = new QWidget(SettingsWindow);
        settingsLayoutWidget->setObjectName(QStringLiteral("settingsLayoutWidget"));
        settingsLayoutWidget->setGeometry(QRect(220, 350, 169, 27));
        horizontalLayout_3 = new QHBoxLayout(settingsLayoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(settingsLayoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setMaximumSize(QSize(80, 25));

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(settingsLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMaximumSize(QSize(80, 25));

        horizontalLayout_3->addWidget(cancelButton);

        layoutWidget = new QWidget(SettingsWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 31, 367, 315));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        multithreadCheckBox = new QCheckBox(layoutWidget);
        multithreadCheckBox->setObjectName(QStringLiteral("multithreadCheckBox"));
        multithreadCheckBox->setChecked(true);

        verticalLayout->addWidget(multithreadCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nIterationsCheckBox = new QCheckBox(layoutWidget);
        nIterationsCheckBox->setObjectName(QStringLiteral("nIterationsCheckBox"));

        horizontalLayout_2->addWidget(nIterationsCheckBox);

        nIterationsSpinBox = new QSpinBox(layoutWidget);
        nIterationsSpinBox->setObjectName(QStringLiteral("nIterationsSpinBox"));
        nIterationsSpinBox->setMinimum(1);
        nIterationsSpinBox->setMaximum(1000000000);
        nIterationsSpinBox->setSingleStep(1000);
        nIterationsSpinBox->setValue(1000);

        horizontalLayout_2->addWidget(nIterationsSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        percentCheckBox = new QCheckBox(layoutWidget);
        percentCheckBox->setObjectName(QStringLiteral("percentCheckBox"));
        percentCheckBox->setChecked(true);

        horizontalLayout->addWidget(percentCheckBox);

        percentSpinBox = new QDoubleSpinBox(layoutWidget);
        percentSpinBox->setObjectName(QStringLiteral("percentSpinBox"));
        percentSpinBox->setDecimals(8);
        percentSpinBox->setMaximum(100);
        percentSpinBox->setSingleStep(0.01);
        percentSpinBox->setValue(1);

        horizontalLayout->addWidget(percentSpinBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        r1SpinBox = new QSpinBox(layoutWidget);
        r1SpinBox->setObjectName(QStringLiteral("r1SpinBox"));
        r1SpinBox->setValue(6);

        horizontalLayout_4->addWidget(r1SpinBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        r2SpinBox = new QSpinBox(layoutWidget);
        r2SpinBox->setObjectName(QStringLiteral("r2SpinBox"));
        r2SpinBox->setValue(4);

        horizontalLayout_5->addWidget(r2SpinBox);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        r3SpinBox = new QSpinBox(layoutWidget);
        r3SpinBox->setObjectName(QStringLiteral("r3SpinBox"));
        r3SpinBox->setEnabled(false);
        r3SpinBox->setValue(6);

        horizontalLayout_6->addWidget(r3SpinBox);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        varyRoundCheckBox = new QCheckBox(layoutWidget);
        varyRoundCheckBox->setObjectName(QStringLiteral("varyRoundCheckBox"));
        varyRoundCheckBox->setChecked(true);

        horizontalLayout_7->addWidget(varyRoundCheckBox);

        varyRoundSpinBox = new QSpinBox(layoutWidget);
        varyRoundSpinBox->setObjectName(QStringLiteral("varyRoundSpinBox"));
        varyRoundSpinBox->setValue(3);

        horizontalLayout_7->addWidget(varyRoundSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_7);

        closeParentWindowCheckBox = new QCheckBox(layoutWidget);
        closeParentWindowCheckBox->setObjectName(QStringLiteral("closeParentWindowCheckBox"));
        closeParentWindowCheckBox->setChecked(true);

        verticalLayout_3->addWidget(closeParentWindowCheckBox);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(16777215, 13));

        verticalLayout_4->addWidget(label_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        bloodThirst0SpinBox = new QDoubleSpinBox(layoutWidget);
        bloodThirst0SpinBox->setObjectName(QStringLiteral("bloodThirst0SpinBox"));
        bloodThirst0SpinBox->setEnabled(false);
        bloodThirst0SpinBox->setMaximumSize(QSize(16777215, 23));
        bloodThirst0SpinBox->setMaximum(100);

        horizontalLayout_8->addWidget(bloodThirst0SpinBox);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        bloodThirst1SpinBox = new QDoubleSpinBox(layoutWidget);
        bloodThirst1SpinBox->setObjectName(QStringLiteral("bloodThirst1SpinBox"));
        bloodThirst1SpinBox->setMaximumSize(QSize(16777215, 23));
        bloodThirst1SpinBox->setMaximum(100);
        bloodThirst1SpinBox->setValue(20);

        horizontalLayout_8->addWidget(bloodThirst1SpinBox);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        bloodThirst2SpinBox = new QDoubleSpinBox(layoutWidget);
        bloodThirst2SpinBox->setObjectName(QStringLiteral("bloodThirst2SpinBox"));
        bloodThirst2SpinBox->setMaximumSize(QSize(16777215, 23));
        bloodThirst2SpinBox->setMaximum(100);
        bloodThirst2SpinBox->setValue(50);

        horizontalLayout_8->addWidget(bloodThirst2SpinBox);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        bloodThirst3SpinBox = new QDoubleSpinBox(layoutWidget);
        bloodThirst3SpinBox->setObjectName(QStringLiteral("bloodThirst3SpinBox"));
        bloodThirst3SpinBox->setMaximumSize(QSize(16777215, 23));
        bloodThirst3SpinBox->setMaximum(100);
        bloodThirst3SpinBox->setValue(20);

        horizontalLayout_8->addWidget(bloodThirst3SpinBox);


        verticalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout_3->addLayout(verticalLayout_4);


        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Dialog", nullptr));
        okButton->setText(QApplication::translate("SettingsWindow", "OK", nullptr));
        cancelButton->setText(QApplication::translate("SettingsWindow", "Cancel", nullptr));
#ifndef QT_NO_TOOLTIP
        multithreadCheckBox->setToolTip(QApplication::translate("SettingsWindow", "<html><head/><body><p>When simulating multiple deck/combo sets (.gwc files) against each other, allow each set to have it's own worker thread.  May disable some real-time ui elements.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        multithreadCheckBox->setText(QApplication::translate("SettingsWindow", "Allow multithreading", nullptr));
        nIterationsCheckBox->setText(QApplication::translate("SettingsWindow", "Run n iterations:", nullptr));
        percentCheckBox->setText(QApplication::translate("SettingsWindow", "Run until error drops below n %: ", nullptr));
        label->setText(QApplication::translate("SettingsWindow", "Cards played round 1:", nullptr));
        label_2->setText(QApplication::translate("SettingsWindow", "Cards played round 2:", nullptr));
        label_3->setText(QApplication::translate("SettingsWindow", "Cards played round 3:", nullptr));
        varyRoundCheckBox->setText(QApplication::translate("SettingsWindow", "Vary round length amount:", nullptr));
        closeParentWindowCheckBox->setText(QApplication::translate("SettingsWindow", "Close parent window when moving between windows", nullptr));
        label_7->setText(QApplication::translate("SettingsWindow", "Bloodthirst probabilities % (number of damaged enemies)", nullptr));
        label_8->setText(QApplication::translate("SettingsWindow", "0", nullptr));
        label_6->setText(QApplication::translate("SettingsWindow", "1", nullptr));
        label_4->setText(QApplication::translate("SettingsWindow", "2", nullptr));
        label_5->setText(QApplication::translate("SettingsWindow", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
