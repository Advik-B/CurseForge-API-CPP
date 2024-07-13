
#ifndef CURSESEARCHBUILDER_HPP
#define CURSESEARCHBUILDER_HPP

#include <cstdint>
#include <string>
#include <optional>
#include <nlohmann/json.hpp>
#include "CurseModsSearchSortField.hpp"
#include "CurseModLoaderType.hpp"

namespace cf {

using std::int32_t;
using std::string;
using std::optional;
using std::nullopt;
using json = nlohmann::json;

class CurseSearchBuilder {
public:
    int32_t gameId;
    optional<int32_t> classId        = nullopt;
    optional<int32_t> categoryId     = nullopt;
    optional<string> categoryIds     = nullopt;
    optional<string> gameVersion     = nullopt;
    optional<string> gameVersions    = nullopt;
    optional<string> searchFilter    = nullopt;
    optional<CurseModsSearchSortField> sortField = nullopt;
    optional<string> sortOrder = nullopt;
    optional<CurseModLoaderType> modLoaderType = nullopt;
    optional<string> modLoaderTypes = nullopt;
    optional<int32_t> gameVersionTypeId = nullopt;
    optional<int32_t> authorId = nullopt;
    optional<int32_t> primaryAuthorId = nullopt;
    optional<string> slug = nullopt;
    optional<int32_t> index = nullopt;
    optional<int32_t> pageSize = 50;

    static CurseSearchBuilder Minecraft();
    static CurseSearchBuilder from_json(const json &data);
    string to_query_string() const;
    json to_json() const;
};

} // cf

#endif //CURSESEARCHBUILDER_HPP
