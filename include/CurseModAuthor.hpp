
#ifndef CURSEMODAUTHOR_HPP
#define CURSEMODAUTHOR_HPP

#include <nlohmann/json.hpp>
#include <string>

namespace cf {
using json = nlohmann::json;
using std::string;

class CurseModAuthor {
public:
    int32_t id;
    string name;
    string url;
    static CurseModAuthor from_json(const json &data);
};

} // cf

#endif //CURSEMODAUTHOR_HPP
