
#include "CurseModAsset.hpp"

namespace cf {
    CurseModAsset CurseModAsset::from_json(const json &data) {
        CurseModAsset asset;
        asset.id = data["id"];
        asset.modId = data["modId"];
        asset.title = data["title"];
        asset.description = data["description"];
        asset.thumbnailUrl = data["thumbnailUrl"];
        asset.url = data["url"];
        return asset;
    }
} // cf