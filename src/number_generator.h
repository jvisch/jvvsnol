namespace jvvsnol
{

    template <typename T, T value_start, T value_end, T value_step = 1>
    struct number_generator
    {
        typedef T value_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;
        typedef const T *const_pointer;

        class const_iterator
        {
        public:
            explicit const_iterator(const number_generator *ptr) : value_(value_start), ptr_(ptr) {}

            const_iterator &operator=(const const_iterator &rhs) = delete;

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
                if (ptr_ == rhs.ptr_)
                {
                    return (ptr_ == nullptr) || (value_ == rhs.value_);
                }
                else
                {
                    return false;
                }
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
            value_type value_;
            const number_generator *ptr_; // if nullptr, out of range

            const_iterator(const const_iterator &i) : value_(i.value_), ptr_(i.ptr_) {}

            void next()
            {
                if (value_start <= value_end)
                {
                    value_ += value_step;
                    if (value_ > value_end)
                    {
                        ptr_ = nullptr;
                    }
                }
                else
                {
                    value_ -= value_step;
                    if (value_ < value_end)
                    {
                        ptr_ = nullptr;
                    }
                }
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
            return const_iterator(this);
        }

        const_iterator cend() const
        {
            return const_iterator(nullptr);
        }
    };
}