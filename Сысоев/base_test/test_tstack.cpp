#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, cant_create_stack_with_too_large_length)
{
	ASSERT_ANY_THROW(TStack<int> st(MaxStackSize + 1));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> st(1);
	ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, IsEmpty_return_true_when_stack_is_empty)
{
	TStack<int> st(1);
	EXPECT_TRUE(st.IsEmpty());
}

TEST(TStack, IsFull_return_true_when_stack_is_full)
{
	TStack<int> st(1);
	st.Push(1);
	EXPECT_TRUE(st.IsFull());
}

TEST(TStack, can_add_value_to_stack_and_view_top_value)
{
	TStack<int> st(1);
	st.Push(1);
	EXPECT_EQ(1, st.Top());
}

TEST(TStack, can_delete_value_from_stack)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);
	st.Pop();
	EXPECT_TRUE(st.Top(),1);
}

TEST(TStack, throw_when_delete_from_empty_stack)
{
	TStack<int> st(1);
	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, throw_when_add_to_full_stack)
{
	TStack<int> st(1);
	st.Push(1);
	ASSERT_ANY_THROW(st.Push(1));
}

TEST(TStack, throw_when_view_top_value_stack)
{
	TStack<int> st(1);
	st.Push(1);
	ASSERT_ANY_THROW(st.Push(1));
}

