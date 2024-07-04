
#ifndef CURSECATEGORY_HPP
#define CURSECATEGORY_HPP

#include <nlohmann/json.hpp>
#include <string>
#include <optional>
#include <CurseForgeAPI.hpp>


/* SCHEMA
{
  "id": 0,
  "gameId": 0,
  "name": "string",
  "slug": "string",
  "url": "string",
  "iconUrl": "string",
  "dateModified": "2019-08-24T14:15:22Z",
  "isClass": true, // Optional
  "classId": 0,
  "parentCategoryId": 0,
  "displayIndex": 0
}
 */

namespace cf {

using json = nlohmann::json;
using std::string;
using std::optional;

class CurseCategory {
    int32_t id;
    int32_t gameId;
    string name;
    string slug;
    string url;
    string iconUrl;
    string dateModified;
    optional<bool> isClass = std::nullopt;
    optional<int32_t> classId = std::nullopt;
    optional<int32_t> parentCategoryId = std::nullopt;
    optional<int32_t> displayIndex = std::nullopt;

public:
    static CurseCategory from_json(const json &data);
    static CurseCategory from_id(int32_t id, CurseForgeAPI &api);
    ~CurseCategory();
};

} // cf

#endif //CURSECATEGORY_HPP
