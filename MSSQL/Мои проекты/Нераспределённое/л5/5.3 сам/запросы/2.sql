/****** Скрипт для команды SelectTopNRows из среды SSMS  ******/
SELECT TOP (1000) [id]
      ,[manager]
      ,[otdel]
      ,[god]
      ,[summa]
  FROM [TestDatabas].[dbo].[test_table]