#ifndef SVG_FILTER__
#define SVG_FILTER__

#include <libxml++/libxml++.h>
#include <glibmm/ustring.h>

///@brief Interface for filters.
class Filter
{
public:
	Filter(const xmlpp::Element* node){parseId(node);}
	virtual ~Filter(){}
	///@brief This function must build an appropriate layout in the 
	/// corresponding group.
	virtual void build (xmlpp::Element* root) const = 0;
	Glib::ustring getId() {return id;}
	Glib::ustring toString() const {return Glib::ustring("id: ") + id + "\n" + this->getString();}
	///@brief This function is just parse the current node. It is simple.
	virtual void parse (const xmlpp::Element* node) = 0;

	static Filter * parseFilterNode(const xmlpp::Node* node);
	
protected:
	virtual Glib::ustring getString() const {return "";}
	void parseId (const xmlpp::Element* node)
	{
		id = node->get_attribute_value("id").data();
	}
	
private:
	Glib::ustring id;
};

#endif //SVG_FILTER__
