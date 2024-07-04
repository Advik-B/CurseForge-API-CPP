
#ifndef CURSEFILEDEPENDENCY_HPP
#define CURSEFILEDEPENDENCY_HPP

#include <cstdint>
#include <nlohmann/json.hpp>
#include "CurseFileRelationType.hpp"

namespace cf {
using json = nlohmann::json;


class CurseFileDependency {
    int32_t modId;
    CurseFileRelationType relationType;

public:
    static CurseFileDependency from_json(const json &data);
};

} // cf

#endif //CURSEFILEDEPENDENCY_HPP
