
#include "CurseSortableGameVersion.hpp"

namespace cf {
    CurseSortableGameVersion CurseSortableGameVersion::from_json(const json &data) {
        CurseSortableGameVersion version;
        version.gameVersionName = data["gameVersionName"];
        version.gameVersionPadded = data["gameVersionPadded"];
        version.gameVersion = data["gameVersion"];
        version.gameVersionReleaseDate = data["gameVersionReleaseDate"];
        if (data.contains("gameVersionTypeId")) {
            version.gameVersionTypeId = data["gameVersionTypeId"];
        }
        return version;
    }
} // cf