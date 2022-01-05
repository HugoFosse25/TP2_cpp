#include "TP2_Qt.h"

TP2_Qt::TP2_Qt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

	for (int i = 0; i < availablePorts.size(); i++)
	{

		QSerialPortInfo info = availablePorts[i];
		ui.CB_Ports->addItem(info.portName(), QVariant(info.portName()));

	}
}

void TP2_Qt::onDisplayBTN_OpenPortClicked()
{

	if (ui.CB_Ports->currentIndex() >= 0)
	{

		port = new QSerialPort(ui.CB_Ports->currentText());
		QObject::connect(port, SIGNAL(readyRead()), this, SLOT(onSerialPortReadyRead()));
		port->setBaudRate(9600);
		port->setDataBits(QSerialPort::DataBits::Data8);
		port->setParity(QSerialPort::Parity::NoParity);
		port->setStopBits(QSerialPort::StopBits::OneStop);
		if (port->open(QIODevice::OpenModeFlag::ExistingOnly | QIODevice::OpenModeFlag::ReadWrite));
		{

			ui.TXT_Status->setText("Ouvert");

		}

	}

}

void TP2_Qt::onSerialPortReadyRead()
{

	QByteArray data = port->read(port->bytesAvailable());
	QString str(data);
	ui.RECEIVEDTXT_Data->insertPlainText(str);

}