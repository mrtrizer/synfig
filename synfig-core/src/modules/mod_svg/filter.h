#ifndef SVG_FILTER__
#define SVG_FILTER__

#include <libxml++/libxml++.h>
#include <glibmm/ustring.h>

///@brief Interface for filters.
class Filter
{
public:
	Filter(const xmlpp::Element* node){parseId(node); parse(node);}
	virtual ~Filter(){}
	///@brief This function must build an appropriate layout in the 
	/// corresponding group.
	virtual void build (xmlpp::Element* root) const = 0;
	Glib::ustring getId() {return id;}
	
protected:
	void parseId (const xmlpp::Element* node)
	{
		Glib::ustring id = node->get_attribute_value("id");
	}
	///@brief This function is just parse the current node. It is simple.
	/// Attention. The function is called from the constructor above.
	virtual void parse (const xmlpp::Element* node) = 0;
	
private:
	Glib::ustring id;
};

#endif //SVG_FILTER__
