#ifndef COMP3400_2020W_A03_signal_hxx_
#define COMP3400_2020W_A03_signal_hxx_

//===========================================================================

#include <csignal>
#include <stdexcept>
#include <type_traits>
#include <initializer_list>

//===========================================================================

namespace comp3400_2020w::a03 {

//===========================================================================

class signal_id {
    using id_type = int;

    id_type id_;

public:
    constexpr signal_id() = delete;
    constexpr signal_id(const signal_id& s) = default;
    constexpr signal_id& operator=(const signal_id& s) = default;
    constexpr signal_id(int signum) : id_(signum) {};
    constexpr signal_id& operator=(int signum) {
        id_ = signum;
        return *this;
    }

    constexpr id_type id() const {
        return id_;
    }

    constexpr operator int() const {
        return this->id_;
    }
};

//===========================================================================

struct signal_handler_error_t {};
constexpr signal_handler_error_t signal_handler_error{};

//===========================================================================

struct signal_handler_ignore_t {};
constexpr signal_handler_ignore_t signal_handler_ignore {};

//===========================================================================

struct signal_handler_default_t {};
constexpr signal_handler_default_t signal_handler_default {};

//===========================================================================

class signal_handler_op
{
private:
    enum class op_type { error, default_, ignore, traditional, sigaction };

public:
    using traditional_op_type = void (*)(int);
    using sigaction_op_type = void (*)(int, siginfo_t*, void*);

private:
    static const traditional_op_type ERROR;
    static const traditional_op_type IGNORE;
    static const traditional_op_type DEFAULT;

    op_type type_;
    union 
    {
        traditional_op_type sa_handler_;
        sigaction_op_type sa_sigaction_;
    };
  
public:
    signal_handler_op() : type_(op_type::default_), sa_handler_(DEFAULT) {};
    signal_handler_op(signal_handler_op const& sho) : type_(sho.type_) {
        if (type_ == op_type::sigaction) {
            sa_sigaction_ = sho.sa_sigaction_;
        }
        else {
            sa_handler_ = sho.sa_handler_;
        }
    };
    signal_handler_op& operator =(signal_handler_op const& sho) {
        type_ = sho.type_;
        if (type_ == op_type::sigaction) {
            sa_sigaction_ = sho.sa_sigaction_;
        }
        else {
            sa_handler_ = sho.sa_handler_;
        }

        return *this;
    }

    signal_handler_op(signal_handler_default_t const&) : type_(op_type::ignore), sa_handler_(IGNORE) {};
    signal_handler_op& operator =(signal_handler_default_t const&) {
        type_ = op_type::default_;
        sa_handler_ = DEFAULT;

        return *this;
    }

    signal_handler_op(signal_handler_ignore_t const&) : type_(op_type::ignore), sa_handler_(IGNORE) {};
    signal_handler_op& operator =(signal_handler_ignore_t const&) {
        type_ = op_type::error;
        sa_handler_ = IGNORE;
        
        return *this;
    }

    signal_handler_op(signal_handler_error_t const&) : type_(op_type::error), sa_handler_(ERROR) {};
    signal_handler_op& operator =(signal_handler_error_t const&) {
        type_ = op_type::error;
        sa_handler_ = ERROR;

        return *this;
    }

    signal_handler_op(traditional_op_type const& op) : type_(op_type::traditional), sa_handler_(op) {};
    signal_handler_op& operator =(traditional_op_type const& op) {
        type_ = op_type::traditional;
        sa_handler_ = op;

        return *this;
    }

    signal_handler_op(sigaction_op_type const& op) : type_(op_type::sigaction), sa_sigaction_(op) {};
    signal_handler_op& operator =(sigaction_op_type const& op) {
        type_ = op_type::sigaction;
        sa_sigaction_ = op;

        return *this;
    }

    operator bool() const {
        return !is_error();
    }

    bool is_error() const {
        if (type_ == op_type::error) {
            return true;
        } else if (type_ == op_type::sigaction) {
            return sa_sigaction_ == nullptr;
        } else {
            return sa_handler_ == ERROR || sa_handler_ == nullptr;
        }
    }

    bool is_default() const {
        if (type_ == op_type::sigaction) {
            return false;
        } else {
            return type_ == op_type::default_ || sa_handler_ == DEFAULT;
        }
    }

    bool is_ignore() const {
        if (type_ == op_type::sigaction) {
            return false;
        } else {
            return type_ == op_type::ignore || sa_handler_ == IGNORE;
        }
    }

    bool is_traditional() const {
        return type_ != op_type::sigaction;
    }

    bool is_sigaction() const {
        return type_ == op_type::sigaction;
    }

    traditional_op_type traditional_op() const {
        if (type_ != op_type::sigaction) {
            return sa_handler_;
        } else {
            throw std::runtime_error("signal_handler_op cast to sigaction_op_type invalid");
        }
    }

    sigaction_op_type sigaction_op() const {
        if (type_ == op_type::sigaction) {
            return sa_sigaction_;
        } else {
            throw std::runtime_error("signal_handler_op cast to traditional_op_type invalid");
        }
    }

    bool operator ==(signal_handler_op const& b) const {
        return type_ == b.type_ && (
            is_traditional()
            ? sa_handler_ == b.sa_handler_
            : sa_sigaction_ == b.sa_sigaction_
        );
    }

    bool operator !=(signal_handler_op const& b) const {
        return !(operator ==(b));
    }
};

//===========================================================================

} // namespace comp3400_2020w::a03

//===========================================================================

#include "provided-signal.hxx"

//===========================================================================

#endif // #ifndef COMP3400_2020W_A03_signal_hxx_
