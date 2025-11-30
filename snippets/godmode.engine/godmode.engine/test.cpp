#ifdef test$
#include <godmode.foundation/test/Fixture.h>
#include <godmode.foundation/core/AppRunner.h>
#include <godmode.engine/GodmodeEngine_Mock.h>

//  kamimodo™ - the legacy of GODMODE_999
//  Copyright © 2025 ____l____e____x____e____r____. All rights reserved.
//
//  This file is part of the kamimodo™ codebase.
//
//  Licensed under the Light Attribution License (LAL) 1.0.
//  See the LICENSE file in the project root or visit:
//  https://7EX.LEX3R.com/$/999/kamimodo™/LICENSE
//
//  Trademarks:
//  kamimodo™ and kamimodo SDK™ are trademarks of ____l____e____x____e____r____.
//
//  Legacy reference:
//  GODMODE_999 - former name of the project.

fixture(
    { AppRunner::startEngine(function$((), new GodmodeEngineMock())); },
    { AppRunner::terminateEngine(); }
);

#pragma comment(lib, "godmode-foundation")
#ifdef link$
#pragma comment(lib, "godmode-engine")
#endif
#endif