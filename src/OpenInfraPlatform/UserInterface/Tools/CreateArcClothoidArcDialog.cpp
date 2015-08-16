/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateArcClothoidArcDialog.h"

OpenInfraPlatform::UserInterface::CreateArcClothoidArcDialog::CreateArcClothoidArcDialog(QWidget *parent /*= nullptr*/) :
	ui_(new Ui::CreateArcClothoidArc),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);
}

OpenInfraPlatform::UserInterface::CreateArcClothoidArcDialog::~CreateArcClothoidArcDialog()
{

}

void OpenInfraPlatform::UserInterface::CreateArcClothoidArcDialog::on_pushButtonGenerate_clicked()
{
	QString s = ui_->lineEdit_R->text();
	R = s.toDouble();
	s = ui_->lineEdit_A->text();
	A = s.toDouble();
	s = ui_->lineEdit_phi1->text();
	phi1 = s.toDouble();
	s = ui_->lineEdit_phi2->text();
	phi2 = s.toDouble();
	s = ui_->lineEdit_L->text();
	L = s.toDouble();
	if (ui_->radioButton_line1->isChecked())
	{
		Radius1 = true;
	}
	if (ui_->radioButton_line2->isChecked())
	{
		Radius1 = false;
	}
	hide();
}

void OpenInfraPlatform::UserInterface::CreateArcClothoidArcDialog::on_pushButtonCancel_clicked()
{
	hide();
}
