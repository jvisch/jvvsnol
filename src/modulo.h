namespace jvvsnol
{
    template <typename T>
    class modulo
    {
    public:
        modulo(const T &begin, const T &end) : begin_(begin), end_(end) {}

        modulo(const modulo &) = delete;
        modulo &operator=(const modulo &rhs) = delete;

        class const_iterator
        {
        public:
            const_iterator(const T &iterator) : iterator_(iterator) {
                set_value();
            }

            const_iterator(const const_iterator &other) : iterator_(other.iterator_), value_(other.value_) {}

            void set_value()
            {
                value_ = ((*iterator_) % 2);
            }

            const_iterator &operator=(const const_iterator &rhs)
            {
                if (this != &rhs)
                {
                    iterator_ = rhs.iterator_;
                    value_ = rhs.value_;
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

            const T::value_type& operator*() const // values of the range may not be changed
            {
                return value_;
            }

            const T::value_type* operator->() const // values of the range may not be changed
            {
                return &value_;
            }

        private:
            T iterator_;
            T::value_type value_;

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
            return const_iterator(begin_);
        }

        const_iterator cend() const
        {
            return const_iterator(end_);
        }

    private:
        T begin_;
        const T end_;
    };

}