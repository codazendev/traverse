// File: Logger.cpp
// The engine logger.

// System includes.
#include <iomanip>

// Engine includes.
#include "traverse/Logger.hpp"

// Construct new Logger instance.
traverse::Logger::Logger(const std::string& a_file_name)
    : m_file_stream(a_file_name, std::ios::app) {
    // Make sure the in-place file stream initialization was successful. If not, throw a runtime error.
    if (!m_file_stream.is_open()) {
        throw std::runtime_error("Could not open log file.");
    }
}

// Write log message to log file.
void traverse::Logger::log(Level level, const std::string& message) {
    m_file_stream << "[timestamp]" << std::setw(8) << levelToString(level) << ": " << message << "\n";
    m_file_stream.flush();
}

const char* traverse::Logger::levelToString(traverse::Logger::Level level) {
    switch (level) {
        case traverse::Logger::Level::Debug:
            return "Debug";
        case traverse::Logger::Level::Info:
            return "Info";
        case traverse::Logger::Level::Warn:
            return "Warn";
        case traverse::Logger::Level::Error:
            return "Error";
        case traverse::Logger::Level::Fatal:
            return "Fatal";
        default:
            return "Unknown";
    }
}

// Write debug log message without formatting.
void traverse::Logger::debug(const std::string& message) {
    log(Level::Debug, message);
}

// Write info log message without formatting.
void traverse::Logger::info(const std::string& message) {
    log(Level::Info, message);
}

// Write warn log message without formatting.
void traverse::Logger::warn(const std::string& message) {
    log(Level::Warn, message);
}

// Write error log message without formatting.
void traverse::Logger::error(const std::string& message) {
    log(Level::Error, message);
}

// Write fatal log message without formatting.
void traverse::Logger::fatal(const std::string& message) {
    log(Level::Fatal, message);
}