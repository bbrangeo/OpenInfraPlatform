/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once

#include <QTextBrowser>
#include <QPushButton>
#include <QEvent>

class HelpBrowser : public QWidget
{
	Q_OBJECT

public:
	HelpBrowser(const QString &path, const QString &page,
		QWidget *parent = 0);

	static void showPage(const QString &page);

private Q_SLOTS:
	void updateWindowTitle();

private:
	QTextBrowser *textBrowser;
	QPushButton *homeButton;
	QPushButton *backButton;
	QPushButton *closeButton;
};

