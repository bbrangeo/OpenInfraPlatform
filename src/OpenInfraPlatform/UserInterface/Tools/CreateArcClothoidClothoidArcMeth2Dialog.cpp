/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateArcClothoidClothoidArcMeth2Dialog.h"

OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcMeth2Dialog::CreateArcClothoidClothoidArcMeth2Dialog(QWidget *parent /*= nullptr*/) :
ui_(new Ui::CreateArcClothoidClothoidArcMeth2),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);
	 ui_->labelPicture->setPixmap(QPixmap(":/ACCA2.svg"));
	 ui_->labelPicture->show();
}

OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcMeth2Dialog::~CreateArcClothoidClothoidArcMeth2Dialog()
{

}

void OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcMeth2Dialog::on_pushButtonGenerate_clicked()
{
	hide();
	std::string message;
	int count_loops = 0, sig = 1;
	buw::vector2d cloth_dir, iter_point, M2M1, startPoint, x_axis = { 1.0, 0.0 }, RelCloEnd[2], center[2], end[2];
	double sigu = 1, phi[2], cloth_start_angle, iter_angle, ny, gon = M_PI / 200, L[2], R[2], tau[2], A[2], AA[2], Atest, Dtest;
	double width, distance;
	bool s_form;

	QString s = ui_->lineEdit_R1->text();
	R[0] = s.toDouble();
	s = ui_->lineEdit_R2->text();
	R[1] = s.toDouble();
	s = ui_->lineEdit_A1->text();
	AA[0] = s.toDouble();
	s = ui_->lineEdit_A2->text();
	AA[1] = s.toDouble();
	s = ui_->lineEdit_phi1->text();
	phi[0] = s.toDouble()*gon;
	s = ui_->lineEdit_phi2->text();
	phi[1] = s.toDouble()*gon;
	if (ui_->s_form->isChecked())
	{
		s_form = true;
	}
	if (ui_->z_form->isChecked())
	{
		s_form = false;
	}
	s = ui_->lineEdit_d_2->text();
	distance = s.toDouble();
	s = ui_->lineEdit_c_2->text();
	width = s.toDouble();
	if (are2Points(points_.size(), message) == 0 || isInsertZero(R[0], R[1], 1, 1, 1, 1, message) == 0 || isInsertNotZero(AA[0], AA[1], 1, message) == 0 || isAngleInBorders(phi[0], phi[1], message) == 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), QString::fromStdString(message));
		return;
	}
	give2Points(center[0], center[1], M2M1, points_[0].xy(), points_[1].xy(),offset_);
	ny = calculateAngleBetweenVectors(x_axis, M2M1);
	if ((M2M1.length() - R[0] - R[1]) < 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please change inserts so that R1 + R2 < length of drawn line.");
		return;
	}
	A[0] = AA[0];
	A[1] = AA[1];
	Atest = (R[0] + R[1]) / 2;
	insertA_for_ACCA2(AA[0], AA[1], A[0], A[1], Atest);
	Dtest = iteration_ACCA(A[0], A[1], R[0], R[1]);// Dtest is the computed M2M1
	while (std::abs(Dtest - M2M1.length()) > 0.0005)// loop generates the values A[0] and A[1] for the creation of Arc-Clothoid-Clothoid-Arc by a differential-quotient
	{
		count_loops++;
		if (count_loops == 10000)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Please change inserts because otherwise no computation possible.");
			return;
		}
		double A01 = Atest + 0.00001;
		insertA_for_ACCA2(AA[0], AA[1], A[0], A[1], A01);
		double D01 = iteration_ACCA(A[0], A[1], R[0], R[1]);
		Atest = Atest + (M2M1.length() - Dtest)*0.00001 / (D01 - Dtest);
		insertA_for_ACCA2(AA[0], AA[1], A[0], A[1], Atest);
		Dtest = iteration_ACCA(A[0], A[1], R[0], R[1]);
	}
	compute_L_tau(L[0], L[1], tau[0], tau[1], A[0], A[1], R[0], R[1]);
	iter_point = R[1] * buw::createRotationZ22d(M_PI / 2 + tau[1])*x_axis + relCloEnd(L[1], A[1], 1) + R[0] * buw::createRotationZ22d(M_PI / 2 + tau[0])*x_axis + relCloEnd(L[0], A[0], 1);// z-form
	iter_angle = calculateAngleBetweenVectors(x_axis, iter_point);
	if (s_form == true)
	{
		sig = -1;
	}
	cloth_start_angle = ny - sig*iter_angle; // z-form if sig==1
	RelCloEnd[0] = relCloEnd(L[0], A[0], sig);
	RelCloEnd[1] = relCloEnd(L[1], A[1], sig);
	startPoint = center[1] - buw::createRotationZ22d(cloth_start_angle)*RelCloEnd[1] - R[1] * buw::createRotationZ22d(sig*(tau[1] + M_PI / 2) + cloth_start_angle)*x_axis;
	cloth_dir = buw::createRotationZ22d(cloth_start_angle)*x_axis;
	for (int i = 0; i < 2; i++)
	{
		if (isClothoidInBorder(tau[0], tau[1], M_PI, message) == 0 || areErrorsForParallelClo(L[i], A[i], width, distance, false, message) == 0)
		{
			QMessageBox::warning(this, QApplication::applicationName(), QString::fromStdString(message));
			return;
		}
		end[i] = startPoint - sigu*buw::createRotationZ22d(cloth_start_angle)*RelCloEnd[i];
		sigu = -1;
	}
	GeneralArcClothoidClothoidArc(cloth_dir, startPoint, end[0], center[0], end[1], center[1], width, distance, false, sig, phi[0], phi[1], A[0], A[1], R[0], R[1]);
}

void OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcMeth2Dialog::on_pushButtonCancel_clicked()
{
	hide();
}
