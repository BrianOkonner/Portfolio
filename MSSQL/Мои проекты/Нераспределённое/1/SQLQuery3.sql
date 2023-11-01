USE [master];
GO
RESTORE DATABASE [AdventureWorksDW2019]
FROM DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\Backup\AdventureWorksDW2019.bak'
WITH
    FILE = 1,
    NOUNLOAD,
    STATS = 5;
GO