#ifndef _VARREADER_HPP
#define _VARREADER_HPP

#include <map>
#include <mutex>
#include <thread>

#include "ITargetMemoryHandler.hpp"
#include "Variable.hpp"
#include "spdlog/spdlog.h"

class TargetMemoryHandler
{
   public:
	TargetMemoryHandler(ITargetMemoryHandler* memoryHandler, std::shared_ptr<spdlog::logger> logger);

	bool start() const;
	bool stop() const;

	uint32_t getValue(uint32_t address) const;
	double getValue(uint32_t address, VariableBase::type type);
	bool setValue(const Variable& var, double value);
	std::string getLastErrorMsg() const;

   private:
	std::mutex mtx;
	std::unique_ptr<ITargetMemoryHandler> memoryHandler;
	std::shared_ptr<spdlog::logger> logger;
};

#endif