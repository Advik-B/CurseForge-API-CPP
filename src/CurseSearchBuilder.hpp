
#ifndef CURSESEARCHBUILDER_HPP
#define CURSESEARCHBUILDER_HPP

#include <cstdint>
#include <string>
#include <optional>
#include "CurseModsSearchSortField.hpp"

namespace cf {

using std::int32_t;
using std::string;

class CurseSearchBuilder {
public:
    int32_t gameId;
    int32_t classId;
    int32_t categoryId;
    string categoryIds;
    string gameVersion;
    string gameVersions;
    string searchFilter;
};

} // cf

#endif //CURSESEARCHBUILDER_HPP
