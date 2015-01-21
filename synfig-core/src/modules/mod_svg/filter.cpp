#include "filter.h"
#include "filter_blur.h"
#include "filterblock.h"


Filter * Filter::parseFilterNode(const xmlpp::Node* node)
{
	const xmlpp::Element* nodeElement = dynamic_cast<const xmlpp::Element*>(node);
	if (!nodeElement)
		return 0;
	Glib::ustring name = nodeElement->get_name();
	Filter * filter = 0;
	if (name == "feGaussianBlur")
		filter = new Filter_Blur(nodeElement);
	if (name == "filter")
		filter = new FilterBlock(nodeElement);
	filter->parse(nodeElement);
	return filter;
}