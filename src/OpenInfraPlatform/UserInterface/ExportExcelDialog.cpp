/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "ExportExcelDialog.h"
#include "buw.BlueInfrastructure.h"
#include "OpenInfraPlatform/DataManagement/Data.h"
#include <QFileDialog>
#include <QUuid>

OpenInfraPlatform::UserInterface::ExportExcelDialog::ExportExcelDialog(QWidget *parent /*= nullptr*/) :
ui_(new Ui::ExportExcelDialog),
QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui_->setupUi(this);
}

OpenInfraPlatform::UserInterface::ExportExcelDialog::~ExportExcelDialog()
{
	
}

void OpenInfraPlatform::UserInterface::ExportExcelDialog::changeEvent(QEvent* evt)
{
	if (evt->type() == QEvent::LanguageChange)
	{
		ui_->retranslateUi(this);
	}
	else
	{
		QWidget::changeEvent(evt);
	}
}

void OpenInfraPlatform::UserInterface::ExportExcelDialog::on_pushButtonCancel_clicked()
{
	hide();
}

void OpenInfraPlatform::UserInterface::ExportExcelDialog::on_pushButtonExport_clicked()
{
	hide();

	QString filename = QFileDialog::getSaveFileName(
		this,
		tr("Save File"),
		QDir::currentPath(),
		tr("Excel Spreadsheet (*.xlsx)")
		);

	if (filename.isNull() == false)
	{
		buw::ifcAlignmentExportDescription desc;
		desc.exportAlignment = true;
		desc.exportTerrain = true;
		desc.useRadiansInsteadOfDegrees = true;

		if (ui_->comboBoxAngleMeasurement->currentText() == QString("Degree"))
		{
			desc.useRadiansInsteadOfDegrees = false;
		}

		QUuid id = QUuid::createUuid();
		QString tempIfcFilename = QDir::currentPath().append(QString("/").append(id.toString().append(".ifc")));
		QString tempLandXMLFilename = QDir::currentPath().append(QString("/").append(id.toString().append(".xml")));
		
		std::string ifcFilename = tempIfcFilename.toStdString(); // "alignment.ifc"; //"C:/Users/no68koc/Desktop/alignment.ifc";//
		std::string landXMLFilename = tempLandXMLFilename.toStdString(); //  "alignment.xml"; //"C:/Users/no68koc/Desktop/alignment.xml";//

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportIfcAlignment(desc, ifcFilename.c_str());
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportLandXML(landXMLFilename.c_str());

		buw::ExcelReport ec(
			filename.toStdString().c_str(),
			landXMLFilename.c_str(),
			ifcFilename.c_str()
		);
	}
}
