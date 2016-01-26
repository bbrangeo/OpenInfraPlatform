/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateClothoidDialog.h"

OpenInfraPlatform::UserInterface::CreateClothoidDialog::CreateClothoidDialog(QWidget *parent /*= nullptr*/) :
	ui_(new Ui::CreateClothoid),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	ui_->setupUi(this);
	ui_->labelPicture->setPixmap(QPixmap(":/LClothoid.svg"));
	ui_->labelPicture->show();
}

OpenInfraPlatform::UserInterface::CreateClothoidDialog::~CreateClothoidDialog()
{

}

void OpenInfraPlatform::UserInterface::CreateClothoidDialog::changeEvent(QEvent* evt)
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

void OpenInfraPlatform::UserInterface::CreateClothoidDialog::on_pushButtonGenerate_clicked()
{
	hide();
	double Ri, Ro, Ai, Ao, A, R, L, width, distance;
	bool clocky =false, UseNoLines = false;
	buw::vector2d CloStartI, CloStartO, x_axis = { 1.0, 0.0 }, startPoint, lineStart, cloth_start_dir;
	std::string message;
	QString s = ui_->lineEdit_R->text();
	R = s.toDouble();
	s = ui_->lineEdit_A->text();
	A = s.toDouble();
	s = ui_->lineEdit_L->text();
	L = s.toDouble();
	s = ui_->lineEdit_d->text();
	distance = s.toDouble();
	s = ui_->lineEdit_c->text();
	width = s.toDouble();
	if (ui_->radioButton_clock->isChecked())
	{
		clocky = true;
	}
	if (ui_->radioButton_counter->isChecked())
	{
		clocky = false;
	}
	if (points_.size() < 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least two alignment-points and then call this function again");
		return;
	}
	if (isInsertNotZero(A, R, L, message) == 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), QString::fromStdString(message));
		return;
	}
	int sig = 1;
	if (clocky == true)
	{
		sig = -sig;
	}
	if (R == 0)
	{
		R = A*A / L;
	}
	if (L == 0)
	{
		L = A*A / R;
	}
	if (A == 0)
	{
		A = sqrt(L* R);
	}
	give2Points(lineStart, startPoint, cloth_start_dir, points_[points_.size() - 2].xy(), points_[points_.size() - 1].xy(),offset_);// attention this looks wrong but is rigth, because lineStart is startpoint of line
	if (isClothoidInBorder(L / (2 * R), 1, M_PI, message) == 0 || areErrorsForParallelClo(L, A, width, distance, UseNoLines, message) == 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), QString::fromStdString(message));
		return;
	}
	makeClothoid(0.0, R, A, startPoint, cloth_start_dir, clocky);
	buw::ReferenceCounted<buw::HorizontalAlignment2D> hb = std::make_shared<buw::HorizontalAlignment2D>();
	buw::ReferenceCounted<buw::HorizontalAlignment2D> ha = std::make_shared<buw::HorizontalAlignment2D>();
	if (width > 0)
	{
		double start_angle = buw::calculateAngleBetweenVectors(x_axis, cloth_start_dir);
		buw::vector2d starthelp = width*buw::createRotationZ22d(start_angle + sig* M_PI / 2)*x_axis;
		buw::vector2d startline_i = lineStart + starthelp;
		buw::vector2d startline_o = lineStart - starthelp;
		if (UseNoLines == true)
		{
			parallelClo(CloStartI, CloStartO, Ri, Ro, Ai, Ao, A, width, R, startPoint, cloth_start_dir, sig);
			makeClothoid(0.0, Ri, Ai, CloStartI, cloth_start_dir, clocky);
			makeClothoid(0.0, Ro, Ao, CloStartO, cloth_start_dir, clocky);
			makeOne3dLine(startline_i, CloStartI);
			makeOne3dLine(startline_o, CloStartO);
		}
		else
		{
			double loopend = L - distance - 0.00000001;
			buw::vector2d FirstCloPoI = startPoint + starthelp;
			buw::vector2d FirstCloPoO = startPoint - starthelp;
			makeOne3dLine(startline_i, FirstCloPoI);
			makeOne3dLine(startline_o, FirstCloPoO);
			buw::vector2d p_endhelp = width*buw::createRotationZ22d(start_angle + sig* (M_PI / 2 + A*A / (R*R * 2)))*x_axis;// tau=A*A/(R*R*2)
			buw::vector2d endPoint = absCloEnd(startPoint, cloth_start_dir, L, A, sig);
			buw::vector2d LastCloPoI = endPoint + p_endhelp;
			buw::vector2d LastCloPoO = endPoint - p_endhelp;
			make2ClothByConnectLin(0,loopend, distance, A, width, startPoint, cloth_start_dir, sig, LastCloPoI, LastCloPoO);
		}
	}
	buw::vector2d startx = buw::vector2d(points_[points_.size()-2].x(), points_[points_.size() -2].y()) + offset_;
	buw::vector2d endx = buw::vector2d(points_[points_.size()-1].x(), points_[points_.size() -1].y()) + offset_;
	makeOne3dLine(startx, endx);
	for (int i = 0; i < points_.size() - 2; i++)
	{
		buw::vector2d start = buw::vector2d(points_[i].x(), points_[i].y()) + offset_;
		buw::vector2d end = buw::vector2d(points_[i + 1].x(), points_[i + 1].y()) + offset_;
		buw::ReferenceCounted<buw::HorizontalAlignmentElement2DLine> line = std::make_shared<buw::HorizontalAlignmentElement2DLine>(start, end);
		ha->addElement(line);
	}
	make3DLine(ha);
}

void OpenInfraPlatform::UserInterface::CreateClothoidDialog::on_pushButtonCancel_clicked()
{
	hide();
}
