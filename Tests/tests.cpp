// Copyright 2022 mora


#include "Tests_ArcGraph.h"
#include "Tests_GraphConstructors.h"
#include "Tests_ListGraph.h"
#include "Tests_MatrixGraph.h"
#include "Tests_SetGraph.h"

#include <gtest/gtest.h>

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
