#pragma once
#include <vector>
using namespace std;

namespace ariel
{

    class MagicalContainer
    {
    private:
        std::vector<int> m_array;

    public:
        MagicalContainer();
        void addElement(int element);
        void removeElement(int value);
        size_t size();

        class AscendingIterator
        {
        public:
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*();
            AscendingIterator &operator++();
            AscendingIterator begin();
            AscendingIterator end();

        private:
            std::vector<int>::iterator m_iter;
            MagicalContainer &m_container;
        };

        class SideCrossIterator
        {
        public:
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            int operator*();
            SideCrossIterator &operator++();
            SideCrossIterator begin();
            SideCrossIterator end();

        private:
            std::vector<int>::iterator m_iter;
            MagicalContainer &m_container;
            // bool m_isFromStart;
        };

        class PrimeIterator
        {
        public:
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            int operator*();
            PrimeIterator &operator++();
            PrimeIterator begin();
            PrimeIterator end();

        private:
            std::vector<int>::iterator m_iter;
            MagicalContainer &m_container;
            bool isPrime(int num);
        };
    };
}