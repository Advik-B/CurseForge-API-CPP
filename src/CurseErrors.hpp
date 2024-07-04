
#ifndef CURSEERRORS_HPP
#define CURSEERRORS_HPP

#include <exception>
#include <utility>
#include <string>

namespace cf::errors {
    using std::string;
    using std::move;
    using std::exception;

    class CurseAPIError : public std::exception {
    public:
        explicit CurseAPIError(string  message);
        [[nodiscard]] const char* what() const noexcept override;

        explicit CurseAPIError(const exception &e) : message(e.what()) {}
    private:
        string message;
    };

    class NotFoundError final : public CurseAPIError {
    public:
        explicit NotFoundError(string for_path);
    };
}


#endif //CURSEERRORS_HPP
