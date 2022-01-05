#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TP2_Qt.h"
#include <QSerialPort>
#include <QSerialPortInfo>

class TP2_Qt : public QMainWindow
{
	Q_OBJECT
	QSerialPort *port;

public:
    TP2_Qt(QWidget *parent = Q_NULLPTR);

private:
    Ui::TP2_QtClass ui;

public slots:

	void onDisplayBTN_OpenPortClicked();
	void onSerialPortReadyRead();
};
