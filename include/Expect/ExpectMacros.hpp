#pragma once

#define CBUNIT_EXPECT ::CBUnit::build_make_expect(__FILE__, __LINE__).expect
#define CBUNIT_EXPECT_TO_OVERRIDE(Class, Logic) ExpectTo<Class, Logic>: public virtual ExpectBase<Class>