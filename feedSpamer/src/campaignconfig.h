#ifndef CAMPAIGNCONFIG_H
#define CAMPAIGNCONFIG_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QFileInfo>
#include <QtDebug>
#include <QCoreApplication>
#include <QMessageBox>

#include "defines.h"

class CampaignConfig : public QObject
{
	Q_OBJECT

public:
	CampaignConfig(QString config, QObject *parent = NULL);
	~CampaignConfig();

	const QMap<int, campaign> *campaigns() const;

private:
	QMap<int, campaign> m_campaigns;
	void parseConfig(QDomDocument &doc);
};

#endif // CAMPAIGNCONFIG_H
