#include "MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

namespace ariel
{

    // MagicalContainer
    MagicalContainer::MagicalContainer()
    {
    }
    void MagicalContainer::addElement(int element)
    {
        m_array.push_back(element);
    }
    void MagicalContainer::removeElement(int value)
    {
        auto iter = find(m_array.begin(), m_array.end(), value);
        m_array.erase(iter);
    }
    size_t MagicalContainer::size()
    {
        return m_array.size();
    }

    // MagicalContainer::AscendingIterator

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : m_container(container)
    {
    }
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : m_container(other.m_container)
    {
        // Copy the iterator position
        m_iter = other.m_iter;
    }

    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (this != &other)
        {
            m_iter = other.m_iter;
            m_container = other.m_container;
        }
        return *this;
    }
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return (this->m_iter == other.m_iter);
    }
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return std::distance(this->m_iter, other.m_iter) > 0;
    }
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return std::distance(this->m_iter, other.m_iter) < 0;
    }
    int MagicalContainer::AscendingIterator::operator*()
    {
        return 0;
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        // need to fix according to how to move the itertator
        ++m_iter;
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return *this;
    }

    /////////////////////////////////////
    // MagicalContainer::SideCrossIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : m_container(container)
    {
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : m_container(other.m_container)
    {
        // Copy the iterator position
        m_iter = other.m_iter;
    }

    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (this != &other)
        {
            m_iter = other.m_iter;
            m_container = other.m_container;
        }
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return (this->m_iter == other.m_iter);
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return std::distance(this->m_iter, other.m_iter) > 0;
    }
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return std::distance(this->m_iter, other.m_iter) < 0;
    }
    int MagicalContainer::SideCrossIterator::operator*()
    {
        return 0;
    }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        // need to fix according to how to move the itertator
        ++m_iter;
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        return *this;
    }

    ///////////////////////////////////
    // MagicalContainer::PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : m_container(container)
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : m_container(other.m_container)
    {
        // Copy the iterator position
        m_iter = other.m_iter;
    }

    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (this != &other)
        {
            m_iter = other.m_iter;
            m_container = other.m_container;
        }
        return *this;
    }
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return (this->m_iter == other.m_iter);
    }
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return std::distance(this->m_iter, other.m_iter) > 0;
    }
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return std::distance(this->m_iter, other.m_iter) < 0;
    }
    int MagicalContainer::PrimeIterator::operator*()
    {
        return 0;
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        // need to fix according to how to move the itertator
        ++m_iter;
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::isPrime(int num)
    {
        return true;
    }
}