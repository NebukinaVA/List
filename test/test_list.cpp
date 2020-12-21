#include <gtest.h>
#include "list.h"

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> l);
}

TEST(List, can_copy_list)
{
	List<int> l1, l2(l1);

	EXPECT_TRUE(l1 == l2);
}

TEST(List, copied_list_has_its_own_memory)
{
	List<int> l1, l2(l1);

	l2.append(1);

	EXPECT_FALSE(l1 == l2);
}

TEST(List, can_append_element)
{
	List<int> l;

	ASSERT_NO_THROW(l.append(0));
}

TEST(List, can_check_if_empty)
{
	List<int> l;

	EXPECT_TRUE(l.empty());
}

TEST(List, can_check_if_not_empty)
{
	List<int> l;
	
	l.append(1);

	EXPECT_FALSE(l.empty());
}

TEST(List, can_remove_element)
{
	List<int> l;

	l.append(1);
	l.append(2);

	ASSERT_NO_THROW(l.remove());
}

TEST(List, can_clear_list)
{
	List<int> l;

	l.append(1);
	l.append(2);
	l.append(3);
	l.clear();

	EXPECT_TRUE(l.empty());
}

TEST(List, can_assign_lists)
{
	List<int> l1, l2;

	l1.append(1);
	l2.append(3);
	l1 = l2;

	EXPECT_TRUE(l1 == l2);
}

TEST(List, can_compare_equal_lists)
{
	List<int> l1, l2;

	l1.append(1);
	l2.append(1);

	EXPECT_TRUE(l1 == l2);
}

TEST(List, can_compare_unequal_lists)
{
	List<int> l1, l2;

	l1.append(1);
	l2.append(2);

	EXPECT_TRUE(l1 != l2);
}

TEST(List, can_compare_unequal_lists_1)
{
	List<int> l1, l2;

	l1.append(1);
	l2.append(1);
	l1.append(2);
	l2.append(2);
	l2.remove();

	EXPECT_TRUE(l1 != l2);
}