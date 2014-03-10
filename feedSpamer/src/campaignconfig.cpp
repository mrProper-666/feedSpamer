#include "campaignconfig.h"

CampaignConfig::CampaignConfig(QString config, QObject *parent)
	: QObject(parent)
{
	QFile file(config);
	QFileInfo fi(file);
	QDomDocument configDoc;

	if (fi.exists() && file.open(QIODevice::ReadWrite | QIODevice::Text)) {
		configDoc.setContent(file.readAll());
	} else {
		QString configPath = qApp->applicationDirPath() + "/" + CAMPAIGN_CONFIG;
		file.setFileName(configPath);
		if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
			qWarning("Cannot create config file :-(");
		configDoc.setContent(file.readAll());
	}

	parseConfig(configDoc);
	configDoc.clear();
	file.close();
}

CampaignConfig::~CampaignConfig()
{

}

void CampaignConfig::parseConfig(QDomDocument &doc)
{
	QDomElement docElem = doc.documentElement();

	QDomNode n = docElem.firstChild();
	while(!n.isNull()) {
		QDomElement e = n.toElement();
		if(!e.isNull()) {
			campaign camp;
			bool ok = true;
			camp.name = e.attribute("name");
			camp.url = QUrl(e.attribute("feedUrl"));
			camp.delay = e.attribute("delay").toInt(&ok, 10);
			if (!ok) {
				QMessageBox::critical(NULL, 
					qApp->applicationName(),
					tr("Delay property is invalid"),
					QMessageBox::Ok);
				camp.delay = 10;
			}
			QString buf = e.attribute("delayMes");
			camp.measurement = (buf == "sec") ? Seconds : ((buf == "min") ? Minutes : Hours);
			buf = e.attribute("onFeedUpdate");
			camp.activity = (buf =="post") ? Post : ((buf == "request") ? Request : None);

			int id = e.attribute("id").toInt(&ok, 10);

			if (!ok) {
				QMessageBox::critical(NULL, 
					qApp->applicationName(),
					tr("Id property is invalid. Aborting"),
					QMessageBox::Ok);
				return;
			}

			m_campaigns.insert(id, camp);
		}
		n = n.nextSibling();
	}
}

const QMap<int, campaign> * CampaignConfig::campaigns() const
{
	return &m_campaigns;
}
