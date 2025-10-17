// File: Logger.hpp
// The engine logger.

// Only include this file once during compilation.
#pragma once

// System includes.
#include <format>
#include <fstream>

// Engine includes.

// Declare this as part of the traverse namespace.
namespace traverse {
    // Logger class specification.
    class Logger {
        public:
            // Enum class for supported log levels.
            enum class Level {
                Debug,
                Info,
                Warn,
                Error,
                Fatal
            };
        
        private:
            // The output file stream for the log file.
            std::ofstream m_file_stream;

            // Write log message to log file.
            void log(Level level, const std::string& message);

            // Get a string representing the given log level.
            static const char* levelToString(Level level);

            // Get a string representing the current system time.
            std::string currentTimestamp() const;

        public:
            // Construct new Logger instance.
            explicit Logger(const std::string& a_file_name);

            // Write debug log message without formatting.
            void debug(const std::string& message);

            // Write debug log message with formatting.
            template<typename... Args>
            void debugf(std::string_view fmt, Args&&... args) {
                std::string formatted_message = std::vformat(fmt, std::make_format_args(args...));
                log(Level::Debug, formatted_message);
            }

            // Write info log message without formatting.
            void info(const std::string& message);

            // Write info log message with formatting.
            template<typename... Args>
            void infof(std::string_view fmt, Args&&... args) {
                std::string formatted_message = std::vformat(fmt, std::make_format_args(args...));
                log(Level::Info, formatted_message);
            }

            // Write warn log message without formatting.
            void warn(const std::string& message);

            // Write warn log message with formatting.
            template<typename... Args>
            void warnf(std::string_view fmt, Args&&... args) {
                std::string formatted_message = std::vformat(fmt, std::make_format_args(args...));
                log(Level::Warn, formatted_message);
            }

            // Write error log message without formatting.
            void error(const std::string& message);

            // Write error log message with formatting.
            template<typename... Args>
            void errorf(std::string_view fmt, Args&&... args) {
                std::string formatted_message = std::vformat(fmt, std::make_format_args(args...));
                log(Level::Error, formatted_message);
            }

            // Write fatal log message without formatting.
            void fatal(const std::string& message);

            // Write fatal log message with formatting.
            template<typename... Args>
            void fatalf(std::string_view fmt, Args&&... args) {
                std::string formatted_message = std::vformat(fmt, std::make_format_args(args...));
                log(Level::Fatal, formatted_message);
            }
    };
} // End traverse namespace.