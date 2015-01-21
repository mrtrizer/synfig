#include <cstdlib>
#include <sstream>
#include <iostream>

#include "filter_blur.h"

using namespace std;

Filter_Blur::Filter_Blur(const xmlpp::Element* node): 
	Filter(node), 
	stdDeviation(0.0)
{
}

void Filter_Blur::build(xmlpp::Element* root) const
{
	
}

Glib::ustring Filter_Blur::getString() const
{
	stringstream ss;
	ss << "stdDeviation: " << stdDeviation << endl; 
	return ss.str();
}

void Filter_Blur::parse (const xmlpp::Element* node)
{
	stdDeviation = atof(node->get_attribute_value("stdDeviation").data());
}
