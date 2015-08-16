/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateClothoidDialog.h"

OpenInfraPlatform::UserInterface::CreateClothoidDialog::CreateClothoidDialog(QWidget *parent /*= nullptr*/) :
	ui_(new Ui::CreateClothoid),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
	 ui_->setupUi(this);
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
	QString s = ui_->lineEdit_R->text();
	R = s.toDouble();
	s = ui_->lineEdit_A->text();
	A = s.toDouble();
	s = ui_->lineEdit_L->text();
	L = s.toDouble();
	if (ui_->radioButton_clock->isChecked())
	{
		clock = true;
	}
	if (ui_->radioButton_counter->isChecked())
	{
		clock = false;
	}
	hide();
}

void OpenInfraPlatform::UserInterface::CreateClothoidDialog::on_pushButtonCancel_clicked()
{
	hide();
}
