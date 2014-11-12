#ifndef RADARXMLPARS_H
#define RADARXMLPARS_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include "tinyxml2.h"


using namespace std;
using namespace tinyxml2;


class RadarXmlParser
{
public:
	RadarXmlParser(const string &strFileName);
	int startParse();
	void print();
	int saveToFile(const string &strFileName);
	int getRadarNumbers();
	void buildRelationTable();
	/*
	xquery()？//暂时不支持
	*/
	
private:
	void parseAttributeSetAndGetMaps();
	void extractOneRadarData(XMLElement *radar,map<string,string> &radarData);
	XMLDocument *doc;
	set<string> attributeSet;
	
	vector<map<string, string> > maps;
};






#endif