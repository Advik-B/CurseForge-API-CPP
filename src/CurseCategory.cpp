
#include "CurseCategory.hpp"

namespace cf {

    CurseCategory CurseCategory::from_json(const json &data) {
        CurseCategory category;
        category.id = data["id"];
        category.gameId = data["gameId"];
        category.name = data["name"];
        category.slug = data["slug"];
        category.url = data["url"];
        category.iconUrl = data["iconUrl"];
        category.dateModified = data["dateModified"];
        if (data.contains("isClass")) {
            category.isClass = data["isClass"];
        }
        if (data.contains("classId")) {
            category.classId = data["classId"];
        }
        if (data.contains("parentCategoryId")) {
            category.parentCategoryId = data["parentCategoryId"];
        }
        if (data.contains("displayIndex")) {
            category.displayIndex = data["displayIndex"];
        }
        return category;
    }

    CurseCategory CurseCategory::from_id(int32_t id, CurseForgeAPI &api) {
        auto response = api.fetch("v1/categories/" + std::to_string(id));
        return from_json(response);
    }

    CurseCategory::~CurseCategory() = default;
} // cf