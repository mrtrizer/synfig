#include <cstdlib>

#include "filter_blur.h"

Filter_Blur::Filter_Blur(xmlpp::Element* node): Filter(node), stdDeviation(0.0)
{

}

void Filter_Blur::build(xmlpp::Element* root) const
{
	
}

void Filter_Blur::parse (const xmlpp::Element* node)
{
	stdDeviation = atof(node->get_attribute_value("stdDeviation").data());
}
