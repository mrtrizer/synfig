#include "filterblock.h"

#include <cstdlib>
#include <sstream>
#include <iostream>

#include "filter_blur.h"

using namespace std;

FilterBlock::FilterBlock(const xmlpp::Element* node): 
	Filter(node), 
	x(0.0), 
	y(0.0), 
	width(0.0), 
	height(0.0)
{
}

FilterBlock::~FilterBlock()
{
	FilterList::iterator i = filterList.begin();
	for (;i != filterList.end(); i++)
		delete *i;
}

void FilterBlock::build (xmlpp::Element* root) const
{
	
}

Glib::ustring FilterBlock::getString() const
{
	std::stringstream ss;
	ss << "x: " << x; 
	ss << " y: " << y; 
	ss << " width: " << width; 
	ss << " height: " << height << endl;
	FilterList::const_iterator i = filterList.begin();
	for (;i != filterList.end(); i++)
		ss << (*i)->toString() << endl;
	return ss.str();
}

void FilterBlock::parse (const xmlpp::Element* node)
{
	x = atof(node->get_attribute_value("x").data());
	y = atof(node->get_attribute_value("y").data());
	width = atof(node->get_attribute_value("width").data());
	height = atof(node->get_attribute_value("height").data());
	xmlpp::Node::NodeList list = node->get_children();
	if (list.empty())
		return;
	for(xmlpp::Node::NodeList::iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		Filter * filter = Filter::parseFilterNode(*iter);
		if (filter != 0)
			filterList.push_back(filter);
	}
}
