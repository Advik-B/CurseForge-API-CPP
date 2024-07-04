# Curseforge API (C++)

[cfapi]: https://wow.curseforge.com/api
[cfapi-docs]: https://wow.curseforge.com/api/docs
[python-cfapi]: https://github.com/Advik-B/CurseForge-API/

This is a no-compromise CurseForge API wrapper for C++. It is a re-write of [Curseforge API][python-cfapi] which is also maintained & actively developed by me.

This project is still in development, and is not yet ready for production use.

## Features

- Simple and easy to use
- Caches responses from the API to disk for faster response times
- Allows direct access to the API via the `fetch` method
- Allows exporting of the objects to DICT, JSON, or YAML
- Can directly parse a manifest file from a curseforge modpack

## Installation

> Todo

## Usage

> Todo

## TODO

- [x] Implement the export methods
- [x] Implement the cache
- [x] Implement the fetch method
- [x] Deal with the download URL being a null value
- [ ] Implement the search method
- [ ] Wrap the ENTIRE API
- [x] Rename the classes so they have a `Curse` prefix

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
