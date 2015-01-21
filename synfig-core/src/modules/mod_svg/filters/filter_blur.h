#ifndef FILTER_BLUR__
#define FILTER_BLUR__

#include "filter.h"

///@brief Blur filter. 
class Filter_Blur: public Filter
{
public:
	Filter_Blur(const xmlpp::Element* node);
	void build(xmlpp::Element* root) const;
	void parse (const xmlpp::Element* node);

protected:
	Glib::ustring getString() const;

private:
	double stdDeviation;
};

#endif //FILTER_BLUR__
