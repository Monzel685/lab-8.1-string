#include "pch.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

string ReplacePatternWithAsterisks(const string& s, bool& foundPattern) {
    foundPattern = false;
    string result = "";
    size_t length = s.length();

    for (size_t i = 0; i < length; ++i) {
        if (i + 2 < length && (s.substr(i, 3) == "OGO" || s.substr(i, 3) == "AGA")) {
            result += "**";
            foundPattern = true;
            i += 2;  // Пропускаємо наступні два символи після заміни
        }
        else {
            result += s[i];
        }
    }

    return result;
}

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestReplacePatternWithAsterisks_AGA)
        {
            bool foundPattern;
            string result = ReplacePatternWithAsterisks("HELLOAGAWORLD", foundPattern);
            Assert::IsTrue(foundPattern);
            Assert::AreEqual("HELLO**WORLD", result.c_str());
        }

        TEST_METHOD(TestReplacePatternWithAsterisks_NoPattern)
        {
            bool foundPattern;
            string result = ReplacePatternWithAsterisks("HELLOWORLD", foundPattern);
            Assert::IsFalse(foundPattern);
            Assert::AreEqual("HELLOWORLD", result.c_str());
        }

        TEST_METHOD(TestReplacePatternWithAsterisks_EmptyString)
        {
            bool foundPattern;
            string result = ReplacePatternWithAsterisks("", foundPattern);
            Assert::IsFalse(foundPattern);
            Assert::AreEqual("", result.c_str());
        }
    };
}
