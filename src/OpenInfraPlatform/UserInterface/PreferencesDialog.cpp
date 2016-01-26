/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "PreferencesDialog.h"

#include "OpenInfraPlatform/DataManagement/Data.h"

#include <QTranslator>

OpenInfraPlatform::UserInterface::PreferencesDialog::PreferencesDialog(OpenInfraPlatform::UserInterface::View* view, QWidget *parent /*= nullptr*/) :
	ui_(new Ui::PreferencesDialog),
	QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint),
	view_(view),
	translator_(new QTranslator())
{
	ui_->setupUi(this);

	colorPickerWidget_ = new ColorPickerWidget(this);

	ui_->verticalLayout_2->insertWidget(1, colorPickerWidget_);

	QObject::connect(colorPickerWidget_,
		SIGNAL(colorChanged(QColor)),
		this,
		SLOT(clearColorChanged(QColor)));

	infraCameraController_ = view_->getInfraCameraController();

	ui_->doubleSpinBoxAnimationTime->setValue(infraCameraController_->getInterpolationTime());
	ui_->doubleSpinBoxNearPlane->setValue(infraCameraController_->getCamera()->frustum().nearPlane());
	ui_->doubleSpinBoxFarPlane->setValue(infraCameraController_->getCamera()->frustum().farPlane());


	ui_->comboBoxRenderSystem->addItem("Direct3D 11");
	ui_->comboBoxRenderSystem->addItem("OpenGL 4.x");

	connect(ui_->comboBoxRenderSystem, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onComboBoxRenderSystem_currentIndexChanged(const QString &)));

	createLanguageMenu();
	connect(ui_->comboBoxLanguage, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onComboBoxLanguage_currentIndexChanged(const QString &)));
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::clearColorChanged( const QColor &col )
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().setClearColor(
		buw::color3f(col.red() / 255.0f, col.green() / 255.0f, col.blue() / 255.0f)
	);
}

OpenInfraPlatform::UserInterface::PreferencesDialog::~PreferencesDialog()
{
	delete colorPickerWidget_;
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::changeEvent(QEvent* evt) 
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

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_checkBoxGradientClear_clicked( bool checked )
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().enableGradientClear(checked);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_checkBoxShowGrid_clicked( bool checked )
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().enableDrawGrid(checked);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_checkBoxShowReferenceCoordinateSystem_clicked( bool checked )
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().enableShowReferenceCoordinateSystem(checked);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_checkBoxSkybox_clicked( bool checked )
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().enableSkybox(checked);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_checkBoxShowViewCube_clicked(bool checked)
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().showViewCube(checked);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_doubleSpinBoxAlignmentLineWidth_valueChanged(double i)
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().setAlignmentLineWidth(i);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_checkBoxShowFrameTimes_clicked(bool checked)
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().setShowFrameTimes(checked);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_doubleSpinBoxAnimationTime_valueChanged(double value)
{
	infraCameraController_->setInterpolationTime(value);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_doubleSpinBoxNearPlane_valueChanged(double value)
{
	infraCameraController_->getCamera()->frustum().nearPlane(value);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::on_doubleSpinBoxFarPlane_valueChanged(double value)
{
	infraCameraController_->getCamera()->frustum().farPlane(value);
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::onComboBoxRenderSystem_currentIndexChanged(const QString & text)
{
	QMessageBox::information(nullptr, "Blueform", tr("Changing the render system setting will take affect after restarting the application."));
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::onComboBoxLanguage_currentIndexChanged(const QString& text)
{
	static const QString qmPath = "Data/translations";
	
	qApp->removeTranslator(translator_);

	if (translator_->load(text, qmPath))
	{	
		qApp->installTranslator(translator_);		
	}
}

void OpenInfraPlatform::UserInterface::PreferencesDialog::createLanguageMenu()
{
	auto translationDir = QDir("Data/translations", "*.qm");
	for (auto f : translationDir.entryInfoList(QDir::Files))
	{
		ui_->comboBoxLanguage->addItem(f.baseName());
	}

	// just use English as default
	// b/c the above sorts alphabetically, thus text and lang do not match
	ui_->comboBoxLanguage->setCurrentText("English");
}