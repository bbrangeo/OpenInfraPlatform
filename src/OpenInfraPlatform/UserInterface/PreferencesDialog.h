/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_PreferencesDialog_38da791c_994f_450a_abc1_6676bdf555c4_h
#define OpenInfraPlatform_UserInterface_PreferencesDialog_38da791c_994f_450a_abc1_6676bdf555c4_h

#include "ui_PreferencesDialog.h"
#include "ColorPicker/colorpickerwidget.h"
#include "OpenInfraPlatform/UserInterface/ViewPanel/View.h"
#include "BlueFramework/Engine/Camera/InfraCameraController.h"
#include <QDialog>
#include <boost/noncopyable.hpp>
#include <iostream>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class PreferencesDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			PreferencesDialog(OpenInfraPlatform::UserInterface::View* view, QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~PreferencesDialog();
			
		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void clearColorChanged(const QColor &col);

			void on_checkBoxGradientClear_clicked (bool checked);
			void on_checkBoxShowGrid_clicked (bool checked);
			void on_checkBoxShowReferenceCoordinateSystem_clicked(bool checked);
			void on_checkBoxSkybox_clicked (bool checked);

			void on_checkBoxShowViewCube_clicked (bool checked);
			void on_doubleSpinBoxAlignmentLineWidth_valueChanged(double i);

			void on_checkBoxShowFrameTimes_clicked(bool checked);

			void on_doubleSpinBoxAnimationTime_valueChanged(double value);
			void on_doubleSpinBoxNearPlane_valueChanged(double value);
			void on_doubleSpinBoxFarPlane_valueChanged(double value);

			void onComboBoxRenderSystem_currentIndexChanged(const QString & text);

			void onComboBoxLanguage_currentIndexChanged(const QString & text);

		private:
			void createLanguageMenu();
			
		private:
			Ui::PreferencesDialog*	ui_;
			ColorPickerWidget*		colorPickerWidget_;
			QTranslator*			translator_;

			OpenInfraPlatform::UserInterface::View* view_;
			buw::ReferenceCounted<buw::InfraCameraController>	infraCameraController_;

		}; // end class PreferencesDialog
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::PreferencesDialog;
}

#endif // end define OpenInfraPlatform_UserInterface_PreferencesDialog_38da791c_994f_450a_abc1_6676bdf555c4_h
