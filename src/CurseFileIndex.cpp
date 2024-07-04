
#include "CurseFileIndex.hpp"

namespace cf {
    CurseFileIndex CurseFileIndex::from_json(const json &data) {
        CurseFileIndex index;
        index.gameVersion = data["gameVersion"];
        index.fileId = data["fileId"];
        index.filename = data["filename"];
        index.releaseType = static_cast<CurseFileReleaseType>(data["releaseType"]);
        if (data.contains("gameVersionTypeId")) {
            index.gameVersionTypeId = data["gameVersionTypeId"];
        }
        index.modLoader = static_cast<CurseModLoaderType>(data["modLoader"]);
        return index;
    }
} // cf