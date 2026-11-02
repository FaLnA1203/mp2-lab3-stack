#include "pch.h"
#include "../mp2-lab3-stack/stack.h"

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> bf(3));
}