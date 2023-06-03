#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("MagicalContainer - addElement")
{
    MagicalContainer container;

    // size of the container should be 0
    CHECK(container.size() == 0);

    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(-5));

    // size of the container should be 2
    CHECK(container.size() == 2);
}

TEST_CASE("MagicalContainer - removeElement")
{
    MagicalContainer container;
    container.addElement(13);
    container.addElement(7);
    // remove elements
    CHECK_NOTHROW(container.removeElement(13));
    CHECK(container.size() == 1);
    CHECK_NOTHROW(container.removeElement(7));
    CHECK(container.size() == 0);
}

TEST_CASE("AscendingIterator - constructors")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(2);

    // create with default, regular and copy costructors
    CHECK_NOTHROW(MagicalContainer::AscendingIterator iter(container));
    MagicalContainer::AscendingIterator iter(container);
    CHECK_NOTHROW(MagicalContainer::AscendingIterator copy_iter(iter));
}
TEST_CASE("SideCrossIterator  - constructors")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(2);

    // create with default, regular and copy costructors
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator iter(container));
    MagicalContainer::SideCrossIterator iter(container);
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator copy_iter(iter));
}
TEST_CASE("PrimeIterator   - constructors")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(2);

    // create with default, regular and copy costructors
    CHECK_NOTHROW(MagicalContainer::PrimeIterator iter(container));
    MagicalContainer::PrimeIterator iter(container);
    CHECK_NOTHROW(MagicalContainer::PrimeIterator copy_iter(iter));
}

TEST_CASE("Comparing AscendingIterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(7);
    container.addElement(10);

    MagicalContainer::AscendingIterator ascend_iter1(container);
    MagicalContainer::AscendingIterator ascend_iter2(container);

    CHECK((ascend_iter1 == ascend_iter2));
    CHECK_FALSE((ascend_iter1 != ascend_iter2));
    CHECK_FALSE((ascend_iter1 < ascend_iter2));
    CHECK_FALSE((ascend_iter1 > ascend_iter2));

    ++ascend_iter1;
    CHECK_FALSE((ascend_iter1 == ascend_iter2));
    CHECK((ascend_iter1 != ascend_iter2));
    CHECK((ascend_iter1 > ascend_iter2));
    CHECK_FALSE((ascend_iter1 < ascend_iter2));

    ++ascend_iter2;
    CHECK((ascend_iter1 == ascend_iter2));
    CHECK_FALSE((ascend_iter1 != ascend_iter2));
    CHECK_FALSE((ascend_iter1 > ascend_iter2));
    CHECK_FALSE((ascend_iter1 < ascend_iter2));

    ++ascend_iter1;
    CHECK_FALSE((ascend_iter1 == ascend_iter2));
    CHECK((ascend_iter1 != ascend_iter2));
    CHECK((ascend_iter1 > ascend_iter2));
    CHECK_FALSE((ascend_iter1 < ascend_iter2));

    ++ascend_iter2; // now iter1 and iter2 on same spot
    ++ascend_iter1;
    ++ascend_iter2;

    // now both are the the end of the container

    CHECK(ascend_iter1 == ascend_iter1.end());
    CHECK(ascend_iter2 == ascend_iter2.end());
    CHECK_FALSE((ascend_iter1 > ascend_iter2));
    CHECK_FALSE((ascend_iter1 < ascend_iter2));

    // checking begin
    MagicalContainer::AscendingIterator ascend_iter3(container);
    CHECK(ascend_iter3 == ascend_iter1.begin());
}

TEST_CASE("Comparing SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(7);
    container.addElement(10);

    MagicalContainer::SideCrossIterator side_iter1(container);
    MagicalContainer::SideCrossIterator side_iter2(container);

    CHECK((side_iter1 == side_iter2));
    CHECK_FALSE((side_iter1 != side_iter2));
    CHECK_FALSE((side_iter1 < side_iter2));
    CHECK_FALSE((side_iter1 > side_iter2));

    ++side_iter1;
    CHECK_FALSE((side_iter1 == side_iter2));
    CHECK((side_iter1 != side_iter2));
    CHECK((side_iter1 > side_iter2));
    CHECK_FALSE((side_iter1 < side_iter2));

    ++side_iter2;
    CHECK((side_iter1 == side_iter2));
    CHECK_FALSE((side_iter1 != side_iter2));
    CHECK_FALSE((side_iter1 > side_iter2));
    CHECK_FALSE((side_iter1 < side_iter2));

    ++side_iter1;
    CHECK_FALSE((side_iter1 == side_iter2));
    CHECK((side_iter1 != side_iter2));
    CHECK((side_iter1 > side_iter2));
    CHECK_FALSE((side_iter1 < side_iter2));

    ++side_iter2; // now iter1 and iter2 on same spot
    ++side_iter1;
    ++side_iter2;

    // now both are the the end of the container
    CHECK(side_iter1 == side_iter1.end());
    CHECK(side_iter2 == side_iter2.end());

    // checking begin
    MagicalContainer::SideCrossIterator side_iter3(container);
    CHECK(side_iter3 == side_iter1.begin());
}

TEST_CASE("Comparing PrimeIterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(7);
    container.addElement(10);

    MagicalContainer::PrimeIterator prime_iter1(container);
    MagicalContainer::PrimeIterator prime_iter2(container);

    CHECK((prime_iter1 == prime_iter2));
    CHECK_FALSE((prime_iter1 != prime_iter2));
    CHECK_FALSE((prime_iter1 < prime_iter2));
    CHECK_FALSE((prime_iter1 > prime_iter2));

    ++prime_iter1;
    CHECK_FALSE((prime_iter1 == prime_iter2));
    CHECK((prime_iter1 != prime_iter2));
    CHECK((prime_iter1 > prime_iter2));
    CHECK_FALSE((prime_iter1 < prime_iter2));

    ++prime_iter2;
    CHECK((prime_iter1 == prime_iter2));
    CHECK_FALSE((prime_iter1 != prime_iter2));
    CHECK_FALSE((prime_iter1 > prime_iter2));
    CHECK_FALSE((prime_iter1 < prime_iter2));

    ++prime_iter2; // now iter1 and iter2 on same spot
    ++prime_iter1;

    // now both are the the end of the container
    CHECK(prime_iter1 == prime_iter1.end());
    CHECK(prime_iter2 == prime_iter2.end());

    // checking begin
    MagicalContainer::PrimeIterator prime_iter3(container);
    CHECK(prime_iter3 == prime_iter1.begin());
}

TEST_CASE("Checking *iter for every type of iterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(7);
    container.addElement(11);
    container.addElement(3);
    container.addElement(12);
    MagicalContainer::AscendingIterator ascend_iter(container);
    MagicalContainer::SideCrossIterator side_iter(container);
    MagicalContainer::PrimeIterator prime_iter(container);

    // checking AscendingIterator
    CHECK(*ascend_iter == 1);
    ++ascend_iter;
    CHECK(*ascend_iter == 2);
    ++ascend_iter;
    CHECK(*ascend_iter == 3);
    ++ascend_iter;
    CHECK(*ascend_iter == 7);
    ++ascend_iter;
    CHECK(*ascend_iter == 11);
    ++ascend_iter;
    CHECK(*ascend_iter == 12);

    //checking SideCrossIterator
    CHECK(*side_iter == 1);
    ++side_iter;
    CHECK(*side_iter == 12);
    ++side_iter;
    CHECK(*side_iter == 2);
    ++side_iter;
    CHECK(*side_iter == 3);
    ++side_iter;
    CHECK(*side_iter == 7);
    ++side_iter;
    CHECK(*side_iter == 11);

    // checking PrimeIterator

    CHECK(*prime_iter == 2);
    ++prime_iter;
    CHECK(*prime_iter == 7);
    ++prime_iter;
    CHECK(*prime_iter == 11);
    ++prime_iter;
    CHECK(*prime_iter == 3);
}

TEST_CASE("Checking = or every type of iterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(7);

    MagicalContainer::AscendingIterator ascend_iter(container);
    ++ascend_iter; // moving the iterator to point on 2
    MagicalContainer::AscendingIterator ascend_iter1 = ascend_iter;
    CHECK(*ascend_iter1 == 2);

    MagicalContainer::SideCrossIterator side_iter(container);
    ++side_iter; // moving the iterator to point on 7
    MagicalContainer::SideCrossIterator side_iter1 = side_iter;
    CHECK(*side_iter1 == 7);

    MagicalContainer::PrimeIterator prime_iter(container);
    ++prime_iter; // moving the iterator to point on 7
    MagicalContainer::PrimeIterator prime_iter1 = prime_iter;
    CHECK(*prime_iter1 == 7);
}

// Test case for the PrimeIterator with no prime numbers in the container
TEST_CASE("PrimeIterator  ++operator throw")
{
    MagicalContainer container;
    container.addElement(4);
    container.addElement(6);
    container.addElement(8);

    MagicalContainer::PrimeIterator prime_iter(container);

    // there is no prime number in this container
    CHECK_THROWS(++prime_iter);
}