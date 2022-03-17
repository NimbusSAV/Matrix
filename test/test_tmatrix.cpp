#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m1(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m1(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m1(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m1(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m1));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	EXPECT_NE(&m1[m1.GetStartIndex()], &m2[m2.GetStartIndex()]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix <int> m1(5);
	EXPECT_EQ(m1.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m1(5);
	m1[0][0] = 1;
	ASSERT_NO_THROW(m1[0][0]);
	ASSERT_NO_THROW(m1[1][1] = 1);
	EXPECT_EQ(m1[0][0], 1);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m1(5);
	ASSERT_ANY_THROW(m1[1][-5] = 0);
	ASSERT_ANY_THROW(m1[-5][1] = 0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m1(5);
	ASSERT_ANY_THROW(m1[1][10] = 0);
	ASSERT_ANY_THROW(m1[10][1] = 0);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TVector<int> m1(5);
	ASSERT_NO_THROW(m1 = m1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(5);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(5), m2(10);
	int len = m1.GetSize();
	m1 = m2;
	EXPECT_NE(len, m1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(5), m2(10);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(5), m2(m1), m3(m2);
	EXPECT_EQ(true, m1 == m2);
	EXPECT_EQ(true, m3 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(5);
	EXPECT_EQ(true, m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(5), m2(10);
	EXPECT_EQ(true, m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(5), m2(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			m1[i][j] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			m2[i][j] = 1;
	TMatrix<int> m3(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			m3[i][j] = 2;
	ASSERT_NO_THROW(m1 + m2);
	EXPECT_EQ(m1 + m2, m3);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(5), m2(10);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(5), m2(5), m3(5);
	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = i; j < m1.GetSize(); j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 1;
			m3[i][j] = 0;
		}
	ASSERT_NO_THROW(m1 - m2);
	EXPECT_EQ(m1 - m2, m3);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(5), m2(10);
	ASSERT_ANY_THROW(m1 - m2);
}