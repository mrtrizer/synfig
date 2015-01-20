#ifndef FILTER_BLUR__
#define FILTER_BLUR__

#include "filter.h"

///@brief Blur filter. 
class Filter_Blur: public Filter
{
public:
	Filter_Blur(xmlpp::Element* node);
	void build(xmlpp::Element* root) const;

protected:
	void parse (const xmlpp::Element* node);

private:
	double stdDeviation;
};

#endif //FILTER_BLUR__
