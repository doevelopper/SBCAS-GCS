#ifndef CENTURION_CORE_LOGGING_CATEGORY_H
#define CENTURION_CORE_LOGGING_CATEGORY_H

#include <QFile>
#include <QDir>
#include <QScopedPointer>
#include <QTextStream>
#include <QDateTime>
#include <QLoggingCategory>
#include <QStringList>


#define LOG_FATAL(M)
#define LOG_ERROR(M)
#define LOG_WARN(M)
#define LOG_INFO(M)
#define LOG_DEBUG(M)
#define LOG_TRACE(M)


// Add Global logging categories (not class specific) here using Q_DECLARE_LOGGING_CATEGORY

Q_DECLARE_LOGGING_CATEGORY(logTrace)
Q_DECLARE_LOGGING_CATEGORY(logDebug)
Q_DECLARE_LOGGING_CATEGORY(logInfo)
Q_DECLARE_LOGGING_CATEGORY(logWarning)
Q_DECLARE_LOGGING_CATEGORY(logCritical)
Q_DECLARE_LOGGING_CATEGORY(logFatal)

// Q_DECLARE_LOGGING_CATEGORY(FirmwareUpgradeLog)
// Q_DECLARE_LOGGING_CATEGORY(FirmwareUpgradeVerboseLog)
// Q_DECLARE_LOGGING_CATEGORY(MissionCommandsLog)
// Q_DECLARE_LOGGING_CATEGORY(MissionItemLog)
// Q_DECLARE_LOGGING_CATEGORY(ParameterManagerLog)
// Q_DECLARE_LOGGING_CATEGORY(GeotaggingLog)

/*!
 * @def LOGGING_CATEGORY
 * @brief This is a specific replacement for Q_LOGGING_CATEGORY. It will register the category name into a
 *        global list. It's usage is the same as Q_LOGGING_CATEOGRY.
 */

#define LOGGING_CATEGORY(name, ...) \
    static QGCLoggingCategory qgcCategory ## name (__VA_ARGS__); \
    Q_LOGGING_CATEGORY(name, __VA_ARGS__)

class LoggingCategoryRegister : public QObject
{
    Q_OBJECT

public:
    static LoggingCategoryRegister* instance(void);

    /*!
     * @brief Registers the specified logging category to the system.
     */
    void registerCategory(const char* category);

    /*! 
     * @brief Returns the list of available logging category names.
     */
    Q_INVOKABLE QStringList registeredCategories(void);

    /*! 
     * @brief Turns on/off logging for the specified category. State is saved in app settings.
     */
    Q_INVOKABLE void setCategoryLoggingOn(const QString& category, bool enable);

    /*!
     * @brief  Returns true if logging is turned on for the specified category.
     */
    Q_INVOKABLE bool categoryLoggingOn(const QString& category);

    /*!
     *@brief    Sets the logging filters rules from saved settings.
     *@param commandLineLoggingOptions Logging options which were specified on the command line
     */
    void setFilterRulesFromSettings(const QString& commandLineLoggingOptions);

	void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
	
private:
    LoggingCategoryRegister(void) 
	{ 
	    // m_logFile.reset(new QFile("logfileName.txt"));
		// m_logFile.data()->open(QFile::Append | QFile::Text);
		// qInstallMessageHandler(messageHandler);
	}
    
    QStringList _registeredCategories;
    QString     _commandLineLoggingOptions;
    static  LoggingCategoryRegister * _instance;
    static const char* _filterRulesSettingsGroup;
	
	QScopedPointer<QFile>   m_logFile;
};
        
class QGCLoggingCategory
{
public:
    QGCLoggingCategory(const char* category) 
    { 
        LoggingCategoryRegister::instance()->registerCategory(category); 
    }
};

#endif
