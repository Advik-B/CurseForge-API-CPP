
#ifndef CURSEERRORS_HPP
#define CURSEERRORS_HPP

#include <exception>

namespace cf {
    class CurseError : public std::exception {
    public:
        explicit CurseError(const char *message) : message(message) {}

        [[nodiscard]] const char *what() const noexcept override {
            return message;
        }

    private:
        const char *message;
    };

    class CurseAPIError final : public CurseError {
    public:
        explicit CurseAPIError(const char *message)
            : CurseError(message) {
        }
    };

    class CurseParseError final : public CurseError {
    public:
        explicit CurseParseError(const char *message)
            : CurseError(message) {
        }
    };
}

#endif //CURSEERRORS_HPP
