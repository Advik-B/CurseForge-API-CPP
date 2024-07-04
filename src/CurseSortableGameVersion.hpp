
#ifndef CURSESORTABLEGAMEVERSION_HPP
#define CURSESORTABLEGAMEVERSION_HPP

#include <string>
#include <optional>
namespace cf {
using std::string;
using std::optional;

class CurseSortableGameVersion {
    string gameVersionName;
    string gameVersionPadded;
    string gameVersion;
    string gameVersionReleaseDate;
    optional<string> gameVersionTypeId = std::nullopt;
};

} // cf

#endif //CURSESORTABLEGAMEVERSION_HPP
