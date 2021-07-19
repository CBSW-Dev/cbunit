CPP_STANDARD = -std=c++11

CPP_WARNINGS = -Wall -Werror -Wextra

CPP_OPTIONS = 
#disable the not, and, or, etc keywords
CPP_OPTIONS += -fno-operator-names

CPP_COMPILER = g++

CPP = $(CPP_COMPILER) $(CPP_STANDARD) $(CPP_WARNINGS) $(CPP_OPTIONS)