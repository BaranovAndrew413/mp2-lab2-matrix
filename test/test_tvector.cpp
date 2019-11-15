#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10);
	for (int i = 0; i < 10; i++)
		v[i] = i;
	TVector<int>v1(10);
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(i, v1[i]);
	
  
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> *v;
	v = new TVector<int>(10);
	for (int i = 0; i < 10; i++)
		(*v)[i] = i;
	TVector<int> v1(*v);
	delete v;
	EXPECT_EQ(v,0);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[-1] = 13);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[MAX_VECTOR_SIZE] = 13);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(5);
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(5), v2(5);
	for (int i = 0; i < 5; i++)
		v1[i] = i;
	ASSERT_NO_THROW(v2 = v1);
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(i, v2[i]);
  
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(10), v2(5);
	v1 = v2;
	EXPECT_EQ(5, v1.GetSize());
  
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(4);
	TVector<int> v1(5);
	ASSERT_NO_THROW(v1 = v);;
}

TEST(TVector, compare_equal_vectors_return_true)
{
	int Size = 5;
	TVector<int> v(Size), v1(Size);
	for (int i = 0; i < Size; i++)
	{
		v[i] = 3;
		v1[i] = v[i];
	}
	EXPECT_EQ(true, v == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(5);
	EXPECT_EQ(true, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(4), v1(5);

	EXPECT_EQ(false, v == v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	int Size = 5;
	TVector<int> v(Size), v1(Size);
	v = v + 3;	//v = (3,3,3,3,3)
	for (int i = 0; i < Size; i++)
	{
		v1[i] = 3;	//v1 = (3,3,3,3,3)
	}
	EXPECT_EQ(v, v1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{

	int Size = 5;
	TVector<int> v(Size), v1(Size);
	v = v - 1;	//v = (-1,-1,-1,-1,-1)
	for (int i = 0; i < Size; i++)
	{
		v1[i] = -1;//v1 = (-1,-1,-1,-1,-1)
	}
	EXPECT_EQ(v, v1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{

	int Size = 5;
	TVector<int> v(Size), v1(Size);
	v = v + 1;	//v = (1,1,1,1,1)
	v = v * 2;	//v = (2,2,2,2,2)
	for (int i = 0; i < Size; i++)
	{
		v1[i] = 2; //v1 = (2,2,2,2,2)
	}
	EXPECT_EQ(v1, v);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	int Size = 5;
	TVector<int> v(Size), v1(Size), sum(Size), exp(Size);
	for (int i = 0; i < Size; i++)
	{
		v[i] = 3;		//v = (3,3,3,3,3)
		v1[i] = 3;	//v1 = (3,3,3,3,3)
	}
	sum = v + v1;	//sum = (6,6,6,6,6)
	for (int i = 0; i < Size; i++)
		exp[i] = 6;	//exp = (6,6,6,6,6)
	EXPECT_EQ(exp, sum);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{

	TVector<int> v(5);
	TVector<int> v1(6);
	ASSERT_ANY_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	int Size = 5;
	TVector<int> v(Size), v1(Size), sub(Size), exp(Size);
	for (int i = 0; i < Size; i++)
	{
		v[i] = 3;		//v = (3,3,3,3,3)
		v1[i] = 3;	//v1 = (3,3,3,3,3)
	}
	sub = v - v1;	//sub = (0,0,0,0,0)
	for (int i = 0; i < Size; i++)
		exp[i] = 0;	//exp = (0,0,0,0,0)
	EXPECT_EQ(exp, sub);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(5);
	TVector<int> v1(6);
	ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	int Size = 5;
	TVector<int> v(Size), v1(Size);
	int scal = 0, exp = 5;
	for (int i = 0; i < Size; i++)
	{
		v[i] = 1;		//v = (1,1,1,1,1)
		v1[i] = 1;	//v1 = (1,1,1,1,1)
	}
	scal = v * v1;	//scal = 5
	EXPECT_EQ(exp, scal);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(5);
	TVector<int> v1(6);
	ASSERT_ANY_THROW(v * v1);
}

