
#ifndef CURSEMOD_HPP
#define CURSEMOD_HPP

/*
SCHEMA

{
  "id": 0,
  "gameId": 0,
  "name": "string",
  "slug": "string",
  "links": {
    "websiteUrl": "string",
    "wikiUrl": "string",
    "issuesUrl": "string",
    "sourceUrl": "string"
  },
  "summary": "string",
  "status": 1,
  "downloadCount": 0,
  "isFeatured": true,
  "primaryCategoryId": 0,
  "categories": [
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
  ],
  "classId": 0,
  "authors": [
    {
      "id": 0,
      "name": "string",
      "url": "string"
    }
  ],
  "logo": {
    "id": 0,
    "modId": 0,
    "title": "string",
    "description": "string",
    "thumbnailUrl": "string",
    "url": "string"
  },
  "screenshots": [
    {
      "id": 0,
      "modId": 0,
      "title": "string",
      "description": "string",
      "thumbnailUrl": "string",
      "url": "string"
    }
  ],
  "mainFileId": 0,
  "latestFiles": [
    {
      "id": 0,
      "gameId": 0,
      "modId": 0,
      "isAvailable": true,
      "displayName": "string",
      "fileName": "string",
      "releaseType": 1,
      "fileStatus": 1,
      "hashes": [
        {
          "value": "string",
          "algo": 1
        }
      ],
      "fileDate": "2019-08-24T14:15:22Z",
      "fileLength": 0,
      "downloadCount": 0,
      "fileSizeOnDisk": 0,
      "downloadUrl": "string",
      "gameVersions": [
        "string"
      ],
      "sortableGameVersions": [
        {
          "gameVersionName": "string",
          "gameVersionPadded": "string",
          "gameVersion": "string",
          "gameVersionReleaseDate": "2019-08-24T14:15:22Z",
          "gameVersionTypeId": 0
        }
      ],
      "dependencies": [
        {
          "modId": 0,
          "relationType": 1
        }
      ],
      "exposeAsAlternative": true,
      "parentProjectFileId": 0,
      "alternateFileId": 0,
      "isServerPack": true,
      "serverPackFileId": 0,
      "isEarlyAccessContent": true,
      "earlyAccessEndDate": "2019-08-24T14:15:22Z",
      "fileFingerprint": 0,
      "modules": [
        {
          "name": "string",
          "fingerprint": 0
        }
      ]
    }
  ],
  "latestFilesIndexes": [
    {
      "gameVersion": "string",
      "fileId": 0,
      "filename": "string",
      "releaseType": 1,
      "gameVersionTypeId": 0,
      "modLoader": 0
    }
  ],
  "latestEarlyAccessFilesIndexes": [
    {
      "gameVersion": "string",
      "fileId": 0,
      "filename": "string",
      "releaseType": 1,
      "gameVersionTypeId": 0,
      "modLoader": 0
    }
  ],
  "dateCreated": "2019-08-24T14:15:22Z",
  "dateModified": "2019-08-24T14:15:22Z",
  "dateReleased": "2019-08-24T14:15:22Z",
  "allowModDistribution": true,
  "gamePopularityRank": 0,
  "isAvailable": true,
  "thumbsUpCount": 0,
  "rating": 0
}

 */

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>
#include "CurseForgeAPI.hpp"
#include "CurseCategory.hpp"
#include "CurseModLinks.hpp"
#include "CurseModStatus.hpp"
#include "CurseModAuthor.hpp"
#include "CurseModAsset.hpp"
#include "CurseFile.hpp"
#include "CurseSearchBuilder.hpp"
#include "CurseFileIndex.hpp"

namespace cf {

using json = nlohmann::json;
using std::string;
using std::vector;
using std::optional;

class CurseMod {
public:
    int32_t id;
    int32_t gameId;
    string name;
    string slug;
    CurseModLinks links;
    CurseModStatus status;
    int64_t downloadCount;
    bool isFeatured;
    int32_t primaryCategoryId;
    vector<CurseCategory> categories;
    optional<int32_t> classId = std::nullopt;
    vector<CurseModAuthor> authors;
    CurseModAsset logo;
    vector<CurseModAsset> screenshots;
    int32_t mainFileId;
    vector<CurseFile> latestFiles;
    vector<CurseFileIndex> latestFilesIndexes;
    vector<CurseFileIndex> latestEarlyAccessFilesIndexes;
    string dateCreated;
    string dateModified;
    string dateReleased;
    optional<bool> allowModDistribution = std::nullopt;
    int32_t gamePopularityRank;
    bool isAvailable;
    int32_t thumbsUpCount;
    optional<double> rating = std::nullopt;
    bool isBlocked; // Custom field to check if the mod is blocked by the API

    static CurseMod from_json(const json &data);
    static CurseMod from_id(int32_t id, CurseForgeAPI &engine);
    static vector<CurseMod> search(CurseSearchBuilder &builder, CurseForgeAPI &engine);
    string get_url() const;
private:
    void unblock();
};
  typedef CurseMod CurseAddon;
}

#endif //CURSEMOD_HPP
