/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "OpenInfraPlatform/UserInterface/ExportIfcZipDialog.h"
#include <QFileDialog>
#include <quuid.h>
#include "OpenInfraPlatform/DataManagement/Data.h"
#include "OpenInfraPlatform/DataManagement/AsyncJob.h"

#define DEFL 0
#define INFL 1

#include "ui_ExportIfcZipDialog.h"

OpenInfraPlatform::UserInterface::ExportIfcZipDialog::ExportIfcZipDialog(
	QWidget *parent/* = nullptr*/) :
	ui_(new Ui::ExportIfcZipDialog),
	QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui_->setupUi(this);
}

OpenInfraPlatform::UserInterface::ExportIfcZipDialog::~ExportIfcZipDialog()
{

}

void OpenInfraPlatform::UserInterface::ExportIfcZipDialog::on_pushButtonExport_clicked()
{
	hide();

	QString filename = QFileDialog::getSaveFileName(
		this,
		tr("Save Document"),
		QDir::currentPath(),
		tr("Zip compressed IfcAlignment BuildingSmart P6 Step File (*.ifczip)"));

	QUuid tempName = QUuid::createUuid();
	QString tempFilename = QDir::currentPath().append(QString("/").append(tempName.toString().append(".ifc")));

	

	if (!filename.isNull())
	{
		buw::ifcAlignmentExportDescription desc;
		desc.exportTerrain = ui_->checkBoxExportDigitalElevationModel->isChecked();
		desc.exportAlignment = ui_->checkBoxExportAlignment->isChecked();
		desc.useRadiansInsteadOfDegrees = true;

		if (ui_->comboBoxAngleMeasurement->currentText() == QString("Degree"))
		{
			desc.useRadiansInsteadOfDegrees = false;
		}

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportIfcAlignment(
			desc,
			tempFilename.toStdString());

		zipper = new OpenInfraPlatform::DataManagement::IfcZipper(this, filename,tempFilename, DEFL);		
		connect(zipper, &OpenInfraPlatform::DataManagement::IfcZipper::finished, zipper, &QObject::deleteLater);
		connect(&OpenInfraPlatform::AsyncJob::getInstance(), SIGNAL(finished()), zipper, SLOT(start()));		
	}
}

void OpenInfraPlatform::UserInterface::ExportIfcZipDialog::on_pushButtonCancel_clicked()
{
	hide();
}