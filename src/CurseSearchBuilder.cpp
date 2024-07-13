
#include "CurseSearchBuilder.hpp"

namespace cf {
    CurseSearchBuilder CurseSearchBuilder::Minecraft() {
        CurseSearchBuilder builder;
        builder.gameId = 432;
        return builder;
    }

    CurseSearchBuilder CurseSearchBuilder::from_json(const json &data) {
        CurseSearchBuilder builder;
        builder.gameId = data["gameId"];
        if (data.contains("classId")) {
            builder.classId = data["classId"];
        }
        if (data.contains("categoryId")) {
            builder.categoryId = data["categoryId"];
        }
        if (data.contains("categoryIds")) {
            builder.categoryIds = data["categoryIds"];
        }
        if (data.contains("gameVersion")) {
            builder.gameVersion = data["gameVersion"];
        }
        if (data.contains("gameVersions")) {
            builder.gameVersions = data["gameVersions"];
        }
        if (data.contains("searchFilter")) {
            builder.searchFilter = data["searchFilter"];
        }
        if (data.contains("sortField")) {
            builder.sortField = static_cast<CurseModsSearchSortField>(data["sortField"]);
        }
        if (data.contains("sortOrder")) {
            builder.sortOrder = data["sortOrder"];
        }
        if (data.contains("modLoaderType")) {
            builder.modLoaderType = static_cast<CurseModLoaderType>(data["modLoaderType"]);
        }
        if (data.contains("modLoaderTypes")) {
            builder.modLoaderTypes = data["modLoaderTypes"];
        }
        if (data.contains("gameVersionTypeId")) {
            builder.gameVersionTypeId = data["gameVersionTypeId"];
        }
        if (data.contains("authorId")) {
            builder.authorId = data["authorId"];
        }
        if (data.contains("primaryAuthorId")) {
            builder.primaryAuthorId = data["primaryAuthorId"];
        }
        if (data.contains("slug")) {
            builder.slug = data["slug"];
        }
        if (data.contains("index")) {
            builder.index = data["index"];
        }
        if (data.contains("pageSize")) {
            builder.pageSize = data["pageSize"];
        }
        return builder;
    }

    json CurseSearchBuilder::to_json() const {
        json data;
        data["gameId"] = gameId;
        if (classId.has_value()) {
            data["classId"] = classId.value();
        }
        if (categoryId.has_value()) {
            data["categoryId"] = categoryId.value();
        }
        if (categoryIds.has_value()) {
            data["categoryIds"] = categoryIds.value();
        }
        if (gameVersion.has_value()) {
            data["gameVersion"] = gameVersion.value();
        }
        if (gameVersions.has_value()) {
            data["gameVersions"] = gameVersions.value();
        }
        if (searchFilter.has_value()) {
            data["searchFilter"] = searchFilter.value();
        }
        if (sortField.has_value()) {
            data["sortField"] = sortField.value();
        }
        if (sortOrder.has_value()) {
            data["sortOrder"] = sortOrder.value();
        }
        if (modLoaderType.has_value()) {
            data["modLoaderType"] = modLoaderType.value();
        }
        if (modLoaderTypes.has_value()) {
            data["modLoaderTypes"] = modLoaderTypes.value();
        }
        if (gameVersionTypeId.has_value()) {
            data["gameVersionTypeId"] = gameVersionTypeId.value();
        }
        if (authorId.has_value()) {
            data["authorId"] = authorId.value();
        }
        if (primaryAuthorId.has_value()) {
            data["primaryAuthorId"] = primaryAuthorId.value();
        }
        if (slug.has_value()) {
            data["slug"] = slug.value();
        }
        if (index.has_value()) {
            data["index"] = index.value();
        }
        if (pageSize.has_value()) {
            data["pageSize"] = pageSize.value();
        }
        return data;
    }

    string CurseSearchBuilder::to_query_string() const {
        string query;
        for (const auto &[key, value] : to_json().items()) {
            query += key + "=" + value.dump() + "&";
        }
        return query;
    }
} // cf