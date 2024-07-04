
#include "CurseCategory.hpp"

namespace cf {
    CurseCategory::CurseCategory(const json &data) {
        this->id = data["id"];
        this->gameId = data["gameId"];
        this->name = data["name"];
        this->slug = data["slug"];
        this->url = data["url"];
        this->iconUrl = data["iconUrl"];
        this->dateModified = data["dateModified"];
    }

    CurseCategory::~CurseCategory() = default;
} // cf