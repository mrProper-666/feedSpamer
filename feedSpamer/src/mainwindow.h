#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include "addcampaigndialog.h"
#include "campaignconfig.h"
#include "listitemmodel.h"
#include "listitemdelegate.h"

#include <QtDebug>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	CampaignConfig *m_campaignConfig;
	ListItemModel *m_campaignModel;

	void loadConfig();

private slots:
	void on_actionAdd_Campaign_triggered();
	void on_actionRemove_Campaign_triggered();
	void on_actionCampaign_report_triggered();
	void on_pbAddCampaign_clicked();
	void on_pbRemoveCampaign_clicked();
};

#endif // MAINWINDOW_H
