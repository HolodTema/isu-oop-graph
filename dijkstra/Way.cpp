#include "Way.hpp"

#include <ostream>

std::ostream& operator<<(std::ostream& os, const Way& way) {
	std::ostream::sentry s(os);
	if (!s) {
		return os;
	}

	os << "Way: length = " << way.length << "\n";
	for (Node* node : way.vecNodes) {
		os << node->getName() << " <- ";
	}
	os << "\n";

	return os;
}
