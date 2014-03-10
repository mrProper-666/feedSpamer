#pragma once
#ifndef DEFINES_H
#define DEFINES_H

#include <QUrl>

enum Measurement { Seconds, Minutes, Hours };
enum FeedActivity { Post, Request, None };

#define CAMPAIGN_CONFIG "config.xml"

typedef struct {
	QString name;
	QUrl url;
	int delay;
	Measurement measurement;
	FeedActivity activity;
} campaign;

#endif // DEFINES_H
