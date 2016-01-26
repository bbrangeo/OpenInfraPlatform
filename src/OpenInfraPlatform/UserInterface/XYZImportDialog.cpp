/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "XYZImportDialog.h"

#include "OpenInfraPlatform/DataManagement/Data.h"

#include "OpenInfraPlatform/DataManagement/Command/ImportXYZ.h"


OpenInfraPlatform::UserInterface::XYZImportDialog::XYZImportDialog( QWidget *parent /*= nullptr*/ ) :
    ui_(new Ui::XYZImportDialog),
    QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
    ui_->setupUi(this);
}

OpenInfraPlatform::UserInterface::XYZImportDialog::~XYZImportDialog()
{

}

void OpenInfraPlatform::UserInterface::XYZImportDialog::changeEvent(QEvent* evt) 
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

void OpenInfraPlatform::UserInterface::XYZImportDialog::on_pushButtonBrowse_clicked()
{
    QString openFile = QFileDialog::getOpenFileName(this, tr("Open File"),QDir::currentPath(),tr("XYZ Files (*.xyz);;Text files (*.txt)"));
    std::string utf8_text_file = openFile.toUtf8().constData();

    ui_->lineEdit->setText(openFile);
}

void OpenInfraPlatform::UserInterface::XYZImportDialog::on_pushButtonImport_clicked()
{

	bool useRestriction = ui_->restrict_radioButton->isChecked();
	buw::vector2d start = buw::vector2d(std::numeric_limits<double>::min());
	buw::vector2d end = buw::vector2d(std::numeric_limits<double>::max());

	if (useRestriction)
	{
		start.x() = ui_->startX_LineEdit->text().toDouble();
		start.y() = ui_->startY_LineEdit->text().toDouble();

		end.x() = ui_->endX_LineEdit->text().toDouble();
		end.y() = ui_->endY_LineEdit->text().toDouble();
	}

	std::string filename = ui_->lineEdit->text().toUtf8().constData();

	buw::ReferenceCounted<buw::ImportXYZ> ia = std::make_shared<buw::ImportXYZ>(filename, start, end);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().execute(ia);

	hide();
	
}

