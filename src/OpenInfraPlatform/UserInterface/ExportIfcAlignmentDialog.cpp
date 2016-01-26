/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "ExportIfcAlignmentDialog.h"
#include "OpenInfraPlatform/DataManagement/Data.h"
#include "OpenInfraPlatform/DataManagement/AsyncJob.h"
#include <QFileDialog>
#include <QUuid>

OpenInfraPlatform::UserInterface::ExportIfcAlignmentDialog::ExportIfcAlignmentDialog(
QWidget *parent/* = nullptr*/) :
	ui_(new Ui::ExportP6AlignmentDialog),
	QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui_->setupUi(this);
}

OpenInfraPlatform::UserInterface::ExportIfcAlignmentDialog::~ExportIfcAlignmentDialog()
{

}

void OpenInfraPlatform::UserInterface::ExportIfcAlignmentDialog::changeEvent(QEvent* evt)
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

void OpenInfraPlatform::UserInterface::ExportIfcAlignmentDialog::on_pushButtonExport_clicked()
{
	hide();

	QString filename = QFileDialog::getSaveFileName(
		this,
		tr("Save Document"),
		QDir::currentPath(),
		tr("IfcAlignment BuildingSmart P6 Step File (*.ifc);;Zip compressed IfcAlignment BuildingSmart P6 Step File (*.ifczip)")
	);

	if (!filename.isNull())
	{
		buw::ifcAlignmentExportDescription desc;
		desc.exportTerrain = ui_->checkBoxExportDigitalElevationModel->isChecked();
		desc.exportAlignment = ui_->checkBoxExportAlignment->isChecked();
		desc.useRadiansInsteadOfDegrees = true;

		if (ui_->comboBoxIfcSchemaVersion->currentText() == QString("IFC4x1"))
		{
			desc.schemaVersion = buw::eIfcSchemaVersion::IFC4x1;
		}

		if (ui_->comboBoxIfcSchemaVersion->currentText() == QString("IFC4"))
		{
			desc.schemaVersion = buw::eIfcSchemaVersion::IFC4;
		}

		if (ui_->comboBoxIfcSchemaVersion->currentText() == QString("IFC2x3"))
		{
			desc.schemaVersion = buw::eIfcSchemaVersion::IFC2x3;
		}

		if (ui_->comboBoxAngleMeasurement->currentText() == QString("Degree"))
		{
			desc.useRadiansInsteadOfDegrees = false;
		}

		desc.useFixedEntityIdForGeometry = ui_->checkBoxUseFixedEntityIdForGeometry->isChecked();
		desc.startId = ui_->lineEditStartId->text().toInt();
		
		if (filename.endsWith(".ifc")) 
		{
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportIfcAlignment(
				desc,
				filename.toStdString()
			);
		}
		else if (filename.endsWith("zip"))
		{
			QUuid tempName = QUuid::createUuid();
			QString tempFilename = QDir::currentPath().append(QString("/").append(tempName.toString().append(".ifc")));

			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportIfcAlignment(
				desc,
				tempFilename.toStdString()
			);

			OpenInfraPlatform::DataManagement::IfcZipper* ExportZipper = new OpenInfraPlatform::DataManagement::IfcZipper(nullptr, QString(filename.data()), tempFilename, DEFL);

			QObject::connect(&OpenInfraPlatform::AsyncJob::getInstance(), SIGNAL(finished()), ExportZipper, SLOT(start()));
			QObject::connect(ExportZipper, &OpenInfraPlatform::DataManagement::IfcZipper::finished, ExportZipper, &QObject::deleteLater);
		}
	}
}

void OpenInfraPlatform::UserInterface::ExportIfcAlignmentDialog::on_pushButtonCancel_clicked()
{
	hide();
}
