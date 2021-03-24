#pragma once

#include "spdlog/spdlog.h"

#include <memory>



    class Log{

    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetLogger() { return CoreLogger; }

    private:
        static  std::shared_ptr<spdlog::logger> CoreLogger;

    };



