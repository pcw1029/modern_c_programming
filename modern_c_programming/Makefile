# GOOGLE TEST 라이브러리 및 헤더 경로 정보
GTEST_LIB 			= /home/pcw1029/googletest/myGoogleTestLib/lib
GTEST_INCLUDE 	= /home/pcw1029/googletest/googletest/include


SRC_INCLUDE		= ./chapter03/src

#컴파일 옵션
G++ 		= g++
G++_FLAGS 	= -c -Wall -I$(GTEST_INCLUDE) -I$(SRC_INCLUDE) -std=c++11
LD_FLAGS 	= -L$(GTEST_LIB) -lgtest -lpthread

#Chapter3 
CH03_GTEST_OBJS	= ./chapter03/gtest/stack_gtest.o
CH03_OBJS 			= ./chapter03/src/stack.o
CH03_GTEST_APP 	= stack_gtest

gtest_ch03: $(CH03_GTEST_APP)

$(CH03_GTEST_APP): $(CH03_OBJS) $(CH03_GTEST_OBJS)
	$(G++) -o $(CH03_GTEST_APP) $(CH03_OBJS) $(CH03_GTEST_OBJS) $(LD_FLAGS) 
	
%.o : %.cc
	$(G++) $(G++_FLAGS) -o $@ $^

clean:
	rm -f $(CH03_GTEST_APP) $(CH03_OBJS) $(CH03_GTEST_OBJS)
                    
.PHONY: all clean