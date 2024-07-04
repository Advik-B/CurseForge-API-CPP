
#include "CurseFileDependency.hpp"

namespace cf {
    CurseFileDependency CurseFileDependency::from_json(const json &data) {
        CurseFileDependency dependency;
        dependency.modId = data["modId"];
        dependency.relationType = static_cast<CurseFileRelationType>(data["relationType"]);
        return dependency;
    }
} // cf