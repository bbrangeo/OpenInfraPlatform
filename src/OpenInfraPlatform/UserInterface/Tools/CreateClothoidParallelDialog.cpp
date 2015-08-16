/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateClothoidParallelDialog.h"

OpenInfraPlatform::UserInterface::CreateClothoidParallelDialog::CreateClothoidParallelDialog(QWidget *parent /*= nullptr*/) :
	ui_(new Ui::CreateClothoidParallel),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);
}

OpenInfraPlatform::UserInterface::CreateClothoidParallelDialog::~CreateClothoidParallelDialog()
{

}

void OpenInfraPlatform::UserInterface::CreateClothoidParallelDialog::on_pushButtonGenerate_clicked()
{
	QString s = ui_->lineEdit_width->text();
	width = s.toDouble();
	s = ui_->lineEdit_distance->text();
	distance = s.toDouble();
	if (ui_->radioButton_sameA->isChecked())
	{
		sameA = true;
		exactly=false;
	}
	if (ui_->radioButton_exactly->isChecked())
	{
		sameA = false;
		exactly=true;
	}
	hide();
}

void OpenInfraPlatform::UserInterface::CreateClothoidParallelDialog::on_pushButtonCancel_clicked()
{
	hide();
}
