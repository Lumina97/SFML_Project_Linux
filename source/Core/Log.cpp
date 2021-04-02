#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <iostream>


    std::shared_ptr<spdlog::logger> Log::CoreLogger;

    void Log::Init(){
        std::cout << "Initialized Logger!" <<std::endl;
        spdlog::set_pattern("%^[%T] %n: %v%$");
        CoreLogger = spdlog::stdout_color_mt("Logger");
        CoreLogger->set_level(spdlog::level::trace);

    }


