#ifndef ADDCAMPAIGNDIALOG_H
#define ADDCAMPAIGNDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "ui_addcampaigndialog.h"

#include "defines.h"

class AddCampaignDialog : public QDialog
{
	Q_OBJECT

public:
	AddCampaignDialog(QWidget *parent = 0);
	~AddCampaignDialog();

	QString campaignName() const;
	QString feedUrl() const;
	int updateDelay() const;
	Measurement measurementType() const;
	FeedActivity onFeedUpdateActivity() const;


private:
	Ui::AddCampaignDialog ui;
	QString m_campaignName;
	QString m_feedUrl;
	int m_delay;
	Measurement m_measurement;
	FeedActivity m_feedAct;

private slots:
	void on_pbOk_clicked();
	void on_pbCancel_clicked();
};

#endif // ADDCAMPAIGNDIALOG_H
