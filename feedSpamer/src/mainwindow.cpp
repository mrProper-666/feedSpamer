#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	m_campaignModel = NULL;

	this->setWindowTitle(qApp->applicationName());

	loadConfig();
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_actionAdd_Campaign_triggered()
{
	AddCampaignDialog *cDialog = new AddCampaignDialog(this);

	if (cDialog->exec()) {

	}

	delete cDialog;
}

void MainWindow::on_actionRemove_Campaign_triggered()
{
	qDebug() << "remove campaign";
}

void MainWindow::on_actionCampaign_report_triggered()
{
	qDebug() << "campaign report";
}

void MainWindow::on_pbAddCampaign_clicked()
{
	on_actionAdd_Campaign_triggered();
}

void MainWindow::on_pbRemoveCampaign_clicked()
{
	qDebug() << "remove campaign click";
}

void MainWindow::loadConfig()
{
	m_campaignConfig = new CampaignConfig(qApp->applicationDirPath() + "/" + CAMPAIGN_CONFIG);

	QMap<int, campaign>::const_iterator it;

	QList<ListItem *> items;

	const QMap<int, campaign> *map = m_campaignConfig->campaigns();
	foreach (int key, map->keys()) {
		ListItem *item = new ListItem;
		item->name = map->value(key).name;
		item->description = map->value(key).url.toString();

		items << item;
	}

	if (m_campaignModel == NULL) {
		m_campaignModel = new ListItemModel;
		ui.campaignView->setItemDelegate(new ListItemDelegate);
		ui.campaignView->setModel(m_campaignModel);
	}

	m_campaignModel->list = items;
}
