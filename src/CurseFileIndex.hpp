
#ifndef CURSEFILEINDEX_HPP
#define CURSEFILEINDEX_HPP

#include <string>
#include <nlohmann/json.hpp>
#include <optional>
#include "CurseFileReleaseType.hpp"
#include "CurseModLoaderType.hpp"

namespace cf {

using json = nlohmann::json;
using std::string;
using std::optional;

class CurseFileIndex {
    string gameVersion;
    int32_t fileId;
    string filename;
    CurseFileReleaseType releaseType;
    optional<int32_t> gameVersionTypeId = std::nullopt;
    CurseModLoaderType modLoader;

public:
    static CurseFileIndex from_json(const json &data);
};

} // cf

#endif //CURSEFILEINDEX_HPP
