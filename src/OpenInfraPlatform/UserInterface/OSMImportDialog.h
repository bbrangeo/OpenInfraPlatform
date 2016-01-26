#pragma once
#include "ui_OSMImportDialog.h"
#include <string>
#include <vector>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{

		class OSMImportDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			OSMImportDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~OSMImportDialog();

			void setFilename(const std::string& filename);

			void setFilterList(const std::vector<std::string>& filter);
			std::vector<std::string> getFilterList();

			void setModes(const std::vector<std::string>& modes);
			int getMode();

		private Q_SLOTS:
			void addItem(const std::string& label = "", bool select = true);
			void removeItem(QListWidgetItem* item);
		
			void on_currentFilterItem_changed(QListWidgetItem* item);

		private:
			Ui::OSMImportDialog*	ui_;
			QListWidgetItem* lastItem_;
			bool bIgnoreChanges_;;
		};
	}
}