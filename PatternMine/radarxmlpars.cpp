#include "radarxmlpars.h"


RadarXmlParser::RadarXmlParser(const string &strFileName) :doc(new XMLDocument())
{
	doc->LoadFile(strFileName.c_str());
}


int RadarXmlParser::getRadarNumbers()
{
	XMLElement *root = doc->RootElement();
	int i = 0;
	XMLElement *radar = root->FirstChildElement();
	if (radar)
	{
		i++;
	}
	while (radar)
	{
		radar = radar->NextSiblingElement();
		if (radar)
		{
			i++;
		}
	}
	return i;
}

int RadarXmlParser::startParse()
{
	XMLElement *root = doc->RootElement();
	if (root)
	{
		XMLElement *radar = root->FirstChildElement();
		while (radar)
		{
			
		}
	}
	return 0;
}

void RadarXmlParser::print()
{

}


void RadarXmlParser::parseAttributeSetAndGetMaps()
{
	XMLElement *root = doc->RootElement();
	map<string, string> radarData;
	if (root)
	{

		map<string, string> data;
		XMLElement *radar = root->FirstChildElement();
		extractOneRadarData(radar, data);
		maps.push_back(data);
		while (radar)
		{
			radar = radar->NextSiblingElement();
			if (radar)
			{
				data.clear();
				extractOneRadarData(radar, data);
				maps.push_back(data);
			}
		}
	}

}

int RadarXmlParser::saveToFile(const string &strFileName)
{
	return 0;
}

void RadarXmlParser::extractOneRadarData(XMLElement *radar, map<string, string> &radarData)
{
	XMLElement *key = radar->FirstChildElement();
	radarData[key->Name()] = key->GetText();
	attributeSet.insert(key->Name());
	while (key)
	{
		key = key->NextSiblingElement();
		if (key)
		{
			radarData[key->Name()] = key->GetText();
			attributeSet.insert(key->Name());
		}
	}
}