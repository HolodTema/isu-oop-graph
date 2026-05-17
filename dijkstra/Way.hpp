#ifndef WAY_HPP
#define WAY_HPP

#include <vector>
#include <iosfwd>
#include "../core/Node.hpp"

class Way {
public:

	int length;
	std::vector<Node*> vecNodes;

	Way():
		length(-1)
	{}
};

std::ostream& operator<<(std::ostream& os, const Way& way);

#endif