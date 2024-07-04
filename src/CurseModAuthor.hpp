
#ifndef CURSEMODAUTHOR_HPP
#define CURSEMODAUTHOR_HPP

#include <nlohmann/json.hpp>
#include <string>

namespace cf {
using json = nlohmann::json;
using std::string;

class CurseModAuthor {
    int32_t id;
    string name;
    string url;
};

} // cf

#endif //CURSEMODAUTHOR_HPP
