#pragma once
#include "Database.h"
#include "DatabasePrecheckPrompt.h"

/*
 * DatabasePrecheck.h
 *
 * This file provide method to do DB precheck
 *
 * @author: Xiangdong Che
 * Revised: 04/09/20
 *
 */

namespace WeAlumni {
    public ref class DatabasePrecheck {

    public:
        static bool CheckAdmin();
        static bool CheckData();
        static void StartPrecheck();
    };
}