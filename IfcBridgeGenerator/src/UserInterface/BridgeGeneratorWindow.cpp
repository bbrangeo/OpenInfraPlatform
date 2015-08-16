#include "BridgeGeneratorWindow.h"

#include "ui_BridgeGenerator.h"

#include "../BridgeFactory.h"

#include <QFileDialog>
#include <QString>

BlueIfcBridgeViewer::UserInterface::BridgeGeneratorWindow::BridgeGeneratorWindow( QWidget *parent /*= nullptr*/ )
{
	ui_ = new Ui::BridgeGeneratorWindow();
	ui_->setupUi(this);
}

void BlueIfcBridgeViewer::UserInterface::BridgeGeneratorWindow::on_pushButtonSaveAs_clicked()
{
	bridgeDescription bd;

	try
	{
		bd.length = ui_->lineEditLength->text().toDouble();
		bd.width = ui_->lineEditLength->text().toDouble();
	}
	catch (...)
	{
		std::cout << "err" << std::endl;
	}

	QString filename = QFileDialog::getSaveFileName( 
		this, 
		tr("Save Document"), 
		QDir::currentPath(), 
		tr("IfcBridge Step File (*.stp)") );
	if( !filename.isNull() )
	{
		shared_ptr<BridgeFactory> factory (new BridgeFactory());
		factory->createBridge(  filename.toStdString(), bd );
	}
}
