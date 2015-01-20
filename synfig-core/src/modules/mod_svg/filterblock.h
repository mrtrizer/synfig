#ifndef FILTER_BLOCK__
#define FILTER_BLOCK__

#include <libxml++/libxml++.h>
#include <list>

#include "filter.h"

///@brief Filter block can contain several filters.
///@details This class looks like just container. But it has such functions  
/// like Filter (build and parse). That is why it is inherited the Filter class.
/// Moreover, FilterBlock has own id, like filters included in it.
class FilterBlock: public Filter
{
public:
	FilterBlock(xmlpp::Element* node);
	~FilterBlock();
	void build (xmlpp::Element* root) const;
	
protected:
	void addFilter(const Filter * filter);
	void parse (const xmlpp::Element* node);

private:
	typedef std::list<const Filter *> FilterList;
	FilterList filterList;
	double x;
	double y;
	double width;
	double height;
};

#endif //FILTER_BLOCK__
