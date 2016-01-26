﻿/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateArcClothoidArcMeth2Dialog.h"

OpenInfraPlatform::UserInterface::CreateArcClothoidArcMeth2Dialog::CreateArcClothoidArcMeth2Dialog(QWidget *parent /*= nullptr*/) :
	ui_(new Ui::CreateArcClothoidArcMeth2),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);
	 ui_->labelPicture->setPixmap(QPixmap(":/ACA2.svg"));
	 ui_->labelPicture->show();
}

OpenInfraPlatform::UserInterface::CreateArcClothoidArcMeth2Dialog::~CreateArcClothoidArcMeth2Dialog()
{

}

void OpenInfraPlatform::UserInterface::CreateArcClothoidArcMeth2Dialog::on_pushButtonGenerate_clicked()
{
	hide();
	std::string message;
	buw::vector2d  iter_point, M2M1, x_axis = { 1.0, 0.0 }, cloth_start_dir, theostartPoint, center[2], start[2], end[2];
	double iter_angle, ny, R[2], L[2], tau[2], gon = M_PI / 200, Dtest, A, width;
	double distance, phi1, phi2, sig = 1;
	int count_loops = 0;
	bool clockClo = false;
	QString s = ui_->lineEdit_R1->text();
	R[0] = s.toDouble();
	s = ui_->lineEdit_R2->text();
	R[1] = s.toDouble();
	s = ui_->lineEdit_phi1->text();
	phi1 = s.toDouble()*gon;
	s = ui_->lineEdit_phi2->text();
	phi2 = s.toDouble()*gon;
	s = ui_->lineEdit_d->text();
	distance = s.toDouble();
	s = ui_->lineEdit_c->text();
	width = s.toDouble();
	if (isInsertZero(R[0], R[1], 1, 1, 1, 1, message) == 0 || are2Points(points_.size(), message) == 0 || isAngleInBorders(phi1, phi2, message) == 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), QString::fromStdString(message));
		return;
	}
	if (R[0] == R[1])
	{
		QMessageBox::warning(this, QApplication::applicationName(), "You have inserted for R1 a value equal to R2. Please correct your inserts.");
		return;
	}
	give2Points(center[0], center[1], M2M1, points_[0].xy(), points_[1].xy(), offset_);
	ny = buw::calculateAngleBetweenVectors(x_axis, M2M1);
	if ((std::abs(R[0] - R[1]) - M2M1.length()) < 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please reduce the length of drawn line or change your inserts so that |R1-R2| > length of drawn line.");
		return;
	}
	A = (R[0] + R[1]) / 2;
	Dtest = iteration_ACA(A, R[0], R[1]); // Dtest is the computed M2M1
	while (std::abs(Dtest - M2M1.length()) > 0.00005) // loop generates A for the creation of Arc-Clothoid-Arc by a differential-quotient
	{
		count_loops++;
		if (count_loops == 10000)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Please change inserts because otherwise no computation possible.");
			return;
		}
		double A01 = A + 0.00001;
		double D01 = iteration_ACA(A01, R[0], R[1]);
		A = A + (M2M1.length() - Dtest)*0.00001 / (D01 - Dtest);
		Dtest = iteration_ACA(A, R[0], R[1]);
	}
	compute_L_tau(L[0], L[1], tau[0], tau[1], A, A, R[0], R[1]);
	double  deltaL = std::abs(L[1] - L[0]);
	if (isClothoidInBorder(tau[1], tau[0], M_PI, message) == 0 || areErrorsForParallelClo(deltaL, A, width, distance, false, message) == 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), QString::fromStdString(message));
		return;
	}
	iter_point = buw::createRotationZ22d(tau[0])*buw::vector2d(0, -R[0]) + relCloEnd(L[1], A, 1) - relCloEnd(L[0], A, 1) + buw::createRotationZ22d(tau[1]) *buw::vector2d(0.0, R[1]);
	iter_angle = calculateAngleBetweenVectors(x_axis, iter_point);
	double cloth_start_angle = ny - iter_angle;
	double delta_cloth_angle = cloth_start_angle+tau[0];
	if (R[0] < R[1])
	{
		sig = -1;
		clockClo = true;
		cloth_start_angle = ny +iter_angle;
		delta_cloth_angle = cloth_start_angle - tau[1];
	}
	cloth_start_dir = buw::createRotationZ22d(cloth_start_angle)*x_axis;
	end[0] = center[0] + buw::createRotationZ22d(sig*tau[0] + cloth_start_angle)*buw::vector2d(0, -sig*R[0]);
	start[0] = center[0] + buw::createRotationZ22d(-phi1)* (end[0] - center[0]);
	theostartPoint = end[0] - buw::createRotationZ22d(cloth_start_angle)*relCloEnd(L[0], A, sig);
	start[1] = theostartPoint + buw::createRotationZ22d(cloth_start_angle)*relCloEnd(L[1], A, sig);
	end[1] = center[1] + buw::createRotationZ22d(phi2)* (start[1] - center[1]);
	GeneralArcClothoidArc(cloth_start_dir, theostartPoint, clockClo, center[0], center[1], start[0], start[1], end[0], end[1], width, distance,true, sig, A, R[0], R[1]);
}

void OpenInfraPlatform::UserInterface::CreateArcClothoidArcMeth2Dialog::on_pushButtonCancel_clicked()
{
	hide();
}
