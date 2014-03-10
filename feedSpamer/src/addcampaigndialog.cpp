#include "addcampaigndialog.h"

AddCampaignDialog::AddCampaignDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(tr("Add campaign"));
}

AddCampaignDialog::~AddCampaignDialog()
{

}

void AddCampaignDialog::on_pbOk_clicked()
{
	if (ui.le_name->text().isEmpty()) {
		QMessageBox::warning(this,
			qApp->applicationName(),
			tr("Campaign name cannot be empty"),
			QMessageBox::Ok);
		return;
	}

	if (ui.le_feedUrl->text().isEmpty()) {
		QMessageBox::warning(this,
			qApp->applicationName(),
			tr("Feed url cannot be empty"),
			QMessageBox::Ok);
		return;
	}

	m_campaignName = ui.le_name->text();
	m_feedUrl = ui.le_feedUrl->text();
	m_delay = ui.sb_delay->value();

	switch (ui.cb_delayMeasurement->currentIndex()) {
	case 0:	m_measurement = Seconds; break;
	case 1:	m_measurement = Minutes; break;
	case 2:	m_measurement = Hours; break;
	default: qWarning("Unknown measurement type"); return;
	}

	switch (ui.cb_feedUpdate->currentIndex()) {
	case 0: m_feedAct = Post; break;
	case 1: m_feedAct = Request; break;
	case 2: m_feedAct = None; break;
	default: qWarning("Unknown feed update type"); return;
	}

	accept();
}

void AddCampaignDialog::on_pbCancel_clicked()
{
	reject();
}

QString AddCampaignDialog::campaignName() const
{
	return m_campaignName;
}

QString AddCampaignDialog::feedUrl() const
{
	return m_feedUrl;
}

int AddCampaignDialog::updateDelay() const
{
	return m_delay;
}

Measurement AddCampaignDialog::measurementType() const
{
	return m_measurement;
}

FeedActivity AddCampaignDialog::onFeedUpdateActivity() const
{
	return m_feedAct;
}
