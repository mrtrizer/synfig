#include "filterblock.h"

#include <cstdlib>

using namespace std;

FilterBlock::FilterBlock(xmlpp::Element* node): 
	Filter(node), 
	x(0.0), 
	y(0.0), 
	width(0.0), 
	height(0.0)
{
	//The parse function is called from the Filter class constructor.
}

FilterBlock::~FilterBlock()
{
	FilterList::iterator i = filterList.begin();
	for (;i != filterList.end(); i++)
		delete *i;
}

void FilterBlock::addFilter(const Filter * filter)
{
	filterList.push_back(filter);
}

void FilterBlock::build (xmlpp::Element* root) const
{

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
		Glib::ustring name =(*iter)->get_name();
	}
}
