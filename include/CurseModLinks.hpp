
#ifndef CURSEMODLINKS_HPP
#define CURSEMODLINKS_HPP

#include <nlohmann/json.hpp>
#include <string>
#include <optional>
#include "CurseForgeAPI.hpp"

namespace cf {

using json = nlohmann::json;
using std::string;
using std::optional;
using std::nullopt;

class CurseModLinks {
public:
    optional<string> websiteUrl = nullopt;
    optional<string> wikiUrl = nullopt;
    optional<string> issuesUrl = nullopt;
    optional<string> sourceUrl = nullopt;
    static CurseModLinks from_json(const json &data);
};

} // cf

#endif //CURSEMODLINKS_HPP
