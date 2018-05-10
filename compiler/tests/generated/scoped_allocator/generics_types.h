
#pragma once

#include <bond/core/bond_version.h>

#if BOND_VERSION < 0x0700
#error This file was generated by a newer version of the Bond compiler and is incompatible with your version of the Bond library.
#endif

#if BOND_MIN_CODEGEN_VERSION > 0x0b00
#error This file was generated by an older version of the Bond compiler and is incompatible with your version of the Bond library.
#endif

#include <bond/core/config.h>
#include <bond/core/containers.h>
#include <bond/core/nullable.h>


namespace tests
{
    
    template <typename T1, typename T2>
    struct Foo
    {
        using allocator_type = arena;

        T2 t2;
        ::bond::nullable< ::tests::Foo<T1, bool>, arena> n;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        Foo(_bond_vc12_ctor_workaround_ = {})
          : t2()
        {
        }

        
        // Compiler generated copy ctor OK
        Foo(const Foo&) = default;
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Foo(Foo&& other)
          : t2(std::move(other.t2)),
            n(std::move(other.n))
        {
        }
#else
        Foo(Foo&&) = default;
#endif
        
        explicit
        Foo(const arena& allocator)
          : t2(),
            n(allocator)
        {
        }
        
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Foo& operator=(Foo other)
        {
            other.swap(*this);
            return *this;
        }
#else
        // Compiler generated operator= OK
        Foo& operator=(const Foo&) = default;
        Foo& operator=(Foo&&) = default;
#endif

        bool operator==(const Foo& other) const
        {
            return true
                && (t2 == other.t2)
                && (n == other.n);
        }

        bool operator!=(const Foo& other) const
        {
            return !(*this == other);
        }

        void swap(Foo& other)
        {
            using std::swap;
            swap(t2, other.t2);
            swap(n, other.n);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
        }
    };

    template <typename T1, typename T2>
    inline void swap(::tests::Foo<T1, T2>& left, ::tests::Foo<T1, T2>& right)
    {
        left.swap(right);
    }
} // namespace tests