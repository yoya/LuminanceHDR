/**
 * This file is a part of Qtpfsgui package.
 * ---------------------------------------------------------------------- 
 * Copyright (C) 2006,2007 Giuseppe Rota
 * 
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * ---------------------------------------------------------------------- 
 *
 * @author Giuseppe Rota <grota@users.sourceforge.net>
 */

#ifndef MAINGUI_IMPL_H
#define MAINGUI_IMPL_H

#include <QMainWindow>
#include <QWorkspace>
#include <QStringList>
#include <QSettings>
#include "../HdrWizard/newHdrWizard.h"
#include "../../generated_uic/ui_maingui.h"
#include "../Preferences/preferencesDialog.h"
#include "../Resize/resizeDialog.h"
class HdrViewer;
class QSignalMapper;

class MainGui : public QMainWindow, private Ui::MainGui
{
Q_OBJECT

public:
	MainGui(QWidget *parent=0);
	~MainGui();
	HdrViewer* currenthdr;
public  slots:
private slots:
	void fileNewViaWizard();
	void fileOpen();//for File->Open, it then calls loadFile()
	void fileSaveAs();
	void tonemap_requested();
	void rotateccw_requested();
	void rotatecw_requested();
	void resize_requested();
	void batch_requested();
	void current_mdi_increase_exp();
	void current_mdi_decrease_exp();
	void current_mdi_extend_exp();
	void current_mdi_shrink_exp();
	void current_mdi_fit_exp();
	void current_mdi_ldr_exp();
	void current_mdi_zoomin();
	void current_mdi_zoomout();
	void current_mdi_fit_to_win(bool checked);
	void current_mdi_original_size();
	void openDocumentation();
	void enterWhatsThis();
	void options_called();
	void transplant_called();
	void reEnableMainWin();
	void fileExit();
	void Text_Under_Icons();
	void Icons_Only();
	void Text_Alongside_Icons();
	void Text_Only();
	void updateWindowMenu();

	void openRecentFile();
	void setCurrentFile(const QString &fileName);
	void addHdrViewer(pfs::Frame*, QString fname);
	void updateRecentDirHDRSetting(QString);
	void load_failed(QString);
	void aboutQtpfsgui();

	void updateActions( QWidget * w );

private:
	void dispatchrotate( bool clockwise);
	void updateRecentFileActions();
	void load_options(qtpfsgui_opts *);
	void setupLoadThread(QString);
	bool testTempDir(QString);
	QWorkspace* workspace;
	QSignalMapper *windowMapper;
        enum { MaxRecentFiles = 5 };
        QAction *recentFileActs[MaxRecentFiles];
        QAction *separatorRecentFiles;
	QSettings settings;
	QString RecentDirHDRSetting;
	qtpfsgui_opts *qtpfsgui_options;
};


#endif