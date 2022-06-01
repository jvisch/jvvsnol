#pragma once

#ifndef JVVSNOL_OPERAND_H__
#define JVVSNOL_OPERAND_H__


namespace jvvsnol
{
    template <typename T_iter, typename T_func>
    class operand
    {
    public:
        operand(const T_iter &begin, const T_iter &end, const T_func& func) : begin_(begin), end_(end), func_(func) {}

        operand(const operand &) = delete;
        operand &operator=(const operand &rhs) = delete;

        class const_iterator
        {
        public:
            typedef typename T_iter::value_type value_type;
            typedef value_type &reference;
            typedef const value_type &const_reference;
            typedef value_type *pointer;
            typedef const value_type *const_pointer;

            explicit const_iterator(const T_iter &iterator, const T_func& func) : iterator_(iterator), value_(), func_(func)
            {
                set_value();
            }

            const_iterator(const const_iterator &other) : iterator_(other.iterator_), value_(other.value_), func_(other.func_) {}

            const_iterator &operator=(const const_iterator &rhs)
            {
                if (this != &rhs)
                {
                    iterator_ = rhs.iterator_;
                    value_ = rhs.value_;
                    func_ = rhs.func_;
                }
                return *this;
            }

            const_iterator &operator++() // ++iter
            {
                next();
                return *this;
            }

            const_iterator operator++(int) // iter++
            {
                const_iterator old(*this);
                next();
                return old;
            }

            bool operator==(const const_iterator &rhs) const
            {
                return (iterator_ == rhs.iterator_);
            }

            bool operator!=(const const_iterator &rhs) const
            {
                return !operator==(rhs);
            }

            const_reference operator*() const // values of the range may not be changed
            {
                return value_;
            }

            const_pointer operator->() const // values of the range may not be changed
            {
                return &value_;
            }

        private:
            T_iter iterator_;
            value_type value_;
            const T_func& func_;

            void set_value()
            {
                // We need a copy of the value, because the operator* and operator-> 
                // need an existing copy of the value to refer to.
                value_ = func_(*iterator_);
            }

            void next()
            {
                ++iterator_;
                set_value();
            }
        };

        const_iterator begin() const
        {
            return cbegin(); // Generator values ar immutable
        }

        const_iterator end() const
        {
            return cend(); // Generator values ar immutable
        }

        const_iterator cbegin() const
        {
            return const_iterator(begin_, func_);
        }

        const_iterator cend() const
        {
            return const_iterator(end_, func_);
        }

    private:
        T_iter begin_;
        const T_iter end_;
        const T_func func_;
    };

}

#endif // JVVSNOL_OPERAND_H__
