@echo off
REM workaround for stupid visual studio shit
pushd %~dp0
IF not defined VSVARS_SET (
	IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\" (
		call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 
	)
	IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\" (
		call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvarsall.bat" x86 
	)
) 
SET VSVARS_SET="yeah buddy"
popd