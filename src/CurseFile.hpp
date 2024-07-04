
#ifndef CURSEFILE_HPP
#define CURSEFILE_HPP

/*
SCHEMA
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
 */

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include "CurseFileReleaseType.hpp"
#include "CurseFileStatus.hpp"
#include "CurseFileHash.hpp"
#include "CurseSortableGameVersion.hpp"
#include "CurseFileDependency.hpp"
#include "CurseFileModule.hpp"

namespace cf {

using std::vector;
using std::string;
using std::optional;
using std::nullopt;
using json = nlohmann::json;

class CurseFile {
    int32_t id;
    int32_t gameId;
    int32_t modId;
    bool isAvailable;
    string displayName;
    string fileName;
    CurseFileReleaseType releaseType;
    CurseFileStatus fileStatus;
    vector<CurseFileHash> hashes;
    string fileDate;
    int64_t fileLength;
    int64_t downloadCount;
    optional<int64_t> fileSizeOnDisk = nullopt;
    string downloadUrl;
    vector<string> gameVersions;
    vector<CurseSortableGameVersion> sortableGameVersions;
    vector<CurseFileDependency> dependencies;
    optional<bool> exposeAsAlternative = nullopt;
    optional<int32_t> parentProjectFileId = nullopt;
    optional<int32_t> alternateFileId = nullopt;
    optional<bool> isServerPack = nullopt;
    optional<int32_t> serverPackFileId = nullopt;
    optional<bool> isEarlyAccessContent = nullopt;
    optional<string> earlyAccessEndDate = nullopt;
    int64_t fileFingerprint;
    vector<CurseFileModule> modules;

    public:
    static CurseFile from_json(const json &data);
};

} // cf

#endif //CURSEFILE_HPP
