#include "postfix.h"
#include "postfix.cpp"
#include <gtest.h>
#include <string>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TStack, can_create_copied_postfix)
{
	TPostfix p;
	ASSERT_NO_THROW(TPostfix p1(p));
}

TEST(TPostfix, can_get_infix)
{
	TPostfix p("a+b");
	EXPECT_EQ("a+b", p.GetInfix());
}

TEST(TPostfix, can_create_postfix_from_infix)
{
	TPostfix p("a+b");
	p.ToPostfix();
	EXPECT_EQ("a,b,+,", p.GetPostfix());
}

TEST(TPostfix, CheckInfix_return_true_when_infix_is_correct)
{
	TPostfix p("a+b");
	EXPECT_TRUE(p.CheckInfix());
}

TEST(TPostfix, CheckInfix_return_false_when_infix_is_invalid)
{
	TPostfix p("(a+-b");
	EXPECT_FALSE(p.CheckInfix());
}

TEST(TStack, throw_when_division_by_zero)
{
	TPostfix p("2+2/0");
	ASSERT_ANY_THROW(p.Calculate());
}

TEST(TPostfix, can_calculate_expression1)
{
	TPostfix p("2+2*(2+2)");
	EXPECT_EQ(10,p.Calculate());
}

TEST(TPostfix, can_calculate_expression2)
{
	TPostfix p("(1+2)-3/6*2");
	EXPECT_EQ(2, p.Calculate());
}

TEST(TPostfix, can_calculate_expression3)
{
	TPostfix p("(0.5+0.5)/(0.25+0.25)");
	EXPECT_EQ(2, p.Calculate());
}

TEST(TPostfix, can_calculate_expression4)
{
	TPostfix p("0.1*(10*0.1)*(10/10)*100");
	EXPECT_EQ(10, p.Calculate());
}





