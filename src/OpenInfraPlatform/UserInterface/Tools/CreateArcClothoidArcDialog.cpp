/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateArcClothoidArcDialog.h"

OpenInfraPlatform::UserInterface::CreateArcClothoidArcDialog::CreateArcClothoidArcDialog(QWidget *parent /*= nullptr*/) :
	ui_(new Ui::CreateArcClothoidArc),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);
	 ui_->labelPicture->setPixmap(QPixmap(":/ACA.svg"));
	 ui_->labelPicture->show();

}

OpenInfraPlatform::UserInterface::CreateArcClothoidArcDialog::~CreateArcClothoidArcDialog()
{

}

void OpenInfraPlatform::UserInterface::CreateArcClothoidArcDialog::on_pushButtonGenerate_clicked()
{
	hide();
	std::string message;
	buw::vector2d  Vect, x_axis = { 1.0, 0.0 }, cloth_start_dir, theostartPoint, center[2], start[2], end[2];
	double L[2], tau[2], R_inserted, deltaL, R[2], width, sig = 1;
	double distance, gon = M_PI / 200, phi1, phi2, A;
	bool clockClo = false, Radius1;
	QString s = ui_->lineEdit_R->text();
	R_inserted = s.toDouble();
	s = ui_->lineEdit_A->text();
	A = s.toDouble();
	s = ui_->lineEdit_phi1->text();
	phi1 = s.toDouble()*gon;
	s = ui_->lineEdit_phi2->text();
	phi2 = s.toDouble()*gon;
	s = ui_->lineEdit_L->text();
	deltaL = s.toDouble();
	if (ui_->radioButton_line1->isChecked())
	{
		Radius1 = true;
	}
	if (ui_->radioButton_line2->isChecked())
	{
		Radius1 = false;
	}
	s = ui_->lineEdit_d->text();
	distance = s.toDouble();
	s = ui_->lineEdit_c->text();
	width = s.toDouble();
	if (isInsertZero(R_inserted, 1, 1, 1, 1, 1, message) == 0 || isAngleInBorders(phi1, phi2, message) == 0 || are2Points(points_.size(), message) == 0 || isInsertNotZero(A, 1, deltaL, message) == 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), QString::fromStdString(message));
		return;
	}
	Vect = points_[1].xy() - points_[0].xy();
	double drawnR = Vect.length();
	R[1] = drawnR;
	R[0] = R_inserted;
	if (Radius1 == true)
	{
		R[0] = drawnR;
		R[1] = R_inserted;
	}
	if (A == 0 && deltaL != 0)
	{
		A = sqrt((R[0] * R[1] / (std::abs(R[0] - R[1])))*deltaL);
	}
	if (R[0] < R[1])
	{
		sig = -1;
		clockClo = true;
	}
	compute_L_tau(L[0], L[1], tau[0], tau[1], A, A, R[0], R[1]);
	if (isClothoidInBorder(tau[0], tau[1], M_PI, message) == 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), QString::fromStdString(message));
		return;
	}
	buw::vector2d  delta_cloth_dir = buw::createRotationZ22d(sig*M_PI / 2)*Vect.normalize();
	double delta_cloth_angle = buw::calculateAngleBetweenVectors(x_axis, delta_cloth_dir);
	if (Radius1 == true)
	{
		give2Points(center[0], end[0], Vect, points_[0].xy(), points_[1].xy(), offset_);
		start[0] = center[0] + buw::createRotationZ22d(-phi1)* Vect;
		theostartPoint = end[0] - buw::createRotationZ22d(delta_cloth_angle - sig*tau[0])*relCloEnd(L[0], A, sig);
		cloth_start_dir = buw::createRotationZ22d(-sig*tau[0])*delta_cloth_dir;
		start[1] = theostartPoint + buw::createRotationZ22d(delta_cloth_angle - sig*tau[0])*relCloEnd(L[1], A, sig);
		center[1] = start[1] + R[1] * buw::createRotationZ22d(delta_cloth_angle + sig*(tau[1] - tau[0] + M_PI / 2))*x_axis;
		end[1] = center[1] + buw::createRotationZ22d(phi2)* (start[1] - center[1]);
	}
	else
	{
		give2Points(center[1], start[1], Vect, points_[0].xy(), points_[1].xy(), offset_);
		end[1] = center[1] + buw::createRotationZ22d(phi2)* Vect;
		theostartPoint = start[1] - buw::createRotationZ22d(delta_cloth_angle - sig*tau[1])*relCloEnd(L[1], A, sig);
		cloth_start_dir = buw::createRotationZ22d(-sig*tau[1])*delta_cloth_dir;
		end[0] = theostartPoint + buw::createRotationZ22d(delta_cloth_angle - sig*tau[1])*relCloEnd(L[0], A, sig);
		center[0] = end[0] + R[0] * buw::createRotationZ22d(delta_cloth_angle + sig*(tau[0] - tau[1] + M_PI / 2))*x_axis;
		start[0] = center[0] + buw::createRotationZ22d(-phi1)* (end[0] - center[0]);
	}
	GeneralArcClothoidArc(cloth_start_dir, theostartPoint, clockClo, center[0], center[1], start[0], start[1], end[0], end[1], width, distance,Radius1, sig, A, R[0], R[1]);
}

void OpenInfraPlatform::UserInterface::CreateArcClothoidArcDialog::on_pushButtonCancel_clicked()
{
	hide();
}
