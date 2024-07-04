
#ifndef CURSESORTABLEGAMEVERSION_HPP
#define CURSESORTABLEGAMEVERSION_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace cf {
using std::string;
using std::optional;
using json = nlohmann::json;

class CurseSortableGameVersion {
public:
    string gameVersionName;
    string gameVersionPadded;
    string gameVersion;
    string gameVersionReleaseDate;
    optional<string> gameVersionTypeId = std::nullopt;
    static CurseSortableGameVersion from_json(const json &data);
};

} // cf

#endif //CURSESORTABLEGAMEVERSION_HPP
