/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "XYZImportDialog.h"

#include "OpenInfraPlatform/DataManagement/Data.h"
#include <iostream>
#include "buw.BlueEngine.h"
#include <vector>

#include "OpenInfraPlatform/DataManagement/Command/ImportXYZ.h"


OpenInfraPlatform::UserInterface::XYZImportDialog::XYZImportDialog( QWidget *parent /*= nullptr*/ ) :
    ui_(new Ui::XYZImportDialog),
    QDialog(parent, Qt::WindowTitleHint|Qt::WindowCloseButtonHint)
{
    ui_->setupUi(this);
}

OpenInfraPlatform::UserInterface::XYZImportDialog::~XYZImportDialog()
{

}

void OpenInfraPlatform::UserInterface::XYZImportDialog::changeEvent(QEvent* evt) 
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

void OpenInfraPlatform::UserInterface::XYZImportDialog::on_pushButtonBrowse_clicked()
{
    QString openFile = QFileDialog::getOpenFileName(this, tr("Open File"),QDir::currentPath(),tr("XYZ Files (*.xyz);;Text files (*.txt)"));
    std::string utf8_text_file = openFile.toUtf8().constData();

    ui_->lineEdit->setText(openFile);
}

void OpenInfraPlatform::UserInterface::XYZImportDialog::on_pushButtonImport_clicked()
{
    double x, y, z;
    std::vector<buw::vector3d> positions;

	bool useRestriction = ui_->restrict_radioButton->isChecked();
	buw::vector2d start, end;

	if (useRestriction)
	{
		start.x() = ui_->startX_LineEdit->text().toDouble();
		start.y() = ui_->startY_LineEdit->text().toDouble();

		end.x() = ui_->endX_LineEdit->text().toDouble();
		end.y() = ui_->endY_LineEdit->text().toDouble();
	}

	// read the data
    std::string utf8_text_file = ui_->lineEdit->text().toUtf8().constData();

    buw::SimpleLexer sl(utf8_text_file.c_str());

    if (!utf8_text_file.empty())
    {
        sl.SetIgnoreWhitespace(true);
        buw::Token token;

        // read token
		bool eof = false;
        while(sl.ReadToken(token))
        {
            while ( token.GetType() == buw::eTokenType::New_Line )
            {
                if(!sl.ReadToken(token))
				{ 
					eof = true;
					break;
				}
            }

			if (eof)
			{
				break;
			}

			BLUE_ASSERT(token.GetType() == buw::eTokenType::Float ||
				token.GetType() == buw::eTokenType::Integer,
				"Invalid token");
			x = token.GetDoubleValue();

            sl.ReadToken(token);
			BLUE_ASSERT(token.GetType() == buw::eTokenType::Float ||
				token.GetType() == buw::eTokenType::Integer,
				"Invalid token");
			y = token.GetDoubleValue();

            sl.ReadToken(token);
			BLUE_ASSERT(token.GetType() == buw::eTokenType::Float ||
				token.GetType() == buw::eTokenType::Integer,
				"Invalid token");
			z = token.GetDoubleValue();

			buw::vector3d tempv(x, y, z);
			if (useRestriction)
			{
				if (tempv.x() < start.x() || tempv.y() < start.y() ||
					tempv.x() > end.x() || tempv.y() > end.y())
					continue;
			}

            positions.push_back(tempv);
        }
    }
	
	buw::ImportXYZ::Ptr ia = std::make_shared<buw::ImportXYZ>(positions);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().execute(ia);

	hide();
}

