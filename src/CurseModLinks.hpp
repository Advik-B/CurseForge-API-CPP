
#ifndef CURSEMODLINKS_HPP
#define CURSEMODLINKS_HPP

#include <nlohmann/json.hpp>
#include <string>
#include "CurseForgeAPI.hpp"

namespace cf {

using json = nlohmann::json;
using std::string;

class CurseModLinks {
public:
    string websiteUrl;
    string wikiUrl;
    string issuesUrl;
    string sourceUrl;
    static CurseModLinks from_json(const json &data);
};

} // cf

#endif //CURSEMODLINKS_HPP
