/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateLineArcArcLineDialog.h"

OpenInfraPlatform::UserInterface::CreateLineArcArcLineDialog::CreateLineArcArcLineDialog(QWidget *parent /*= nullptr*/) :
	ui_(new Ui::CreateLineArcArcLine)
	
{
	ui_->setupUi(this);

}

OpenInfraPlatform::UserInterface::CreateLineArcArcLineDialog::~CreateLineArcArcLineDialog()
{

}

void OpenInfraPlatform::UserInterface::CreateLineArcArcLineDialog::changeEvent(QEvent* evt) 
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

void OpenInfraPlatform::UserInterface::CreateLineArcArcLineDialog::on_pushButtonGenerate_clicked()
{
	QString s = ui_->lineEdit_R1->text();
	R1 = s.toDouble();
	s = ui_->lineEdit_R2->text();
	R2 = s.toDouble();

	hide();
}

void OpenInfraPlatform::UserInterface::CreateLineArcArcLineDialog::on_pushButtonCancel_clicked()
{
	hide();
}
