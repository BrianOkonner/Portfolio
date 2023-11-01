@echo off

if exist examdll.obj del examdll.obj
if exist examdll.dll del examdll.dll

c:\masm32\bin\ml /c /coff examdll.asm

c:\masm32\bin\Link /SUBSYSTEM:WINDOWS /DLL /DEF:examdll.def examdll.obj

dir examdll.*

pause