/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateArcClothoidClothoidArcDialog.h"

OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcDialog::CreateArcClothoidClothoidArcDialog(QWidget *parent /*= nullptr*/) :
ui_(new Ui::CreateArcClothoidClothoidArc),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);

}

OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcDialog::~CreateArcClothoidClothoidArcDialog()
{

}

void OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcDialog::changeEvent(QEvent* evt)
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

void OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcDialog::on_pushButtonGenerate_clicked()
{
	QString s = ui_->lineEdit_R1->text();
	R1 = s.toDouble();
	s = ui_->lineEdit_R2->text();
	R2 = s.toDouble();
	s = ui_->lineEdit_A1->text();
	A1 = s.toDouble();
	s = ui_->lineEdit_A2->text();
	A2 = s.toDouble();
	s = ui_->lineEdit_phi1->text();
	phi1 = s.toDouble();
	s = ui_->lineEdit_phi2->text();
	phi2 = s.toDouble();
	if (ui_->radioButton_S->isChecked())
	{
		s_form = true;
	}
	if (ui_->radioButton_Z->isChecked())
	{
		s_form = false;
	}
	hide();
	hide();
}

void OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcDialog::on_pushButtonCancel_clicked()
{
	hide();
}
