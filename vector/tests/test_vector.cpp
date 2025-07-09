#include <gtest/gtest.h>
#include "../include/vector/vector.h"

TEST(VectorTest, ConstructorAndSize)
{
    vector v(5);
    EXPECT_EQ(v.size(), 5);
    EXPECT_FALSE(v.empty());

    for (size_t i = 0; i < v.size(); ++i)
    {
        EXPECT_EQ(v[i], 0);
    }
}

TEST(VectorTest, PushBackIncreasesSize)
{
    vector v;
    EXPECT_TRUE(v.empty());

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    EXPECT_EQ(v.size(), 3);
    EXPECT_GE(v.capacity(), 3);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);
    EXPECT_EQ(v[2], 30);
}

TEST(VectorTest, InsertElement)
{
    vector v;
    v.push_back(1);
    v.push_back(3);
    v.insert(1, 2);

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, ResizeIncreasesAndZeroFills)
{
    vector v(2);
    v[0] = 7;
    v[1] = 8;
    v.resize(5);

    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v[0], 7);
    EXPECT_EQ(v[1], 8);
    EXPECT_EQ(v[2], 0);
    EXPECT_EQ(v[3], 0);
    EXPECT_EQ(v[4], 0);
}

TEST(VectorTest, ReserveIncreasesCapacityOnly)
{
    vector v(2);
    size_t old_size = v.size();
    v.reserve(10);
    EXPECT_EQ(v.size(), old_size);
    EXPECT_GE(v.capacity(), 10);
}

TEST(VectorTest, AtThrowsOutOfRange)
{
    vector v(2);
    EXPECT_NO_THROW(v.at(1));
    EXPECT_THROW(v.at(2), std::out_of_range);
    EXPECT_THROW(v.at(999), std::out_of_range);
}

TEST(VectorTest, CopyConstructorAndAssignment)
{
    vector v1;
    v1.push_back(1);
    v1.push_back(2);

    vector v2 = v1;  // copy constructor
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);

    vector v3(1);
    v3 = v1;  // copy assignment
    EXPECT_EQ(v3.size(), 2);
    EXPECT_EQ(v3[0], 1);
    EXPECT_EQ(v3[1], 2);
}

TEST(VectorTest, MoveConstructorAndAssignment)
{
    vector temp;
    temp.push_back(42);

    vector moved1 = std::move(temp);  // move constructor
    EXPECT_EQ(moved1.size(), 1);
    EXPECT_EQ(moved1[0], 42);

    vector temp2;
    temp2.push_back(100);
    temp2.push_back(200);

    vector moved2(1);
    moved2 = std::move(temp2);  // move assignment
    EXPECT_EQ(moved2.size(), 2);
    EXPECT_EQ(moved2[0], 100);
    EXPECT_EQ(moved2[1], 200);
}
