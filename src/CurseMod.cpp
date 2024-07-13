
#include "CurseMod.hpp"
// #include <iostream>
namespace cf {
    CurseMod CurseMod::from_json(const json &data) {
        // std::cout << data.dump(4) << std::endl;
        CurseMod mod;
        mod.id = data["id"];
        mod.gameId = data["gameId"];
        mod.name = data["name"];
        mod.slug = data["slug"];
        mod.links = CurseModLinks::from_json(data["links"]);
        mod.status = static_cast<CurseModStatus>(data["status"]); // We need to cast the integer to the enum type
        mod.downloadCount = data["downloadCount"];
        mod.isFeatured = data["isFeatured"];
        mod.primaryCategoryId = data["primaryCategoryId"];
        for (const auto &category : data["categories"]) {
            mod.categories.push_back(CurseCategory::from_json(category));
        }
        if (data.contains("classId")) {
            mod.classId = data["classId"];
        }
        for (const auto &author : data["authors"]) {
            mod.authors.push_back(CurseModAuthor::from_json(author));
        }
        mod.logo = CurseModAsset::from_json(data["logo"]);
        for (const auto &screenshot : data["screenshots"]) {
            mod.screenshots.push_back(CurseModAsset::from_json(screenshot));
        }
        mod.mainFileId = data["mainFileId"];
        for (const auto &file : data["latestFiles"]) {
            mod.latestFiles.push_back(CurseFile::from_json(file));
        }
        for (const auto &index : data["latestFilesIndexes"]) {
            mod.latestFilesIndexes.push_back(CurseFileIndex::from_json(index));
        }
        for (const auto &index : data["latestEarlyAccessFilesIndexes"]) {
            mod.latestEarlyAccessFilesIndexes.push_back(CurseFileIndex::from_json(index));
        }
        mod.dateCreated = data["dateCreated"];
        mod.dateModified = data["dateModified"];
        mod.dateReleased = data["dateReleased"];
        if (data.contains("allowModDistribution")) {
            mod.allowModDistribution = data["allowModDistribution"];
        }
        mod.gamePopularityRank = data["gamePopularityRank"];
        mod.isAvailable = data["isAvailable"];
        mod.thumbsUpCount = data["thumbsUpCount"];
        if (data.contains("rating")) {
            mod.rating = data["rating"];
        }
        return mod;
    }

    CurseMod CurseMod::from_id(int32_t id, CurseForgeAPI &engine) {
        return from_json(engine.fetch("/v1/mods/" + std::to_string(id))["data"]);
    }

    vector<CurseMod> CurseMod::search(CurseSearchBuilder &builder, CurseForgeAPI &engine) {
        vector<CurseMod> mods;
        mods.reserve(50);
        json data = engine.fetch("/v1/mods/search?" + builder.to_query_string())["data"];
        for (const auto &mod : data) {
            mods.push_back(from_json(mod));
        }
        return mods;
    }
}
