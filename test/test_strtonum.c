#include "unity.h"
#include "strtonum.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void setUp(void){}

void tearDown(void){}

void test_strtonum_given_1234_abcd_and_expert_1234_basedTen(void)
{
  char *ptr;
  long val;
  char value2Parse[] ="1234 abcd";
  val = strtol("1234 abcd", NULL, 10);
  TEST_ASSERT_EQUAL(1234, val);
}

void test_strtonum_given_8765(void)
{
  long val;
  char value2Parse[] =" 8756 abcd";
  val = strtol(value2Parse, NULL, 10);
  TEST_ASSERT_EQUAL(8756, val);
}


void test_strtonum_given_with_tab4567_opq(void)
{
  long val;
  char value2Parse[] ="\t\t4567 abcd";
  val = strtol(value2Parse, NULL, 10);
  TEST_ASSERT_EQUAL(4567, val);
}

void test_strtonum_given_0x345abc_abc_expert_0x345abc(void)
{
  long val;
  char *ptr; 
  char value2Parse[] ="0x234567 abc";
  val = strtol(value2Parse, &ptr, 10);
    TEST_ASSERT_EQUAL('x',*ptr);
     TEST_ASSERT_EQUAL(0, val);
}

void test_strtonum_given_0x23345abc_abc_expert_0x345abc(void)
{
  long val;
  char *ptr; 
  char value2Parse[] ="0x123456 abc";
  val = strtol(value2Parse, &ptr, 16);
  TEST_ASSERT_EQUAL(' ',*ptr);
 } 
 
void test_strtonum_given_0x23345abc_abc_expert_0x345abctest(void)
{
  long val;
  char *ptr; 
  char value2Parse[] ="write 0x123123 abc";
  val = strtol(value2Parse, &ptr, 16);
  TEST_ASSERT_EQUAL('w',*ptr);
}

void test_strtonum_given_0x23345abc_abc_expert_0x345abctest12(void)
{
  long val;
  char *ptr; 
  char value2Parse[] =" 0x123123 abc";
  val = strtol(value2Parse, &ptr, 16);
  TEST_ASSERT_EQUAL(' ',*ptr);
}


void test_12strtonum_given_0x23345abc_abc_expert_0x345abctest12(void)
{
  long val;
  char *ptr; 
  char value2Parse[] =" write 0x123123 abc";
  val = strtol(value2Parse, &ptr, 0);
  TEST_ASSERT_EQUAL(' ',*ptr);
}

void test_12strtonum_given_0x23345abc_abc_expert_0x345abctest1212(void)
{
  long val;
  char *ptr; 
  char value2Parse[] ="\t0x124556 \t0x1234 123";
  val = strtol(value2Parse, &ptr, 16);
  TEST_ASSERT_EQUAL(' ',*ptr);
}

void test_getNumber_given__0x124556_0x1234_123_expert_return_0x124556_0x1234_123(void)
{
  char *str = "\t0x124556 0x1234 123";
  long val = getNumber(&str);
  TEST_ASSERT_EQUAL(123, val);
  // getnum(str);
} 

void test_getNumber_given_write_expert_ERR(void)
{
  char *str = "write";
  long val = getNumber(&str);
  TEST_ASSERT_EQUAL(-1, val);
} 

void test_getNumber_given_write__0x123456_expert_ERR(void)
{
  char *str = "write\t0x123456";
  long val = getNumber(&str);
  TEST_ASSERT_EQUAL(-1, val);
} 

void test_getNumber_given__0x123456_write_expert_ERR(void)
{
  char *str = "/t0x123456 write";
  long val = getNumber(&str);
  TEST_ASSERT_EQUAL(-1, val);
} 


/* void test_getNuma(void)
{
  int i = sum (123);
  // TEST_ASSERT_EQUAL(1197398, val);
  // getnum(str);
} */

 
 
 
 
 
 