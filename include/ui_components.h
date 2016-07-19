#ifndef UI_ASDINTERFACE_H
#define UI_ASDINTERFACE_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QLCDNumber>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QComboBox>

QT_BEGIN_NAMESPACE

// Handles the specifics of the UI layout of the interface
class UIComponents {

public:

    static const int BSPACING = 20, BWIDTH = 200, BHEIGHT = 100,
                     COL1_X = 40, COL1_Y = 140, 
                     COL2_X = 300, COL2_Y = COL1_Y,
                     COL3_X = 560, COL3_Y = COL1_Y;

    QLabel *trainingLabel, *trialLabel, *extrasLabel;
    
    QPushButton *trainingRecord, *trainingDelete, *trainingClear, // first column
                *trialBegin, *trialPractice, *trialSandbox,       // second column
                *myoLaunch, *myoCalibrate, *naoLaunch;            // third column
    
    QComboBox *myoCount; // the dropdown selector in the third column

    static const int MYOCOUNT_WIDTH = 70;

    void setupUi(QWidget *MasterInterface) {
        
        QFont boxFont;
        boxFont.setPointSize(14);
        // Create and size window    
        
        if(MasterInterface->objectName().isEmpty()) {
            MasterInterface->setObjectName(QString("MasterInterface"));
        }

        //MasterInterface->resize(410, 260);
        MasterInterface->resize(820, 520);

        /**First Column**/
        
        // Uses HTML to manipulate text, used to make the titles of the columns
        trainingLabel = new QLabel(MasterInterface);
        trainingLabel->setText(QString("<h1><u>Training</u></h1>"));
        trainingLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        trainingLabel->setStyleSheet("QLabel { margin: 40px 0 0 80px }");
        
        // QRect defines the EXACT dimensions and location of the button
        trainingRecord = new QPushButton(MasterInterface);
        trainingRecord->setObjectName(QString("trainingRecord"));
        trainingRecord->setGeometry(QRect(COL1_X, COL1_Y, BWIDTH, BHEIGHT)); 

        trainingDelete = new QPushButton(MasterInterface);
        trainingDelete->setObjectName(QString("trainingDelete"));
        trainingDelete->setGeometry(QRect(COL1_X, COL1_Y+BHEIGHT+BSPACING, BWIDTH, BHEIGHT)); 
        
        trainingClear = new QPushButton(MasterInterface);
        trainingClear->setObjectName(QString("trainingClear"));
        trainingClear->setGeometry(QRect(COL1_X, COL1_Y+2*(BHEIGHT+BSPACING), BWIDTH, BHEIGHT)); 

        /**Second Column**/
        
        trialLabel = new QLabel(MasterInterface);
        trialLabel->setText(QString("<h1><u>Trial</u></h1>"));
        trialLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        trialLabel->setStyleSheet("QLabel { margin: 40px 0 0 360px }");

        trialBegin = new QPushButton(MasterInterface);
        trialBegin->setObjectName(QString("trialBegin"));
        trialBegin->setGeometry(QRect(COL2_X, COL2_Y, BWIDTH, BHEIGHT)); 

        trialPractice = new QPushButton(MasterInterface);
        trialPractice->setObjectName(QString("trialPractice"));
        trialPractice->setGeometry(QRect(COL2_X, COL2_Y+BHEIGHT+BSPACING, BWIDTH, BHEIGHT)); 

        trialSandbox = new QPushButton(MasterInterface);
        trialSandbox->setObjectName(QString("trialSandbox"));
        trialSandbox->setGeometry(QRect(COL2_X, COL2_Y+2*(BHEIGHT+BSPACING), BWIDTH, BHEIGHT)); 

        /**Third Column**/
        
        extrasLabel = new QLabel(MasterInterface);
        extrasLabel->setText(QString("<h1><u>Extras</u></h1>"));
        extrasLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        extrasLabel->setStyleSheet("QLabel { margin: 40px 0 0 620px }");

        myoCount = new QComboBox(MasterInterface);
        myoCount->addItem(QString("2"));
        myoCount->addItem(QString("1"));
        myoCount->setGeometry(QRect(COL3_X, COL3_Y, MYOCOUNT_WIDTH, BHEIGHT)); 
        myoCount->setFont(boxFont);

        myoLaunch = new QPushButton(MasterInterface);
        myoLaunch->setObjectName(QString("myoLaunch"));
        myoLaunch->setGeometry(QRect(COL3_X + MYOCOUNT_WIDTH, COL3_Y, BWIDTH - MYOCOUNT_WIDTH, BHEIGHT)); 

        myoCalibrate = new QPushButton(MasterInterface);
        myoCalibrate->setObjectName(QString("myoCalibrate"));
        myoCalibrate->setGeometry(QRect(COL3_X, COL3_Y+(BHEIGHT+BSPACING), BWIDTH, BHEIGHT)); 

        naoLaunch = new QPushButton(MasterInterface);
        naoLaunch->setObjectName(QString("naoLaunch"));
        naoLaunch->setGeometry(QRect(COL3_X, COL3_Y+2*(BHEIGHT+BSPACING), BWIDTH, BHEIGHT)); 

        /**Polish**/
        
        retranslateUi(MasterInterface);

        // ! Connects the buttons to any listener functions in the MasterInterface object !
        // Maps buttons ObjectName to a onClick function. 
        // For example, on_myoLaunch_clicked() maps to the myoLaunch button which is declared above
        QMetaObject::connectSlotsByName(MasterInterface);
    }

    // Name window and buttons to be more user friendly  
    void retranslateUi(QWidget *MasterInterface){

        QFont f;
        f.setPointSize(16);

        MasterInterface->setWindowTitle(QApplication::translate("MasterInterface", "MasterInterface", 0));

        trainingLabel->adjustSize(); 
        trainingRecord->setText("Train\nClassifier");
        trainingRecord->setFont(f);
        trainingDelete->setText("Delete\nLast Training");
        trainingDelete->setFont(f);
        trainingClear->setText("Clear");
        trainingClear->setFont(f);

        trialLabel->adjustSize();
        trialBegin->setText("Begin Trial");
        trialBegin->setFont(f);
        trialPractice->setText("Begin\nPractice");
        trialPractice->setFont(f);
        trialSandbox->setText("No Evaluation");
        trialSandbox->setFont(f);

        extrasLabel->adjustSize();
        myoLaunch->setText("Launch\nMyo");
        myoLaunch->setFont(f);
        myoCalibrate->setText("Calibrate Myo");
        myoCalibrate->setFont(f);
        naoLaunch->setText("Launch Nao");
        naoLaunch->setFont(f);
   }

    // Because the character will be a number in ASCII format, if we subtract the '0' character, it will convert it to its number form
    int getMyoCount() {
        return myoCount->currentText().toStdString()[0] - '0';
    } 

};

QT_END_NAMESPACE

#endif
