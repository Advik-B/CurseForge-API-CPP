
#ifndef CURSECATEGORY_HPP
#define CURSECATEGORY_HPP

#include <nlohmann/json.hpp>
#include <string>

/* SCHEMA
{
  "id": 0,
  "gameId": 0,
  "name": "string",
  "slug": "string",
  "url": "string",
  "iconUrl": "string",
  "dateModified": "2019-08-24T14:15:22Z",
  "isClass": true,
  "classId": 0,
  "parentCategoryId": 0,
  "displayIndex": 0
}
 */

namespace cf {

using json = nlohmann::json;
using std::string;

class CurseCategory {
    int32_t id;
    int32_t gameId;
    string name;
    string slug;
    string url;
    string iconUrl;
    string dateModified;
};

} // cf

#endif //CURSECATEGORY_HPP
