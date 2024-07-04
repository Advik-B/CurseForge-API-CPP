
#include "CurseModLinks.hpp"

namespace cf {
    CurseModLinks CurseModLinks::from_json(const json &data) {
        CurseModLinks links;
        links.websiteUrl = data["websiteUrl"];
        links.wikiUrl = data["wikiUrl"];
        links.issuesUrl = data["issuesUrl"];
        links.sourceUrl = data["sourceUrl"];
        return links;
    }
} // cf