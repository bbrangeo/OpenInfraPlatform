/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateLineArcArcArcLineDialog.h"

OpenInfraPlatform::UserInterface::CreateLineArcArcArcLineDialog::CreateLineArcArcArcLineDialog(QWidget *parent /*= nullptr*/) :
ui_(new Ui::CreateLineArcArcArcLine),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);
}

OpenInfraPlatform::UserInterface::CreateLineArcArcArcLineDialog::~CreateLineArcArcArcLineDialog()
{

}

void OpenInfraPlatform::UserInterface::CreateLineArcArcArcLineDialog::changeEvent(QEvent* evt)
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

void OpenInfraPlatform::UserInterface::CreateLineArcArcArcLineDialog::on_pushButtonGenerate_clicked()
{
	QString s = ui_->lineEdit_R2->text();
	R2 = s.toDouble();
	if (ui_->radioButton_213->isChecked())
	{
		r213 = true;
	}
	if (ui_->radioButton_25155->isChecked())
	{
		r213 = false;
	}
	if (ui_->radioButton_ral->isChecked())
	{
		ral = true;
	}
	if (ui_->radioButton_noral->isChecked())
	{
		ral = false;
	}
	hide();
}

void OpenInfraPlatform::UserInterface::CreateLineArcArcArcLineDialog::on_pushButtonCancel_clicked()
{
	hide();
}
