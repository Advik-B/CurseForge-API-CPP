
#ifndef CURSEFILEDEPENDENCY_HPP
#define CURSEFILEDEPENDENCY_HPP

#include <cstdint>
#include <nlohmann/json.hpp>
#include "CurseFileRelationType.hpp"

namespace cf {
using json = nlohmann::json;


class CurseFileDependency {
public:
    int32_t modId;
    CurseFileRelationType relationType;
    static CurseFileDependency from_json(const json &data);
};

} // cf

#endif //CURSEFILEDEPENDENCY_HPP
