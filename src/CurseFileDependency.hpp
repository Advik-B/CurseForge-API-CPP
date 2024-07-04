
#ifndef CURSEFILEDEPENDENCY_HPP
#define CURSEFILEDEPENDENCY_HPP

#include <cstdint>
#include "CurseFileRelationType.hpp"

namespace cf {


class CurseFileDependency {
    int32_t modId;
    CurseFileRelationType relationType;
};

} // cf

#endif //CURSEFILEDEPENDENCY_HPP
