# FRPG2Lib
Library for modding Dark Souls II Scholar of the First Sin. Target version is 1.03

## Requirements
DirectXTK (use NuGet if the package is missing)

## Usage
Include FRPG2lib.h and add FRPG2Lib.lib as an Input to your project

Use the defines in FRPG2Globals.h to reference singletons. An example would be `KATANA_MAIN_APP->GetAppGUISystem()`, or `KATANA_MAIN_APP->m_fpsMode`
