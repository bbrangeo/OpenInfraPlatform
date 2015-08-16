/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateArcClothoidClothoidArcMeth2Dialog.h"

OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcMeth2Dialog::CreateArcClothoidClothoidArcMeth2Dialog(QWidget *parent /*= nullptr*/) :
ui_(new Ui::CreateArcClothoidClothoidArcMeth2),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);

}

OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcMeth2Dialog::~CreateArcClothoidClothoidArcMeth2Dialog()
{

}

void OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcMeth2Dialog::on_pushButtonGenerate_clicked()
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
	s = ui_->lineEdit_delta->text();
	psi = s.toDouble();
	hide();
	hide();
}

void OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcMeth2Dialog::on_pushButtonCancel_clicked()
{
	hide();
}
