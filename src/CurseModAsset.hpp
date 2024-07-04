
#ifndef CURSEMODASSET_HPP
#define CURSEMODASSET_HPP

#include <nlohmann/json.hpp>
#include <string>

namespace cf {

using json = nlohmann::json;
using std::string;

class CurseModAsset {
    int32_t id;
    int32_t modId;
    string title;
    string description;
    string thumbnailUrl;
    string url;
};

} // cf

#endif //CURSEMODASSET_HPP
