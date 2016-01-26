/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateArcClothoidClothoidArcDialog.h"

OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcDialog::CreateArcClothoidClothoidArcDialog(QWidget *parent /*= nullptr*/) :
ui_(new Ui::CreateArcClothoidClothoidArc),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);
	 ui_->labelPicture->setPixmap(QPixmap(":/ACCA.svg"));
	 ui_->labelPicture->show();
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
	hide();
	std::string message;
	int sig = 1;
	double sigu = 1, cloth_start_angle, A[2], phi[2], L[2], tau[2], R[2], helpangle[2], width, distance, gon = M_PI / 200;
	buw::vector2d startPoint, Vect, x_axis = { 1.0, 0.0 }, center[2], end[2], RelCloEnd[2];
	bool s_form, UseNoLines = false;
	QString s = ui_->lineEdit_R1->text();
	R[0] = s.toDouble();
	s = ui_->lineEdit_R2->text();
	R[1] = s.toDouble();
	s = ui_->lineEdit_A1->text();
	A[0] = s.toDouble();
	s = ui_->lineEdit_A2->text();
	A[1] = s.toDouble();
	s = ui_->lineEdit_phi1->text();
	phi[0] = s.toDouble()* gon;
	s = ui_->lineEdit_phi2->text();
	phi[1] = s.toDouble()* gon;
	if (ui_->radioButton_S->isChecked())
	{
		s_form = true;
	}
	if (ui_->radioButton_Z->isChecked())
	{
		s_form = false;
	}
	s = ui_->lineEdit_d->text();
	distance = s.toDouble();
	s = ui_->lineEdit_c->text();
	width = s.toDouble();
	compute_L_tau(L[0], L[1], tau[0], tau[1], A[0], A[1], R[0], R[1]);
	if (isClothoidInBorder(tau[0], tau[1], M_PI, message) == 0 || are2Points(points_.size(), message) == 0 || isAngleInBorders(phi[0], phi[1], message) == 0 || isInsertZero(1, 1, R[1], R[0], A[0], A[1], message) == 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), QString::fromStdString(message));
		return;
	}
	give2Points(startPoint, RelCloEnd[0], Vect, points_[0].xy(), points_[1].xy(),offset_);// we use RelCloEnd[0] just because it will be changed later
	cloth_start_angle = buw::calculateAngleBetweenVectors(x_axis, Vect);
	if (s_form == true)
	{
		sig = -1;
	}
	for (int i = 0; i < 2; i++)
	{
		helpangle[i] = cloth_start_angle + sig* (tau[i] + sigu* M_PI / 2);
		RelCloEnd[i] = relCloEnd(L[i], A[i], sig);
		end[i] = startPoint - sigu*buw::createRotationZ22d(cloth_start_angle)*RelCloEnd[i];
		center[i] = end[i] - R[i] * buw::createRotationZ22d(helpangle[i])* x_axis;
		sigu = -1;
	}
	GeneralArcClothoidClothoidArc(Vect, startPoint, end[0], center[0], end[1], center[1], width, distance, UseNoLines, sig, phi[0], phi[1], A[0], A[1], R[0], R[1]);
}

void OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcDialog::on_pushButtonCancel_clicked()
{
	hide();
}
