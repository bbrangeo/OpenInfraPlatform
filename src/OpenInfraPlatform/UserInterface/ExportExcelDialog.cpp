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
		DataManagement::DocumentManager::getInstance().getData().createExcelReport(filename.toStdString(), ui_->comboBoxAngleMeasurement->currentText() == QString("Degree"));
	}
}
