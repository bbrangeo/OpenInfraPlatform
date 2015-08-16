/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateLineClothoidClothoidLineDialog.h"


OpenInfraPlatform::UserInterface::CreateLineClothoidClothoidLineDialog::CreateLineClothoidClothoidLineDialog(QWidget *parent /*= nullptr*/) :
ui_(new Ui::CreateLineClothoidClothoidLine),
QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui_->setupUi(this);
}

OpenInfraPlatform::UserInterface::CreateLineClothoidClothoidLineDialog::~CreateLineClothoidClothoidLineDialog()
{

}

void OpenInfraPlatform::UserInterface::CreateLineClothoidClothoidLineDialog::changeEvent(QEvent* evt) 
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

void OpenInfraPlatform::UserInterface::CreateLineClothoidClothoidLineDialog::on_pushButtonGenerate_clicked()
{
	QString s = ui_->lineEdit_R->text();
	R = s.toDouble();
	s = ui_->lineEdit_A1->text();
	A1 = s.toDouble();
	s = ui_->lineEdit_A2->text();
	A2 = s.toDouble();
	hide();
}

void OpenInfraPlatform::UserInterface::CreateLineClothoidClothoidLineDialog::on_pushButtonCancel_clicked()
{
	hide();
}