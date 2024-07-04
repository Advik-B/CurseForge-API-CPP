
#include "CurseModAuthor.hpp"

namespace cf {
    CurseModAuthor CurseModAuthor::from_json(const json &data) {
        CurseModAuthor author;
        author.id = data["id"];
        author.name = data["name"];
        author.url = data["url"];
        return author;
    }
} // cf