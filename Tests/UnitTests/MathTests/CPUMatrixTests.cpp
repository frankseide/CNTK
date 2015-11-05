//
// <copyright file="CPUMatrixTests.cpp" company="Microsoft">
//     Copyright (c) Microsoft Corporation.  All rights reserved.
// </copyright>
//
#include "stdafx.h"
#include "../../../Math/Math/CPUMatrix.h"

using namespace Microsoft::MSR::CNTK;

namespace Microsoft
{
    namespace MSR
    {
        namespace CNTK
        {
            namespace Test
            {
                typedef CPUDoubleMatrix DMatrix;
                typedef CPUSingleMatrix SMatrix;

                BOOST_AUTO_TEST_SUITE(CpuMatrixSuite)

                BOOST_AUTO_TEST_CASE(CPUMatrixConstructorNoFlags)
                {
                    DMatrix m;
                    BOOST_CHECK(m.IsEmpty());

                    m.Resize(2, 3);
                    BOOST_CHECK(!m.IsEmpty());
                    BOOST_CHECK_EQUAL(m.GetNumRows(), 2);
                    BOOST_CHECK_EQUAL(m.GetNumCols(), 3);
                    BOOST_CHECK_EQUAL(m.GetNumElements(), 6);

                    m(0, 0) = 1;
                    m(1, 2) = 2;
                    BOOST_CHECK_EQUAL(m(0, 0), 1);
                    BOOST_CHECK_EQUAL(m(1, 2), 2);

                    DMatrix m1(m);
                    BOOST_CHECK(m1.IsEqualTo(m));
                }

                BOOST_AUTO_TEST_CASE(CPUMatrixConstructorFlagNormal)
                {
                    std::array<float, 6> array = { 1, 2, 3, 4, 5, 6 };
                    SMatrix m(2, 3, array.data(), matrixFlagNormal);
                    BOOST_CHECK_EQUAL(m(0, 0), 1);
                    BOOST_CHECK_EQUAL(m(0, 1), 3);
                    BOOST_CHECK_EQUAL(m(0, 2), 5);
                    BOOST_CHECK_EQUAL(m(1, 0), 2);
                    BOOST_CHECK_EQUAL(m(1, 1), 4);
                    BOOST_CHECK_EQUAL(m(1, 2), 6);
                }

                BOOST_AUTO_TEST_CASE(CPUMatrixConstructorFormatRowMajor)
                {
                    std::array<double, 6> array = { 7, 8, 9, 10, 11, 12 };
                    DMatrix m(2, 3, array.data(), matrixFormatRowMajor);
                    BOOST_CHECK_EQUAL(m(0, 0), 7);
                    BOOST_CHECK_EQUAL(m(0, 1), 8);
                    BOOST_CHECK_EQUAL(m(0, 2), 9);
                    BOOST_CHECK_EQUAL(m(1, 0), 10);
                    BOOST_CHECK_EQUAL(m(1, 1), 11);
                    BOOST_CHECK_EQUAL(m(1, 2), 12);
                }

                BOOST_AUTO_TEST_SUITE_END()
            }
        }
    }
}