/****** Скрипт для команды SelectTopNRows из среды SSMS  ******/
SELECT TOP (1000) [fio]
      ,[god]
      ,[summa]
  FROM [TestDatabas].[dbo].[test_table_pivot]